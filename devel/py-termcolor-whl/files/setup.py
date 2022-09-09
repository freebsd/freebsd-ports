# -*- coding: utf-8 -*-
from setuptools import setup

packages = \
['termcolor']

package_data = \
{'': ['*']}

setup_kwargs = {
    'name': 'termcolor-whl',
    'version': '1.1.2',
    'description': 'ANSI Color formatting for output in terminal, successor to termcolor (has wheels!)',
    'long_description': '# termcolor\nColorize your console output.\n\nThis is the successor to `termcolor`\n \n### Example\n\n     import sys\n     from termcolor import colored, cprint\n\n     text = colored(\'Hello, World!\', \'red\', attrs=[\'reverse\', \'blink\'])\n     print(text)\n     cprint(\'Hello, World!\', \'green\', \'on_red\')\n\n     print_red_on_cyan = lambda x: cprint(x, \'red\', \'on_cyan\')\n     print_red_on_cyan(\'Hello, World!\')\n     print_red_on_cyan(\'Hello, Universe!\')\n\n     for i in range(10):\n         cprint(i, \'magenta\', end=\' \')\n\n     cprint("Attention!", \'red\', attrs=[\'bold\'], file=sys.stderr)\n\n### Disabling\nAny value in the environment variable `ANSI_COLORS_DISABLED` will disable colors.\n\n### Text Properties\nText colors:\n\n> -   grey\n> -   red\n> -   green\n> -   yellow\n> -   blue\n> -   magenta\n> -   cyan\n> -   white\n\nText highlights:\n> -   on\\_grey\n> -   on\\_red\n> -   on\\_green\n> -   on\\_yellow\n> -   on\\_blue\n> -   on\\_magenta\n> -   on\\_cyan\n> -   on\\_white\n\n> Attributes:\n> -   bold\n> -   dark\n> -   underline\n> -   blink\n> -   reverse\n> -   concealed\n\n### Terminal properties\n\n    Terminal       bold      dark   underline   blink        reverse   concealed\n    -------------- --------- ------ ----------- ------------ --------- -----------\n    xterm          yes       no     yes         bold         yes       yes\n    linux          yes       yes    bold        yes          yes       no\n    rxvt           yes       no     yes         bold/black   yes       no\n    dtterm         yes       yes    yes         reverse      yes       yes\n    teraterm       reverse   no     yes         rev/red      yes       no\n    aixterm        normal    no     yes         no           yes       yes\n    PuTTY          color     no     yes         no           yes       no\n    Windows        no        no     no          no           yes       no\n    Cygwin SSH     yes       no     color       color        color     yes\n    Mac Terminal   yes       no     yes         yes          yes       yes\n\n### License and Authorship\nOriginal author: Konstantin Lepa <konstantin.lepa@gmail.com>, Copyright (c) 2008-2011 Volvox Development Team\nOriginal license: MIT.\n\nOriginal source code repository no longer available, this is a fork of the artifacts published to pypi\n\n## Documents\n- [Changes](https://github.com/matthewdeanmartin/termcolor/blob/main/docs/CHANGES.MD)',
    'author': 'Konstantin Lepa',
    'author_email': 'konstantin.lepa@gmail.com',
    'maintainer': None,
    'maintainer_email': None,
    'url': 'https://github.com/matthewdeanmartin/termcolor',
    'packages': packages,
    'package_data': package_data,
    'python_requires': '>=2.6',
}

setup(**setup_kwargs)
