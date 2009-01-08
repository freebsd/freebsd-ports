--- setup.py.orig	2008-12-30 21:36:38.000000000 +0800
+++ setup.py	2008-12-30 21:37:41.000000000 +0800
@@ -40,7 +40,8 @@
 			loc=cp.get('install','install-scripts')
 			print 'Unattended install. Scripts will go to',loc
 		else:
-			scr=raw_input('Do you want the Pyro scripts (in bin/) installed (y/n)? ')
+			#scr=raw_input('Do you want the Pyro scripts (in bin/) installed (y/n)? ')
+			scr='y'
 
 		if scr.lower()=='y':
 			#loc=cp.get('install','install-scripts')
@@ -52,7 +53,8 @@
 				print 'The default location is usually something like C:\\Python\\Scripts'
 				print 'on Windows and /usr/local/bin on Unixes.'
 				#scr=raw_input('Where do you want them to be installed ('+loc+')? ')
-				scr=raw_input('Where do you want them to be installed (empty=default loc.)? ')
+				#scr=raw_input('Where do you want them to be installed (empty=default loc.)? ')
+				scr=''
 
 			if scr:
 				loc=scr
