--- setup.py.orig	Fri Mar 22 18:04:34 2002
+++ setup.py	Fri Mar 22 18:11:18 2002
@@ -36,16 +36,11 @@
 	else:	
 		# first, confirm the installation path of the scripts.
 		scripts=[]
-		scr=raw_input('Do you want the Pyro scripts (in bin/) installed (y/n)? ')
+		scr='y'
 		if scr.lower()=='y':
 			cp=ConfigParser()
 			cp.read('setup.cfg')
 			loc=cp.get('install','install-scripts')
-			print 'Some Pyro scripts may conflict with system tools already on your system.'
-			print 'Choose your script install directory carefully.'
-			scr=raw_input('Where do you want them to be installed ('+loc+')? ')
-			if scr:
-				loc=scr
 			cp.set('install','install-scripts',loc)
 			cp.write(open('setup.cfg','w'))
 		
