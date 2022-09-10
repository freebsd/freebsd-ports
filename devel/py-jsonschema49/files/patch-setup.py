--- setup.py.orig	2022-07-20 21:49:12 UTC
+++ setup.py
@@ -0,0 +1,66 @@
+# -*- coding: utf-8 -*-
+from setuptools import setup
+
+setup(
+    name='jsonschema',
+    version='4.7.2',
+    description='An implementation of JSON Schema validation for Python',
+    long_description='==========\njsonschema\n==========\n\n|PyPI| |Pythons| |CI| |ReadTheDocs| |Precommit| |Zenodo|\n\n.. |PyPI| image:: https://img.shields.io/pypi/v/jsonschema.svg\n   :alt: PyPI version\n   :target: https://pypi.org/project/jsonschema/\n\n.. |Pythons| image:: https://img.shields.io/pypi/pyversions/jsonschema.svg\n   :alt: Supported Python versions\n   :target: https://pypi.org/project/jsonschema/\n\n.. |CI| image:: https://github.com/python-jsonschema/jsonschema/workflows/CI/badge.svg\n  :alt: Build status\n  :target: https://github.com/python-jsonschema/jsonschema/actions?query=workflow%3ACI\n\n.. |ReadTheDocs| image:: https://readthedocs.org/projects/python-jsonschema/badge/?version=stable&style=flat\n   :alt: ReadTheDocs status\n   :target: https://python-jsonschema.readthedocs.io/en/stable/\n\n.. |Precommit| image:: https://results.pre-commit.ci/badge/github/python-jsonschema/jsonschema/main.svg\n   :alt: pre-commit.ci status\n   :target: https://results.pre-commit.ci/latest/github/python-jsonschema/jsonschema/main\n\n.. |Zenodo| image:: https://zenodo.org/badge/3072629.svg\n   :target: https://zenodo.org/badge/latestdoi/3072629\n\n\n``jsonschema`` is an implementation of the `JSON Schema\n<https://json-schema.org>`_ specification for Python.\n\n.. code-block:: python\n\n    >>> from jsonschema import validate\n\n    >>> # A sample schema, like what we\'d get from json.load()\n    >>> schema = {\n    ...     "type" : "object",\n    ...     "properties" : {\n    ...         "price" : {"type" : "number"},\n    ...         "name" : {"type" : "string"},\n    ...     },\n    ... }\n\n    >>> # If no exception is raised by validate(), the instance is valid.\n    >>> validate(instance={"name" : "Eggs", "price" : 34.99}, schema=schema)\n\n    >>> validate(\n    ...     instance={"name" : "Eggs", "price" : "Invalid"}, schema=schema,\n    ... )                                   # doctest: +IGNORE_EXCEPTION_DETAIL\n    Traceback (most recent call last):\n        ...\n    ValidationError: \'Invalid\' is not of type \'number\'\n\nIt can also be used from console:\n\n.. code-block:: bash\n\n    $ jsonschema --instance sample.json sample.schema\n\nFeatures\n--------\n\n* Partial support for\n  `Draft 2020-12 <https://python-jsonschema.readthedocs.io/en/latest/validate/#jsonschema.Draft202012Validator>`_ and\n  `Draft 2019-09 <https://python-jsonschema.readthedocs.io/en/latest/validate/#jsonschema.Draft201909Validator>`_,\n  except for ``dynamicRef`` / ``recursiveRef`` and ``$vocabulary`` (in-progress).\n  Full support for\n  `Draft 7 <https://python-jsonschema.readthedocs.io/en/latest/validate/#jsonschema.Draft7Validator>`_,\n  `Draft 6 <https://python-jsonschema.readthedocs.io/en/latest/validate/#jsonschema.Draft6Validator>`_,\n  `Draft 4 <https://python-jsonschema.readthedocs.io/en/latest/validate/#jsonschema.Draft4Validator>`_\n  and\n  `Draft 3 <https://python-jsonschema.readthedocs.io/en/latest/validate/#jsonschema.Draft3Validator>`_\n\n* `Lazy validation <https://python-jsonschema.readthedocs.io/en/latest/validate/#jsonschema.protocols.Validator.iter_errors>`_\n  that can iteratively report *all* validation errors.\n\n* `Programmatic querying <https://python-jsonschema.readthedocs.io/en/latest/errors/>`_\n  of which properties or items failed validation.\n\n\nInstallation\n------------\n\n``jsonschema`` is available on `PyPI <https://pypi.org/project/jsonschema/>`_. You can install using `pip <https://pip.pypa.io/en/stable/>`_:\n\n.. code-block:: bash\n\n    $ pip install jsonschema\n\n\nRunning the Test Suite\n----------------------\n\nIf you have ``tox`` installed (perhaps via ``pip install tox`` or your\npackage manager), running ``tox`` in the directory of your source\ncheckout will run ``jsonschema``\'s test suite on all of the versions\nof Python ``jsonschema`` supports. If you don\'t have all of the\nversions that ``jsonschema`` is tested under, you\'ll likely want to run\nusing ``tox``\'s ``--skip-missing-interpreters`` option.\n\nOf course you\'re also free to just run the tests on a single version with your\nfavorite test runner. The tests live in the ``jsonschema.tests`` package.\n\n\nBenchmarks\n----------\n\n``jsonschema``\'s benchmarks make use of `pyperf\n<https://pyperf.readthedocs.io>`_. Running them can be done via::\n\n      $ tox -e perf\n\n\nCommunity\n---------\n\nThe JSON Schema specification has `a Slack\n<https://json-schema.slack.com>`_, with an `invite link on its home page\n<https://json-schema.org/>`_. Many folks knowledgeable on authoring\nschemas can be found there.\n\nOtherwise, asking questions on Stack Overflow is another means of\ngetting help if you\'re stuck.\n\n\nAbout\n-----\n\nI\'m Julian Berman.\n\n``jsonschema`` is on `GitHub <https://github.com/python-jsonschema/jsonschema>`_.\n\nGet in touch, via GitHub or otherwise, if you\'ve got something to contribute,\nit\'d be most welcome!\n\nYou can also generally find me on Libera (nick: ``Julian``) in various\nchannels, including ``#python``.\n\nIf you feel overwhelmingly grateful, you can also `sponsor me\n<https://github.com/sponsors/Julian/>`_.\n\nAnd for companies who appreciate ``jsonschema`` and its continued support\nand growth, ``jsonschema`` is also now supportable via `TideLift\n<https://tidelift.com/subscription/pkg/pypi-jsonschema?utm_source=pypi-j\nsonschema&utm_medium=referral&utm_campaign=readme>`_.\n',
+    author='Julian Berman',
+    author_email='Julian+jsonschema@GrayVines.com',
+    classifiers=[
+        'Development Status :: 5 - Production/Stable',
+        'Intended Audience :: Developers',
+        'License :: OSI Approved :: MIT License',
+        'Operating System :: OS Independent',
+        'Programming Language :: Python',
+        'Programming Language :: Python :: 3.10',
+        'Programming Language :: Python :: 3.11',
+        'Programming Language :: Python :: 3.7',
+        'Programming Language :: Python :: 3.8',
+        'Programming Language :: Python :: 3.9',
+        'Programming Language :: Python :: Implementation :: CPython',
+        'Programming Language :: Python :: Implementation :: PyPy',
+    ],
+    install_requires=[
+        'attrs>=17.4.0',
+        'importlib-metadata; python_version < "3.8"',
+        'importlib-resources>=1.4.0; python_version < "3.9"',
+        'pyrsistent!=0.17.0,!=0.17.1,!=0.17.2,>=0.14.0',
+        'typing-extensions; python_version < "3.8"',
+    ],
+    extras_require={
+        'format': [
+            'fqdn',
+            'idna',
+            'isoduration',
+            'jsonpointer>1.13',
+            'rfc3339-validator',
+            'rfc3987',
+            'uri-template',
+            'webcolors>=1.11',
+        ],
+        'format-nongpl': [
+            'fqdn',
+            'idna',
+            'isoduration',
+            'jsonpointer>1.13',
+            'rfc3339-validator',
+            'rfc3986-validator>0.1.0',
+            'uri-template',
+            'webcolors>=1.11',
+        ],
+    },
+    entry_points={
+        'console_scripts': [
+            'jsonschema = jsonschema.cli:main',
+        ],
+    },
+    packages=[
+        'jsonschema',
+        'jsonschema.schemas',
+        'jsonschema.benchmarks',
+        'jsonschema.tests',
+    ],
+    package_data={'': ['*']},
+)
