#!/usr/local/bin/python
#
# checkcats.py - verify that master categories in all ports are correct and
# report any problems.
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

import glob, os.path
import patchtool
from patchtool import True, False

PORTSDIR = '/usr/ports'

if __name__ == '__main__':
    portdirs = glob.glob(os.path.join(PORTSDIR, '*/*'))
    for dirname in portdirs:
	if not os.path.isfile(os.path.join(dirname, 'Makefile')):
	    continue
	categories = patchtool.querymakevar('CATEGORIES', dirname)
	try:
	    mastercat = categories.split()[0]
	except IndexError:
	    print '%s: categories list is empty' % dirname
	    continue
	mastercat_real = os.path.basename(os.path.dirname(dirname))
	if mastercat != mastercat_real:
	    print '%s: specified master category `%s\' doesn\'t match real one `%s\'' \
	      % (dirname, mastercat, mastercat_real)

