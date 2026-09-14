--- src/prediction/gen_zero_query_data.py.orig	2020-08-14 17:09:18 UTC
+++ src/prediction/gen_zero_query_data.py
@@ -72,7 +72,7 @@ def RemoveTrailingNumber(string):
 def RemoveTrailingNumber(string):
   if not string:
     return b''
-  return re.sub(br'^([^0-9]+)[0-9]+$', r'\1', string)
+  return re.sub(br'^([^0-9]+)[0-9]+$', br'\1', string)
 
 
 def GetReadingsFromDescription(description):
