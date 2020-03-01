from setuptools import setup, find_packages

setup(
    name='flit_core',
    version='2.2.0',
    author='Thomas Kluyver & contributors',
    author_email='thomas@kluyver.me.uk',
    description="Flit's core machinery for building packages.",
    long_description='Distribution-building parts of Flit. See flit package for more information',
    url='https://github.com/takluyver/flit',
    packages=find_packages(),
    install_requires=['pytoml'],
    requires_python='>=2.7, !=3.0, !=3.1, !=3.2, != 3.3',
    classifiers=[
        "License :: OSI Approved :: BSD License",
        "Topic :: Software Development :: Libraries :: Python Modules",
    ]
)
