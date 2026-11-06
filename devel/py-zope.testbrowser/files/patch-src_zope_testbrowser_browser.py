Description: Use functools.cached_property instead of zope.cachedescriptors'
  Lazy.
Issue ID: none
Changeset: none
TODO: FreeBSD-specific (zope.cachedescriptors was removed from the ports
  tree), not for upstream.

--- src/zope/testbrowser/browser.py.orig	2019-11-12 09:52:53 UTC
+++ src/zope/testbrowser/browser.py
@@ -23,7 +23,7 @@ from six.moves import urllib_robotparser
 from six import string_types
 
 from zope.interface import implementer
-from zope.cachedescriptors.property import Lazy
+from functools import cached_property as Lazy
 from wsgiproxy.proxies import TransparentProxy
 from bs4 import BeautifulSoup
 from soupsieve import escape as css_escape
