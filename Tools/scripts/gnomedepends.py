#!/usr/local/bin/python
#
# gnomedepends
# Analyse pkg/PLIST and give an advice as to which GNOME
# ports should be listes in {RUN,LIB}_DEPENDS for this port
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
# MAINTAINER= sobomax@FreeBSD.org
#
# TODO:
#  - analyse actual {RUN,LIB}_DEPENDS and give an advice about what should be
#    added;
#  - analyse results and remove redundant dependencies (for example if gnomecore
#    has gnomecontrolcenter listed as dependency, and it is found that the port
#    requires both gnomecontrolcenter and gnomecore do not list
#    gnomecontrolcenter then);
#  - parse ports/INDEX directly.
#

import os, os.path, sys, string, re

def getcmdout(cmdline):
	results = []
	pipe = os.popen(cmdline)
	buffer = pipe.readlines()
	for result in buffer:
		result = string.strip(result)
		if len(result) > 0:
			results.append(result)
	pipe.close()
	return results

def readfile(filename):
	file = open(filename)
	result = file.readlines()
	file.close()
	return result

def filter(lines, regobj):
	results = []
	for line in lines:
		match = regobj.match(line)
		if match != None:
			result = string.strip(match.group(1))
			try:
				tmp = results.index(result)
			except ValueError:
				results.append(result)
	return results

gnomeports = getcmdout('cd /usr/ports && make search key=gnome | grep ^Path:')
newgnomeports = []
for i in gnomeports:
	newgnomeports.append(string.split(i)[1])
gnomeports = newgnomeports
newgnomeports = []

regobj = re.compile('^@dirrm (?P<dirname>\S+).*$')
for portdir in gnomeports:
	try:
		lines = readfile(os.path.join(portdir, 'pkg-plist'))
		lines = filter(lines, regobj)
		if len(lines) > 0:
			newgnomeports.append([portdir, lines])
	except IOError:
		pass
gnomeports = newgnomeports
newgnomeports = []

try:
	currplist = readfile('pkg-plist')
except IOError, errmsg:
	print errmsg
	sys.exit(1)

regobj = re.compile('^(?!@)(?P<dirname>\S+)/.*')
currdirs = filter(currplist, regobj)
regobj = re.compile('^@dirrm (?P<dirname>\S+).*$')
currdirs.extend(filter(currplist, regobj))
currportdir = os.getcwd()

newcurrdirs = []
for dir in currdirs:
	incremental = ''
	for component in string.split(dir, '/'):
		if incremental != '':
			incremental = incremental + '/'
		incremental = incremental + component
		try:
			tmp = newcurrdirs.index(incremental)
		except ValueError:
			newcurrdirs.append(incremental)
currdirs = newcurrdirs

depends = []
for gnomeport in gnomeports:
	if (currportdir == gnomeport[0]):
		continue
	matches = []
	for gnomedir in gnomeport[1]:
		for dir in currdirs:
			if (gnomedir == dir):
				matches.append(dir)
	if len(matches) > 0:
		depends.append([gnomeport[0], matches])

if len(depends) == 0:
	sys.stdout.writelines(['No dependencies found (maybe it is not a GNOME port).\n'])
	sys.exit(0)

sys.stdout.writelines(['According to the contents of pkg-plist the port depends on the following GNOME\n', 'port(s):\n\n'])
for depend in depends:
	sys.stdout.writelines([depend[0], ', for directories:\n'])
	for dir in depend[1]:
		sys.stdout.writelines(['\t', dir, '\n'])
	sys.stdout.writelines(['\n'])


