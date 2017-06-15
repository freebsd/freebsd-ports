
from setuptools import setup, find_packages

setup(
    name='testpath',
    version='0.3',
    description='Test utilities for Python code working with files and commands',
    url='https://github.com/jupyter/testpath',
    author='The Jupyter Development Team',
    license='MIT',
    long_description='Test utilities for Python code working with files and commands',
    packages=find_packages(exclude=['tests'])
)
