#!/usr/local/bin/python
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
# MAINTAINER= sobomax@FreeBSD.org <- any unapproved commits to this file are
#                                    highly discouraged!!!
#

import os, os.path, popen2, types, sys, getopt, pickle

# Global constants and semi-constants
PKG_DBDIR = '/var/db/pkg'
PORTSDIR = '/usr/ports'
ROOT_PORTMK = '/usr/share/mk/bsd.port.mk'
PLIST_FILE = '+CONTENTS'
ORIGIN_PREF = '@comment ORIGIN:'
MAKEFILE = 'Makefile'
MAKE = 'make'
ERR_PREF = 'Error:'
WARN_PREF = 'Warning:'

# Global variables
#
# PortInfo cache
picache = {}

# Useful aliases
op_isdir = os.path.isdir
op_join = os.path.join
op_split = os.path.split
op_abspath = os.path.abspath


#
# Query origin of specified installed package.
#
def getorigin(pkg):
    plist = op_join(PKG_DBDIR, pkg, PLIST_FILE)
    for line in open(plist).xreadlines():
	if line.startswith(ORIGIN_PREF):
	    origin = line[len(ORIGIN_PREF):].strip()
	    break
    else:
	raise RuntimeError('%s: no origin recorded' % plist)

    return origin


#
# Execute external command and return content of its stdout.
#
def getcmdout(cmdline, filterempty = 1):
    pipe = popen2.Popen3(cmdline, 1)
    results = pipe.fromchild.readlines()
    for stream in (pipe.fromchild, pipe.tochild, pipe.childerr):
        stream.close()

    if pipe.wait() != 0:
        if type(cmdline) is types.StringType:
            cmdline = (cmdline)
        raise IOError('%s: external command returned non-zero error code' % \
          cmdline[0])

    if filterempty != 0:
	results = filter(lambda line: len(line.strip()) > 0, results)

    return results


#
# For a specified path (either dir or makefile) query requested make(1)
# variables and return them as a tuple in exactly the same order as they
# were specified in function call, i.e. querymakevars('foo', 'A', 'B') will
# return a tuple with a first element being the value of A variable, and
# the second one - the value of B.
#
def querymakevars(path, *vars):
    if op_isdir(path):
	path = op_join(path, MAKEFILE)
    dirname, makefile = op_split(path)
    cmdline = [MAKE, '-f', makefile]
    savedir = os.getcwd()
    os.chdir(dirname)
    try:
        for var in vars:
	    cmdline.extend(('-V', var))

        results = map(lambda line: line.strip(), getcmdout(cmdline, 0))
    finally:
        os.chdir(savedir)

    return tuple(results)


def parsedeps(depstr):
    return tuple(map(lambda dep: dep.split(':'), depstr.split()))


#
# For a specified port return either a new instance of the PortInfo class,
# or existing instance from the cache.
#
def getpi(path):
    path = op_abspath(path)
    if not picache.has_key(path):
        picache[path] = PortInfo(path)
    return picache[path]


#
# Format text string according to requested constrains. Useful when you have
# to display multi-line, variable width message on terminal.
#
def formatmsg(msg, wrapat = 78, seclindent = 0):
    words = msg.split()
    result = ''
    position = 0
    for word in words:
        if position + 1 + len(word) > wrapat:
            result += '\n' + ' ' * seclindent + word
            position = seclindent + len(word)
        else:
            if position != 0:
                result += ' '
                position += 1
            result += word
            position += len(word)

    return result


#
# Class that contain main info about the port
#
class PortInfo:
    PKGNAME = None
    CATEGORIES = None
    MAINTAINER = None
    BUILD_DEPENDS = None
    LIB_DEPENDS = None
    RUN_DEPENDS = None
    PKGORIGIN = None
    # Cached values, to speed-up things
    __deps = None
    __bt_deps = None
    __rt_deps = None

    def __init__(self, path):
        self.PKGNAME, self.CATEGORIES, self.MAINTAINER, self.BUILD_DEPENDS, \
          self.LIB_DEPENDS, self.RUN_DEPENDS, self.PKGORIGIN = \
          querymakevars(path, 'PKGNAME', 'CATEGORIES', 'MAINTAINER', \
          'BUILD_DEPENDS', 'LIB_DEPENDS', 'RUN_DEPENDS', 'PKGORIGIN')

    def __str__(self):
        return 'PKGNAME:\t%s\nCATEGORIES:\t%s\nMAINTAINER:\t%s\n' \
          'BUILD_DEPENDS:\t%s\nLIB_DEPENDS:\t%s\nRUN_DEPENDS:\t%s\n' \
          'PKGORIGIN:\t%s' % (self.PKGNAME, self.CATEGORIES, self.MAINTAINER, \
          self.BUILD_DEPENDS, self.LIB_DEPENDS, self.RUN_DEPENDS, \
          self.PKGORIGIN)

    def getdeps(self):
        if self.__deps == None:
            result = []
            for depstr in self.BUILD_DEPENDS, self.LIB_DEPENDS, \
              self.RUN_DEPENDS:
                deps = tuple(map(lambda dep: dep[1], parsedeps(depstr)))
                result.append(deps)
            self.__deps = tuple(result)
        return self.__deps

    def get_bt_deps(self):
        if self.__bt_deps == None:
            topdeps = self.getdeps()
            topdeps = list(topdeps[0] + topdeps[1])
            for dep in topdeps[:]:
                botdeps = filter(lambda dep: dep not in topdeps, \
                  getpi(dep).get_rt_deps())
                topdeps.extend(botdeps)
            self.__bt_deps = tuple(topdeps)
        return self.__bt_deps
        
    def get_rt_deps(self):
        if self.__rt_deps == None:
            topdeps = self.getdeps()
            topdeps = list(topdeps[1] + topdeps[2])
            for dep in topdeps[:]:
                botdeps = filter(lambda dep: dep not in topdeps, \
                  getpi(dep).get_rt_deps())
                topdeps.extend(botdeps)
            self.__rt_deps = tuple(topdeps)
        return self.__rt_deps


def write_msg(*message):
    if type(message) == types.StringType:
        message = message,
    message = tuple(filter(lambda line: line != None, message))
    sys.stderr.writelines(message)


#
# Print optional message and usage information and exit with specified exit
# code.
#
def usage(code, msg = None):
    myname = os.path.basename(sys.argv[0])
    if msg != None:
        msg = str(msg) + '\n'
    write_msg(msg, "Usage: %s [-rb] [-l|L cachefile] [-s cachefile]\n" % \
      myname)
    sys.exit(code)


def main():
    global picache

    # Parse command line arguments
    try:
        opts, args = getopt.getopt(sys.argv[1:], 'erbl:L:s:')
    except getopt.GetoptError, msg:
        usage(2, msg)

    if len(args) > 0 or len(opts) == 0 :
        usage(2)

    cachefile = None
    chk_bt_deps = 0
    chk_rt_deps = 0
    warn_as_err = 0
    for o, a in opts:
        if o == '-b':
            chk_bt_deps = 1
        elif o == '-r':
            chk_rt_deps = 1
        elif o in ('-l', '-L'):
            # Try to load saved PortInfo cache
            try:
                picache = pickle.load(open(a))
            except:
                picache = {}
            try:
                if o == '-L':
                    os.unlink(a)
            except:
                pass
        elif o == '-s':
            cachefile = a
        elif o == '-e':
            warn_as_err = 1

    # Load origins of all installed packages
    instpkgs = os.listdir(PKG_DBDIR)
    instpkgs = filter(lambda pkg: op_isdir(op_join(PKG_DBDIR, pkg)), instpkgs)
    origins = {}
    for pkg in instpkgs:
        origins[pkg] = getorigin(pkg)

    # Resolve dependencies for the current port
    info = getpi(os.getcwd())
    deps = []
    if chk_bt_deps != 0:
        deps.extend(filter(lambda d: d not in deps, info.get_bt_deps()))
    if chk_rt_deps != 0:
        deps.extend(filter(lambda d: d not in deps, info.get_rt_deps()))

    # Perform validation
    nerrs = 0
    nwarns = 0
    if warn_as_err == 0:
        warn_pref = WARN_PREF
    else:
        warn_pref = ERR_PREF
    err_pref = ERR_PREF
    for dep in deps:
        pi = getpi(dep)
        if pi.PKGORIGIN not in origins.values():
            print formatmsg(seclindent = 7 * 0, msg = \
              '%s package %s (%s) belongs to dependency chain, but ' \
              'isn\'t installed.' % (err_pref, pi.PKGNAME, pi.PKGORIGIN))
            nerrs += 1
        elif pi.PKGNAME not in origins.keys():
            for instpkg in origins.keys():
                if origins[instpkg] == pi.PKGORIGIN:
                    break
            print formatmsg(seclindent = 9 * 0, msg = \
              '%s package %s (%s) belongs to dependency chain, but ' \
              'package %s is installed instead. Perhaps it\'s an older ' \
              'version - update is highly recommended.' % (warn_pref, \
              pi.PKGNAME, pi.PKGORIGIN, instpkg))
            nwarns += 1

    # Save PortInfo cache if requested
    if cachefile != None:
        try:
            pickle.dump(picache, open(cachefile, 'w'))
        except:
            pass

    if warn_as_err != 0:
        nerrs += nwarns

    return nerrs


PORTSDIR, PKG_DBDIR = querymakevars(ROOT_PORTMK, 'PORTSDIR', 'PKG_DBDIR')

if __name__ == '__main__':
    try:
        sys.exit(main())
    except KeyboardInterrupt:
        pass
