--- pgdb.py.orig	Sun Nov  5 20:15:26 2000
+++ pgdb.py	Thu Nov 29 17:38:24 2001
@@ -58,7 +58,7 @@
 import string
 import exceptions
 import types
-import DateTime
+import mx.DateTime
 import time
 
 ### module constants
@@ -384,13 +384,13 @@
 
 # mandatory type helpers
 def Date(year, month, day):
-	return DateTime.DateTime(year, month, day)
+	return mx.DateTime.DateTime(year, month, day)
 
 def Time(hour, minute, second):
-	return DateTime.TimeDelta(hour, minute, second)
+	return mx.DateTime.TimeDelta(hour, minute, second)
 
 def Timestamp(year, month, day, hour, minute, second):
-	return DateTime.DateTime(year, month, day, hour, minute, second)
+	return mx.DateTime.DateTime(year, month, day, hour, minute, second)
 
 def DateFromTicks(ticks):
 	return apply(Date, time.localtime(ticks)[:3])
