#!/usr/bin/env python
# ex:ts=4
#-*- mode: Fundamental; tab-width: 4; -*-
#
# patchtool.py - a tool to automate common operation with patchfiles in the
# FreeBSD Ports Collection.
#
# ----------------------------------------------------------------------------
# "THE BEER-WARE LICENSE" (Revision 42, (c) Poul-Henning Kamp):
# Maxim Sobolev <sobomax@FreeBSD.org> wrote this file.  As long as you retain
# this notice you can do whatever you want with this stuff. If we meet some
# day, and you think this stuff is worth it, you can buy me a beer in return.
#
# Maxim Sobolev
# ----------------------------------------------------------------------------
#
# $FreeBSD$
#
# MAINTAINER= ports@FreeBSD.org <- any unapproved commits to this file are
#				     highly discouraged!!!
#

import os, os.path, subprocess, sys, getopt, glob, errno, types

# python3 lacks raw_input
compat_raw_input = input
if sys.version_info < (3,):
    compat_raw_input = raw_input

# Some global variables used as constants
#True = 1
#False = 0

def isStr(obj):
    try:
        return isinstance(obj, basestring)
    except NameError:
        return isinstance(obj, str)

# Tweakable global variables. User is able to override any of these by setting
# appropriate environment variable prefixed by `PT_', eg:
# $ export PT_CVS_ID="FooOS"
# $ export PT_DIFF_CMD="/usr/local/bin/mydiff"
# will force script to use "FooOS" as a CVS_ID instead of "FreeBSD" and
# "/usr/local/bin/mydiff" as a command to generate diffs.
class Vars:
	CVS_ID = 'FreeBSD'

	DIFF_ARGS = '-du'
	DIFF_SUFX = '.orig'
	PATCH_PREFIX = 'patch-'
	PATCH_IGN_SUFX = ('.orig', '.rej')
	RCSDIFF_SUFX = ',v'

	CD_CMD = 'cd'
	DIFF_CMD = '/usr/bin/diff'
	MAKE_CMD = '/usr/bin/make'
	PRINTF_CMD = '/usr/bin/printf'
	RCSDIFF_CMD = '/usr/bin/rcsdiff'

	DEFAULT_MAKEFILE = 'Makefile'
	DEV_NULL = '/dev/null'
	ETC_MAKE_CONF = '/etc/make.conf'
	
	SLASH_REPL_SYMBOL = '_'	# The symbol to replace '/' when auto-generating
							# patchnames


#
# Check if the supplied patch refers to a port's directory.
#
def isportdir(path, soft = False):
	REQ_FILES = ('Makefile', 'pkg-descr', 'distinfo')
	if not os.path.isdir(path) and soft != True:
		raise IOError(errno.ENOENT, path)
		# Not reached #

	try:
		content = os.listdir(path)
	except OSError:
		return False

	for file in REQ_FILES:
		if file not in content:
			return False
	return True


#
# Traverse directory tree up from the path pointed by argument and return if
# root directory of a port is found.
#
def locateportdir(path, wrkdirprefix= '', strict = False):
	# Flag to relax error checking in isportdir() function. It required when
	# WRKDIRPREFIX is defined.
	softisport = False

	path = os.path.abspath(path)

	if wrkdirprefix != '':
		wrkdirprefix= os.path.abspath(wrkdirprefix)
		commonprefix = os.path.commonprefix((path, wrkdirprefix))
		if commonprefix != wrkdirprefix:
			return ''
		path = path[len(wrkdirprefix):]
		softisport = True

	while path != '/':
		if isportdir(path, softisport) == True:
			return path
		path = os.path.abspath(os.path.join(path, '..'))

	if strict == True:
		raise LocatePDirError(path)
		# Not reached #
	else:
		return ''


#
# Get value of a make(1) variable called varname. Optionally maintain a cache
# for resolved varname:makepath pairs to speed-up operation if the same variable
# from the exactly same file is requested repeatedly (invocation of make(1) is
# very expensive operation...)
#
def querymakevar(varname, path = 'Makefile', strict = False, cache = {}):
	path = os.path.abspath(path)

	if (varname, path) in cache:
		return cache[(varname, path)]

	origpath = path
	if os.path.isdir(path):
		path = os.path.join(path, Vars.DEFAULT_MAKEFILE)
	if not os.path.isfile(path):
		raise IOError(errno.ENOENT, path)
		# Not reached #

	dir = os.path.dirname(path)
	CMDLINE = '%s %s && %s -f %s -V %s' % (Vars.CD_CMD, dir, Vars.MAKE_CMD, \
      path, varname)
	devnull = open('/dev/null', 'a')
	pipe = subprocess.Popen(CMDLINE, shell = True, stdin = subprocess.PIPE, \
            stdout = subprocess.PIPE, stderr = devnull, close_fds = True)
	retval = ''
	for line in pipe.stdout.readlines():
		retval = retval + line.decode().strip() + ' '
	retval = retval[:-1]
	if strict == True and retval.strip() == '':
		raise MakeVarError(path, varname)
		# Not reached #

	cache[(varname, origpath)] = retval
	return retval


#
# Get a path of `path'  relatively to wrksrc. For example:
# path:		/foo/bar
# wrksrc:	/foo/bar/baz/somefile.c
# getrelpath:	baz/somefile.c
# Most of the code here is to handle cases when ../ operation is required to
# reach wrksrc from path, for example:
# path:		/foo/bar
# wrksrc:	/foo/baz/somefile.c
# getrelpath:	../baz/somefile.c
#
def getrelpath(path, wrksrc):
	path = os.path.abspath(path)
	wrksrc = os.path.abspath(wrksrc) + '/'
	commonpart = os.path.commonprefix((path, wrksrc))
	while commonpart[-1:] != '/':
		commonpart = commonpart[:-1]
	path = path[len(commonpart):]
	wrksrc = wrksrc[len(commonpart):]
	adjust = ''
	while os.path.normpath(os.path.join(wrksrc, adjust)) != '.':
		adjust = os.path.join(adjust, '..')
	relpath = os.path.join(adjust, path)
	return relpath


#
# Generate a diff between saved and current versions of the file pointed by the
# wrksrc+path. Apply heuristics to locate saved version of the file in question
# and if it fails assume that file is new, so /dev/null is to be used as
# original file. Optionally save generated patch into `outfile' instead of
# dumping it to stdout. Generated patches automatically being tagged with
# "FreeBSD" cvs id.
#
def gendiff(path, wrksrc, outfile = ''):
	fullpath = os.path.join(wrksrc, path)
	if not os.path.isfile(fullpath):
		raise IOError(errno.ENOENT, fullpath)
		# Not reached #

	cmdline = ''
	if os.path.isfile(fullpath + Vars.DIFF_SUFX):		# Normal diff
		path_orig = path + Vars.DIFF_SUFX
		cmdline = '%s %s %s %s' % (Vars.DIFF_CMD, Vars.DIFF_ARGS, path_orig, path)
	elif os.path.isfile(fullpath + Vars.RCSDIFF_SUFX):	# RCS diff
		path_orig = path
		cmdline = '%s %s %s' % (Vars.RCSDIFF_CMD, Vars.DIFF_ARGS, path)
	else:							# New file
		path_orig = Vars.DEV_NULL
		cmdline = '%s %s %s %s' % (Vars.DIFF_CMD, Vars.DIFF_ARGS, path_orig, path)

	savedir = os.getcwd()
	os.chdir(wrksrc)
	devnull = open('/dev/null', 'a')
	pipe = subprocess.Popen(cmdline, shell = True, stdin = subprocess.PIPE, \
            stdout = subprocess.PIPE, stderr = devnull, close_fds = True)
	outbuf = [x.decode() for x in pipe.stdout.readlines()]
	exitval = pipe.wait()
	if exitval == 0:    # No differences were found
		retval = False
		retmsg = 'no differences found between original and current ' \
			  'version of "%s"' % fullpath
	elif exitval == 1:  # Some differences  were  found
		if (outfile != ''):
			outbuf[0] = '--- %s\n' % path_orig
			outbuf[1] = '+++ %s\n' % path
			open(outfile, 'w').writelines(outbuf)
		else:
			sys.stdout.writelines(outbuf)
		retval = True
		retmsg = ''
	else:               # Error occurred
		raise ECmdError('"%s"' % cmdline, \
		  'external command returned non-zero error code')
		# Not reached #

	os.chdir(savedir)
	return (retval, retmsg)


#
# Automatically generate a name for a patch based on its path relative to
# wrksrc. Use simple scheme to ensure 1-to-1 mapping between path and
# patchname - replace all '_' with '__' and all '/' with '_'.
#
def makepatchname(path, patchdir = ''):
	SRS = Vars.SLASH_REPL_SYMBOL
	retval = Vars.PATCH_PREFIX + \
	  path.replace(SRS, SRS + SRS).replace('/', SRS)
	retval = os.path.join(patchdir, retval)
	return retval


#
# Write a specified message to stderr.
#
def write_msg(message):
	if isStr(message):
		message = message,
	sys.stderr.writelines(message)


#
# Print specified message to stdout and ask user [y/N]?. Optionally allow
# specify default answer, i.e. return value if user typed only <cr>
#
def query_yn(message, default = False):
	while True:
		if default == True:
			yn = 'Y/n'
		elif default == False:
			yn = 'y/N'
		else:
			yn = 'Y/N'

		reply = compat_raw_input('%s [%s]: ' % (message, yn))

		if reply == 'y' or reply == 'Y':
			return True
		elif reply == 'n' or reply == 'N':
			return False
		elif reply == '' and default in (True, False):
			return default
		print('Wrong answer "%s", please try again' % reply)
	return default


#
# Print optional message and usage information and exit with specified exit
# code.
#
def usage(code, msg = ''):
	myname = os.path.basename(sys.argv[0])
	write_msg((str(msg), """
Usage: %s [-afi] file ...
       %s -u [-i] [patchfile|patchdir ...]
""" % (myname, myname)))
	sys.exit(code)


#
# Simple custom exception
#
class MyError(Exception):
	msg = 'error'

	def __init__(self, file, msg=''):
		self.file = file
		if msg != '':
			self.msg = msg

	def __str__(self):
			return '%s: %s' % (self.file, self.msg)


#
# Error parsing patchfile
#
class PatchError(MyError):
	msg = 'corrupt patchfile, or not patchfile at all'


#
# Error executing external command
#
class ECmdError(MyError):
	pass


#
# Error getting value of makefile variable
#
class MakeVarError(MyError):
	def __init__(self, file, makevar, msg=''):
		self.file = file
		if msg != '':
			self.msg = msg
		else:
			self.msg = 'can\'t get %s value' % makevar


#
# Error locating portdir
#
class LocatePDirError(MyError):
	msg = 'can\'t locate portdir'


class Patch:
	fullpath = ''
	minus3file = ''
	plus3file = ''
	wrksrc = ''
	patchmtime = 0
	targetmtime = 0

	def __init__(self, path, wrksrc):
		MINUS3_DELIM = '--- '
		PLUS3_DELIM = '+++ '

		path = os.path.abspath(path)
		if not os.path.isfile(path):
			raise IOError(errno.ENOENT, path)
			# Not reached #

		self.fullpath = path
		filedes = open(path)

		for line in filedes.readlines():
			if self.minus3file == '':
				if line[:len(MINUS3_DELIM)] == MINUS3_DELIM:
					lineparts = line.split()
					try:
						self.minus3file = lineparts[1]
					except IndexError:
						raise PatchError(path)
						# Not reached #
					continue
			elif line[:len(PLUS3_DELIM)] == PLUS3_DELIM:
				lineparts = line.split()
				try:
					self.plus3file = lineparts[1]
				except IndexError:
					raise PatchError(path)
					# Not reached #
				break

		filedes.close()

		if self.minus3file == '' or self.plus3file == '':
			raise PatchError(path)
			# Not reached #

		self.wrksrc = os.path.abspath(wrksrc)
		self.patchmtime = os.path.getmtime(self.fullpath)
		plus3file = os.path.join(self.wrksrc, self.plus3file)
		if os.path.isfile(plus3file):
			self.targetmtime = os.path.getmtime(plus3file)
		else:
			self.targetmtime = 0

	def update(self, patch_cookiemtime = 0, ignoremtime = False):
		targetfile = os.path.join(self.wrksrc, self.plus3file)
		if not os.path.isfile(targetfile):
			raise IOError(errno.ENOENT, targetfile)
			# Not reached #

		patchdir = os.path.dirname(self.fullpath)
		if not os.path.isdir(patchdir):
			os.mkdir(patchdir)

		if ignoremtime == True or self.patchmtime == 0 or \
		  self.targetmtime == 0 or \
		  (self.patchmtime < self.targetmtime and \
		  patch_cookiemtime < self.targetmtime):
			retval = gendiff(self.plus3file, self.wrksrc, self.fullpath)
			if retval[0] == True:
				self.patchmtime = os.path.getmtime(self.fullpath)
		else:
			retval = (False, 'patch is already up to date')
		return retval


class NewPatch(Patch):
	def __init__(self, patchdir, wrksrc, relpath):
		self.fullpath = makepatchname(relpath, os.path.abspath(patchdir))
		self.wrksrc = os.path.abspath(wrksrc)
		self.plus3file = relpath
		self.minus3file = relpath
		self.patchmtime = 0
		plus3file = os.path.join(self.wrksrc, self.plus3file)
		if os.path.isfile(plus3file):
			self.targetmtime = os.path.getmtime(plus3file)
		else:
			self.targetmtime = 0


class PatchesCollection:
	patches = {}

	def __init__(self):
		self.patches = {}
		pass

	def adddir(self, patchdir, wrksrc):
		if not os.path.isdir(patchdir):
			raise IOError(errno.ENOENT, patchdir)
			# Not reached #

		for filename in glob.glob(os.path.join(patchdir, Vars.PATCH_PREFIX + '*')):
			for sufx in Vars.PATCH_IGN_SUFX:
				if filename[-len(sufx):] == sufx:
					write_msg('WARNING: patchfile "%s" ignored\n' % filename)
					break
			else:
				self.addpatchfile(filename, wrksrc)

	def addpatchfile(self, path, wrksrc):
		path = os.path.abspath(path)
		if path not in self.patches:
			self.addpatchobj(Patch(path, wrksrc))

	def addpatchobj(self, patchobj):
		self.patches[patchobj.fullpath] = patchobj

	def lookupbyname(self, path):
		path = os.path.abspath(path)
		if path in self.patches:
			return self.patches[path]
		return None

	def lookupbytarget(self, wrksrc, relpath):
		wrksrc = os.path.abspath(wrksrc)
		for patch in self.patches.values():
			if wrksrc == patch.wrksrc and relpath == patch.plus3file:
				return patch
		return None

	def getpatchobjs(self):
		return self.patches.values()


#
# Resolve all symbolic links in the given path to a file
#
def truepath(path):
	if not os.path.isfile(path):
		raise IOError(errno.ENOENT, path)

	result = ''
	while len(path) > 0:
		path, lastcomp = os.path.split(path)
		if len(lastcomp) == 0:
			lastcomp = path
			path = ''
		result = os.path.join(lastcomp, result)
		if len(path) == 0:
			break
		if os.path.islink(path):
			linkto = os.path.normpath(os.readlink(path))
			if linkto[0] != '/':
				path = os.path.join(path, linkto)
			else:
				path = linkto
	return result[:-1]


def main():
	try:
		opts, args = getopt.getopt(sys.argv[1:], 'afui')
	except getopt.GetoptError as msg:
		usage(2, msg)

	automatic = False
	force = False
	mode = generate
	ignoremtime = False

	for o, a in opts:
		if o == '-a':
			automatic = True
		elif o == '-f':
			force = True
		elif o == '-u':
			mode = update
		elif o == '-i':
			ignoremtime = True
		else:
			usage(2)

	# Allow user to override internal constants
	for varname in dir(Vars):
		if varname[:2] == '__' and varname[-2:] == '__':
			continue
		try:
			value = os.environ['PT_' + varname]
			setattr(Vars, varname, value)
		except KeyError:
			pass

	mode(args, automatic, force, ignoremtime)

	sys.exit(0)


#
# Display a diff or generate patchfile for the files pointed out by args.
#
def generate(args, automatic, force, ignoremtime):
	if len(args) == 0:
		usage(2, "ERROR: no input files specified")

	patches = PatchesCollection()

	for filepath in args:
		for suf in Vars.RCSDIFF_SUFX, Vars.DIFF_SUFX:
			if filepath.endswith(suf):
				filepath = filepath[:-len(suf)]
				break
		if not os.path.isfile(filepath):
			raise IOError(errno.ENOENT, filepath)
			# Not reached #

		filepath = truepath(filepath)

		wrkdirprefix = querymakevar('WRKDIRPREFIX', Vars.ETC_MAKE_CONF, False)
		portdir = locateportdir(os.path.dirname(filepath), wrkdirprefix, True)
		wrksrc = querymakevar('WRKSRC', portdir, True)

		relpath = getrelpath(filepath, wrksrc)

		if automatic:
			patchdir = querymakevar('PATCHDIR', portdir, True)

			if os.path.isdir(patchdir):
				patches.adddir(patchdir, wrksrc)

			extra_patches = querymakevar('EXTRA_PATCHES', portdir, False)
			for extra_patch in extra_patches.split():
				if os.path.isfile(extra_patch):
					patches.addpatchfile(extra_patch, wrksrc)

			patchobj = patches.lookupbytarget(wrksrc, relpath)
			if patchobj == None:
				patchobj = NewPatch(patchdir, wrksrc, relpath)
				patches.addpatchobj(patchobj)

			if not force and os.path.exists(patchobj.fullpath) and \
			  os.path.getsize(patchobj.fullpath) > 0:
				try:
					retval = query_yn('Target patchfile "%s" already ' \
					  'exists, do you want to  replace it?' % \
					  os.path.basename(patchobj.fullpath))
				except KeyboardInterrupt:
					sys.exit('\nAction aborted')
					# Not reached #
				if retval == False:
					continue

			write_msg('Generating patchfile: %s...' % \
			  os.path.basename(patchobj.fullpath))

			try:
				retval = None
				retval = patchobj.update(ignoremtime = ignoremtime)
			finally:
				# Following tricky magic intended to let us append \n even if
				# we are going to die due to unhandled exception
				if retval == None:
					write_msg('OUCH!\n')

			if retval[0] == False:
				write_msg('skipped (%s)\n' % retval[1])
			else:
				write_msg('ok\n')

		else:	# automatic != True
			retval = gendiff(relpath, wrksrc)
			if retval[0] == False:
				write_msg('WARNING: %s\n' % retval[1])


#
# Atomatically update all patches pointed by args (may be individual
# patchfiles, patchdirs or any directories in a portdirs). If directory argument
# is encountered, all patches that belong to the port are updated. If no
# arguments are supplied - current directory is assumed.
#
# The procedure honours last modification times of the patchfile, file from
# which diff to be generated and `EXTRACT_COOKIE' file (usually
# ${WRKDIR}/.extract_cookie) to update only those patches that are really need
# to be updated.
#
def update(args, automatic, force, ignoremtime):
	if len(args) == 0:
		args = './',

	for path in args:
		if not os.path.exists(path):
			raise IOError(errno.ENOENT, path)
			# Not reached #

		patches = PatchesCollection()

		if os.path.isdir(path):
			for wrkdirprefix in (querymakevar('WRKDIRPREFIX', \
              Vars.ETC_MAKE_CONF, False), ''):
				portdir = locateportdir(path, wrkdirprefix, False)
				if portdir != '':
					break
			if portdir == '':
				raise LocatePDirError(os.path.abspath(path))
				# Not reached #

			wrksrc = querymakevar('WRKSRC', portdir, True)
			patchdir = querymakevar('PATCHDIR', portdir, True)

			if os.path.isdir(patchdir):
				patches.adddir(patchdir, wrksrc)
			else:
				continue

		elif os.path.isfile(path):
			portdir = locateportdir(os.path.dirname(path), '' , True)
			wrksrc = querymakevar('WRKSRC', portdir, True)
			patches.addpatchfile(path, wrksrc)

		patch_cookie = querymakevar('PATCH_COOKIE', portdir, True)
		if os.path.isfile(patch_cookie):
			patch_cookiemtime = os.path.getmtime(patch_cookie)
		else:
			patch_cookiemtime = 0

		for patchobj in patches.getpatchobjs():
			write_msg('Updating patchfile: %s...' % \
			  os.path.basename(patchobj.fullpath))

			try:
				retval = None
				retval = patchobj.update(patch_cookiemtime, \
				  ignoremtime)
			finally:
				if retval == None:
					write_msg('OUCH!\n')

			if retval[0] == False:
				write_msg('skipped (%s)\n' % retval[1])
			else:
				write_msg('ok\n')


if __name__ == '__main__':
	try:
		main()
	except (PatchError, ECmdError, MakeVarError, LocatePDirError) as msg:
		sys.exit('ERROR: ' + str(msg))
	except IOError as ex:
		code, msg = ex
		sys.exit('ERROR: %s: %s' % (str(msg), os.strerror(code)))

