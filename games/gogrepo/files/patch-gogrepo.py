--- gogrepo.py.orig	2017-04-18 19:27:22 UTC
+++ gogrepo.py
@@ -4,7 +4,7 @@ from __future__ import print_function
 from __future__ import division
 from __future__ import unicode_literals
 
-__appname__ = 'gogrepo.py'
+__appname__ = 'gogrepo'
 __author__ = 'eddie3'
 __version__ = '0.3a'
 __url__ = 'https://github.com/eddie3/gogrepo'
@@ -110,7 +110,7 @@ HTTP_GAME_DOWNLOADER_THREADS = 4
 HTTP_PERM_ERRORCODES = (404, 403, 503)
 
 # Save manifest data for these os and lang combinations
-DEFAULT_OS_LIST = ['windows']
+DEFAULT_OS_LIST = ['linux']
 DEFAULT_LANG_LIST = ['en']
 
 # These file types don't have md5 data from GOG
@@ -575,7 +575,7 @@ def cmd_login(user, passwd):
 
     # perform two-step if needed
     if login_data['two_step_url'] is not None:
-        login_data['two_step_security_code'] = input("enter two-step security code: ")
+        login_data['two_step_security_code'] = input("enter two-step security code (sent by mail): ")
 
         # Send the security code back to GOG
         with request(login_data['two_step_url'], delay=0,
