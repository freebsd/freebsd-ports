# -*- coding: utf-8 -*-
from setuptools import setup

setup(
    name='platformdirs',
    version='%%PORTVERSION%%',
    description='A small Python package for determining appropriate platform-specific dirs, e.g. a "user data dir".',
    long_description='The problem\n===========\n\n.. image:: https://github.com/platformdirs/platformdirs/workflows/Test/badge.svg\n   :target: https://github.com/platformdirs/platformdirs/actions?query=workflow%3ATest\n\nWhen writing desktop application, finding the right location to store user data\nand configuration varies per platform. Even for single-platform apps, there\nmay by plenty of nuances in figuring out the right location.\n\nFor example, if running on macOS, you should use::\n\n    ~/Library/Application Support/<AppName>\n\nIf on Windows (at least English Win XP) that should be::\n\n    C:\\Documents and Settings\\<User>\\Application Data\\Local Settings\\<AppAuthor>\\<AppName>\n\nor possibly::\n\n    C:\\Documents and Settings\\<User>\\Application Data\\<AppAuthor>\\<AppName>\n\nfor `roaming profiles <https://docs.microsoft.com/en-us/previous-versions/windows/it-pro/windows-vista/cc766489(v=ws.10)>`_ but that is another story.\n\nOn Linux (and other Unices), according to the `XDG Basedir Spec`_, it should be::\n\n    ~/.local/share/<AppName>\n\n.. _XDG Basedir Spec: https://specifications.freedesktop.org/basedir-spec/basedir-spec-latest.html\n\n``platformdirs`` to the rescue\n==============================\n\nThis kind of thing is what the ``platformdirs`` package is for.\n``platformdirs`` will help you choose an appropriate:\n\n- user data dir (``user_data_dir``)\n- user config dir (``user_config_dir``)\n- user cache dir (``user_cache_dir``)\n- site data dir (``site_data_dir``)\n- site config dir (``site_config_dir``)\n- user log dir (``user_log_dir``)\n- user documents dir (``user_documents_dir``)\n- user runtime dir (``user_runtime_dir``)\n\nAnd also:\n\n- Is slightly opinionated on the directory names used. Look for "OPINION" in\n  documentation and code for when an opinion is being applied.\n\nExample output\n==============\n\nOn macOS:\n\n.. code-block:: pycon\n\n    >>> from platformdirs import *\n    >>> appname = "SuperApp"\n    >>> appauthor = "Acme"\n    >>> user_data_dir(appname, appauthor)\n    \'/Users/trentm/Library/Application Support/SuperApp\'\n    >>> site_data_dir(appname, appauthor)\n    \'/Library/Application Support/SuperApp\'\n    >>> user_cache_dir(appname, appauthor)\n    \'/Users/trentm/Library/Caches/SuperApp\'\n    >>> user_log_dir(appname, appauthor)\n    \'/Users/trentm/Library/Logs/SuperApp\'\n    >>> user_documents_dir()\n    \'/Users/trentm/Documents\'\n    >>> user_runtime_dir(appname, appauthor)\n    \'/Users/trentm/Library/Caches/TemporaryItems/SuperApp\'\n\nOn Windows 7:\n\n.. code-block:: pycon\n\n    >>> from platformdirs import *\n    >>> appname = "SuperApp"\n    >>> appauthor = "Acme"\n    >>> user_data_dir(appname, appauthor)\n    \'C:\\\\Users\\\\trentm\\\\AppData\\\\Local\\\\Acme\\\\SuperApp\'\n    >>> user_data_dir(appname, appauthor, roaming=True)\n    \'C:\\\\Users\\\\trentm\\\\AppData\\\\Roaming\\\\Acme\\\\SuperApp\'\n    >>> user_cache_dir(appname, appauthor)\n    \'C:\\\\Users\\\\trentm\\\\AppData\\\\Local\\\\Acme\\\\SuperApp\\\\Cache\'\n    >>> user_log_dir(appname, appauthor)\n    \'C:\\\\Users\\\\trentm\\\\AppData\\\\Local\\\\Acme\\\\SuperApp\\\\Logs\'\n    >>> user_documents_dir()\n    \'C:\\\\Users\\\\trentm\\\\Documents\'\n    >>> user_runtime_dir(appname, appauthor)\n    \'C:\\\\Users\\\\trentm\\\\AppData\\\\Local\\\\Temp\\\\Acme\\\\SuperApp\'\n\nOn Linux:\n\n.. code-block:: pycon\n\n    >>> from platformdirs import *\n    >>> appname = "SuperApp"\n    >>> appauthor = "Acme"\n    >>> user_data_dir(appname, appauthor)\n    \'/home/trentm/.local/share/SuperApp\'\n    >>> site_data_dir(appname, appauthor)\n    \'/usr/local/share/SuperApp\'\n    >>> site_data_dir(appname, appauthor, multipath=True)\n    \'/usr/local/share/SuperApp:/usr/share/SuperApp\'\n    >>> user_cache_dir(appname, appauthor)\n    \'/home/trentm/.cache/SuperApp\'\n    >>> user_log_dir(appname, appauthor)\n    \'/home/trentm/.cache/SuperApp/log\'\n    >>> user_config_dir(appname)\n    \'/home/trentm/.config/SuperApp\'\n    >>> user_documents_dir()\n    \'/home/trentm/Documents\'\n    >>> user_runtime_dir(appname, appauthor)\n    \'/run/user/{os.getuid()}/SuperApp\'\n    >>> site_config_dir(appname)\n    \'/etc/xdg/SuperApp\'\n    >>> os.environ["XDG_CONFIG_DIRS"] = "/etc:/usr/local/etc"\n    >>> site_config_dir(appname, multipath=True)\n    \'/etc/SuperApp:/usr/local/etc/SuperApp\'\n\nOn Android::\n\n    >>> from platformdirs import *\n    >>> appname = "SuperApp"\n    >>> appauthor = "Acme"\n    >>> user_data_dir(appname, appauthor)\n    \'/data/data/com.myApp/files/SuperApp\'\n    >>> user_cache_dir(appname, appauthor)\n    \'/data/data/com.myApp/cache/SuperApp\'\n    >>> user_log_dir(appname, appauthor)\n    \'/data/data/com.myApp/cache/SuperApp/log\'\n    >>> user_config_dir(appname)\n    \'/data/data/com.myApp/shared_prefs/SuperApp\'\n    >>> user_documents_dir()\n    \'/storage/emulated/0/Documents\'\n    >>> user_runtime_dir(appname, appauthor)\n    \'/data/data/com.myApp/cache/SuperApp/tmp\'\n\nNote: Some android apps like Termux and Pydroid are used as shells. These\napps are used by the end user to emulate Linux environment. Presence of\n``SHELL`` environment variable is used by Platformdirs to differentiate\nbetween general android apps and android apps used as shells. Shell android\napps also support ``XDG_*`` environment variables.\n\n\n``PlatformDirs`` for convenience\n================================\n\n.. code-block:: pycon\n\n    >>> from platformdirs import PlatformDirs\n    >>> dirs = PlatformDirs("SuperApp", "Acme")\n    >>> dirs.user_data_dir\n    \'/Users/trentm/Library/Application Support/SuperApp\'\n    >>> dirs.site_data_dir\n    \'/Library/Application Support/SuperApp\'\n    >>> dirs.user_cache_dir\n    \'/Users/trentm/Library/Caches/SuperApp\'\n    >>> dirs.user_log_dir\n    \'/Users/trentm/Library/Logs/SuperApp\'\n    >>> dirs.user_documents_dir\n    \'/Users/trentm/Documents\'\n    >>> dirs.user_runtime_dir\n    \'/Users/trentm/Library/Caches/TemporaryItems/SuperApp\'\n\nPer-version isolation\n=====================\n\nIf you have multiple versions of your app in use that you want to be\nable to run side-by-side, then you may want version-isolation for these\ndirs::\n\n    >>> from platformdirs import PlatformDirs\n    >>> dirs = PlatformDirs("SuperApp", "Acme", version="1.0")\n    >>> dirs.user_data_dir\n    \'/Users/trentm/Library/Application Support/SuperApp/1.0\'\n    >>> dirs.site_data_dir\n    \'/Library/Application Support/SuperApp/1.0\'\n    >>> dirs.user_cache_dir\n    \'/Users/trentm/Library/Caches/SuperApp/1.0\'\n    >>> dirs.user_log_dir\n    \'/Users/trentm/Library/Logs/SuperApp/1.0\'\n    >>> dirs.user_documents_dir\n    \'/Users/trentm/Documents\'\n    >>> dirs.user_runtime_dir\n    \'/Users/trentm/Library/Caches/TemporaryItems/SuperApp/1.0\'\n\nBe wary of using this for configuration files though; you\'ll need to handle\nmigrating configuration files manually.\n\nWhy this Fork?\n==============\n\nThis repository is a friendly fork of the wonderful work started by\n`ActiveState <https://github.com/ActiveState/appdirs>`_ who created\n``appdirs``, this package\'s ancestor.\n\nMaintaining an open source project is no easy task, particularly\nfrom within an organization, and the Python community is indebted\nto ``appdirs`` (and to Trent Mick and Jeff Rouse in particular) for\ncreating an incredibly useful simple module, as evidenced by the wide\nnumber of users it has attracted over the years.\n\nNonetheless, given the number of long-standing open issues\nand pull requests, and no clear path towards `ensuring\nthat maintenance of the package would continue or grow\n<https://github.com/ActiveState/appdirs/issues/79>`_, this fork was\ncreated.\n\nContributions are most welcome.\n',
    maintainer_email='Bernát Gábor <gaborjbernat@gmail.com>, Julian Berman <Julian@GrayVines.com>, Ofek Lev <oss@ofek.dev>, Ronny Pfannschmidt <opensource@ronnypfannschmidt.de>',
    classifiers=[
        'Development Status :: 5 - Production/Stable',
        'Intended Audience :: Developers',
        'License :: OSI Approved :: MIT License',
        'Operating System :: OS Independent',
        'Programming Language :: Python',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3 :: Only',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8',
        'Programming Language :: Python :: 3.9',
        'Programming Language :: Python :: 3.10',
        'Programming Language :: Python :: 3.11',
        'Programming Language :: Python :: Implementation :: CPython',
        'Programming Language :: Python :: Implementation :: PyPy',
        'Topic :: Software Development :: Libraries :: Python Modules',
    ],
    install_requires=[
        'typing-extensions>=4.4; python_version < "3.8"',
    ],
    extras_require={
        'docs': [
            'furo>=2022.12.7',
            'proselint>=0.13',
            'sphinx-autodoc-typehints>=1.19.5',
            'sphinx>=5.3',
        ],
        'test': [
            'appdirs==1.4.4',
            'covdefaults>=2.2.2',
            'pytest-cov>=4',
            'pytest-mock>=3.10',
            'pytest>=7.2',
        ],
    },
    packages=[
        'platformdirs',
    ],
    package_dir={'': 'src'},
)
