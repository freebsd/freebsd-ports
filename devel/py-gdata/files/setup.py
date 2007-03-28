from distutils.core import setup

setup(
	name = 'gdata',
	version = "%%PORTVERSION%%",
	py_modules = [
		'app_service',
		'atom',
		'gbase',
		'gbase_service',
		'gcalendar',
		'gcalendar_service',
		'gdata',
		'gdata_client',
		'gdata_service',
		'gspreadsheet',
		'gspreadsheet_service',
	],
)
