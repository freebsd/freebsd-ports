__version__ = "$FreeBSD$"
from distutils.core import setup
setup(	name = "gdick",
	py_modules = ["YahooDict", "YahooView"],
	scripts = ["gdick", "gdick_applet"],
	data_files = [("share/gdick", ("gdick.glade",))],
)
