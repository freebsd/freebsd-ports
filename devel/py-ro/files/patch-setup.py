--- setup.py.orig	Sat May 18 04:48:44 2002
+++ setup.py	Tue May 21 04:24:22 2002
@@ -35,19 +35,13 @@
 		print 'This script will install Pyro on your system.'
 		# first, confirm the installation path of the scripts.
 		scripts=[]
-		scr=raw_input('Do you want the Pyro scripts (in bin/) installed (y/n)? ')
+		scr='y'
 		config='setup.cfg'
 		if scr.lower()=='y':
 			cp=ConfigParser()
 			cp.read(config)
 			#loc=cp.get('install','install-scripts')
-			print 'Some Pyro scripts may conflict with system tools already on your system.'
-			print 'Choose your script install directory carefully.'
-			print 'The default location is usually something like C:\\Python\\Scripts'
-			print 'on Windows and /usr/local/bin on Unixes.'
-			#scr=raw_input('Where do you want them to be installed ('+loc+')? ')
-			scr=raw_input('Where do you want them to be installed (empty=default loc.)? ')
-			if scr:
+			if 0:
 				loc=scr
 				if not cp.has_section('install'):
 					cp.add_section('install')
