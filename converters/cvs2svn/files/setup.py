__version__ = '$FreeBSD$'
from distutils.core import setup
setup(	name = 'cvs2svn',
	version = '0.0.938',
	packages = ['rcsparse'],
	scripts = ['cvs2svn', 'profile-cvs2svn',
		   'verify-cvs2svn', 'dump-db', 'show-db'],
)
