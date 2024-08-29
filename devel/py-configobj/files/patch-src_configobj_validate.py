From: cdcadman <mythirty@gmail.com>
Date: Wed, 17 May 2023 03:57:08 -0700
Subject: Address CVE-2023-26112 ReDoS

Origin: https://github.com/DiffSK/configobj/pull/236
--- src/configobj/validate.py.orig	2023-01-18 22:28:31 UTC
+++ src/configobj/validate.py
@@ -541,7 +541,7 @@ class Validator(object):
     """
 
     # this regex does the initial parsing of the checks
-    _func_re = re.compile(r'(.+?)\((.*)\)', re.DOTALL)
+    _func_re = re.compile(r'([^\(\)]+?)\((.*)\)', re.DOTALL)
 
     # this regex takes apart keyword arguments
     _key_arg = re.compile(r'^([a-zA-Z_][a-zA-Z0-9_]*)\s*=\s*(.*)$',  re.DOTALL)
