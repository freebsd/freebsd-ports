# $FreeBSD$
import os
from distutils.core import setup, Extension

LOCALBASE = os.environ['LOCALBASE']
PREFIX = os.environ['PREFIX']

setup ( name = 'newt',
	version = '0.50.33',
	description = 'Python interface to Newt module',
	py_modules = ['snack'],
	ext_modules = [ Extension(
       		name='_snack',
		sources=['snackmodule.c'],
		include_dirs=['.', LOCALBASE+'/include', PREFIX+'/include'],
		library_dirs=['.', LOCALBASE+'/lib', PREFIX+'/lib'],
		libraries=['newt', 'popt', 'slang', 'ncurses']
	)])
