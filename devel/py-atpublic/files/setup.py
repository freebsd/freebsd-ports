"""public -- @public for populating __all__"""

from setup_helpers import get_version, require_python
from setuptools import setup, find_packages

require_python(0x30800f0)
__version__ = get_version('src/public/__init__.py')


with open('README.rst') as fp:
    readme = fp.read()


setup(
    name='atpublic',
    version=__version__,
    author='Barry Warsaw',
    author_email='barry@python.org',
    description=__doc__,
    long_description=readme,
    long_description_content_type='text/x-rst',
    license='Apache 2.0',
    keywords='__all__ public',
    url='http://public.readthedocs.io/',
    package_dir={"":"src"},
    packages=['public'],
    include_package_data=True,
    package_data={
        'public': ['public/py.typed'],
        },
    # readthedocs builds fail unless zip_safe is False.
    zip_safe=False,
    python_requires='>=3.8',
    install_requires=[
        'typing_extensions;python_version<"3.8"',
        ],
    project_urls={
        'Documentation': 'https://public.readthedocs.io',
        'Source': 'https://gitlab.com/warsaw/public.git',
        'Tracker': 'https://gitlab.com/warsaw/public/issues',
        },
    classifiers=[
        'Development Status :: 5 - Production/Stable',
        'Development Status :: 6 - Mature',
        'Intended Audience :: Developers',
        'License :: OSI Approved :: Apache Software License',
        'Operating System :: POSIX',
        'Operating System :: MacOS :: MacOS X',
        'Operating System :: Microsoft :: Windows',
        'Programming Language :: Python',
        'Programming Language :: Python :: 3',
        'Topic :: Software Development :: Libraries',
        'Topic :: Software Development :: Libraries :: Python Modules',
        'Topic :: Utilities',
        ],
    )
