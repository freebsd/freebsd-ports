# $FreeBSD$
import os
from distutils.core import setup, Extension

setup ( name = 'newt',
	version = '0.50.33',
	description = 'Python interface to Newt module',
	py_modules = ['snack'],
	ext_modules = [ Extension(
       		name='_snack',
		sources=['snackmodule.c'],
		include_dirs=['.', os.environ['PREFIX']+'/include'],
		library_dirs=['.', os.environ['PREFIX']+'/lib'],
		libraries=['newt', 'popt', 'slang', 'ncurses']
	)])
