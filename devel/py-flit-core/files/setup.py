from setuptools import setup, find_packages
import flit_core

setup(
    name='flit_core',
    version=flit_core.__version__,
    author='Thomas Kluyver & contributors',
    author_email='thomas@kluyver.me.uk',
    description="Flit's core machinery for building packages.",
    long_description='Distribution-building parts of Flit. See flit package for more information',
    url='https://github.com/takluyver/flit',
    packages=find_packages(),
    install_requires=['pytoml'],
    python_requires='>=3.4',
    classifiers=[
        "License :: OSI Approved :: BSD License",
        "Topic :: Software Development :: Libraries :: Python Modules",
    ]
)
