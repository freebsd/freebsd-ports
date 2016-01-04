# Add support for standard test command
# https://github.com/jek/blinker/pull/26/

--- setup.py.orig	2015-12-27 05:36:22 UTC
+++ setup.py
@@ -37,4 +37,6 @@ setup(name="blinker",
           'Topic :: Software Development :: Libraries',
           'Topic :: Utilities',
           ],
+          tests_require=['nose'],
+          test_suite='nose.collector',
 )
