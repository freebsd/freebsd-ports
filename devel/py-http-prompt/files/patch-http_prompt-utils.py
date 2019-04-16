Obtained from:	https://github.com/jonathanslenders/http-prompt/commit/34de86178d8ae2b478e0ad989222aab24dd4c046

--- http_prompt/utils.py.orig	2018-11-04 14:03:53 UTC
+++ http_prompt/utils.py
@@ -3,7 +3,7 @@ from __future__ import unicode_literals
 import math
 import re
 
-from prompt_toolkit.shortcuts import create_output
+from prompt_toolkit.output.defaults import create_output
 from six.moves import range
 
 
