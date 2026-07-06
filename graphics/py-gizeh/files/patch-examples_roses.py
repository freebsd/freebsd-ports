-- Fix gcd import for Python 3.9+.

--- examples/roses.py.orig	2026-06-08 09:41:52 UTC
+++ examples/roses.py
@@ -5,7 +5,7 @@ http://en.wikipedia.org/wiki/Rose_mathematics
 http://en.wikipedia.org/wiki/Rose_mathematics
 """
 
-from fractions import gcd
+from math import gcd
 
 import numpy as np
 
