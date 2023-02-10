# -*- coding: utf-8 -*-
from setuptools import setup

setup(
    name='comm',
    version='%%PORTVERSION%%',
    description='Jupyter Python Comm implementation, for usage in ipykernel, xeus-python etc.',
    long_description="# Comm\n\nIt provides a way to register a Kernel Comm implementation, as per the Jupyter kernel protocol.\nIt also provides a base Comm implementation and a default CommManager that can be used.\n\n## Register a comm implementation in the kernel:\n\n### Case 1: Using the default CommManager and the BaseComm implementations\n\nWe provide default implementations for usage in IPython:\n\n```python\nimport comm\n\n\nclass MyCustomComm(comm.base_comm.BaseComm):\n\n    def publish_msg(self, msg_type, data=None, metadata=None, buffers=None, **keys):\n        # TODO implement the logic for sending comm messages through the iopub channel\n        pass\n\n\ncomm.create_comm = MyCustomComm\n```\n\nThis is typically what ipykernel and JupyterLite's pyolite kernel will do.\n\n### Case 2: Providing your own comm manager creation implementation\n\n```python\nimport comm\n\ncomm.create_comm = custom_create_comm\ncomm.get_comm_manager = custom_comm_manager_getter\n```\n\nThis is typically what xeus-python does (it has its own manager implementation using xeus's C++ messaging logic).\n\n## Comm users\n\nLibraries like ipywidgets can then use the comms implementation that has been registered by the kernel:\n\n```python\nfrom comm import create_comm, get_comm_manager\n\n# Create a comm\ncomm_manager = get_comm_manager()\ncomm = create_comm()\n\ncomm_manager.register_comm(comm)\n```\n",
    author='Jupyter contributors',
    classifiers=[
        'Framework :: Jupyter',
        'License :: OSI Approved :: BSD License',
        'Programming Language :: Python',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3.6',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8',
        'Programming Language :: Python :: 3.9',
        'Programming Language :: Python :: 3.10',
    ],
    install_requires=[
        'traitlets>=5.3',
    ],
    extras_require={
        'test': [
            'pytest',
        ],
    },
    packages=[
        'comm',
    ],
)
