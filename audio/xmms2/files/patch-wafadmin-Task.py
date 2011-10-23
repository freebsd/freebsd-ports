--- wafadmin/Task.py.orig	2010-02-19 18:43:54.000000000 +0100
+++ wafadmin/Task.py	2011-10-14 14:36:57.000663231 +0200
@@ -47,6 +47,7 @@
 import Build, Runner, Utils, Node, Logs, Options
 from Logs import debug, warn, error
 from Constants import *
+import time
 
 algotype = NORMAL
 #algotype = JOBCONTROL
@@ -406,6 +407,7 @@
 	def call_run(self):
 		if self.can_retrieve_cache():
 			return 0
+		time.sleep(0.02)
 		return self.run()
 
 	def run(self):
