from distutils.core import setup, Extension

setup(
    name = 'gdchart',
    version = "%%PORTVERSION%%",
    py_modules = ["chart"],
    ext_modules = [
	Extension("gdchart", ["gdc_py.c"],
		include_dirs=["%%GD_INCLUDE%%", "%%GDCHART_INCLUDE%%"],
		libraries=["gdc", "gd", "png", "z", "jpeg"],
		library_dirs=["%%LOCALLIB%%"]
	)
    ]
)
