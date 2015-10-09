From ac830d6b197f8b8dad24782d7900c69cee0ab77e Mon Sep 17 00:00:00 2001
From: Syl <srouquette@gmail.com>
Date: Sun, 30 Aug 2015 08:57:48 +0200
Subject: [PATCH] Fix gmock_doctor.py for Python3

--- scripts/gmock_doctor.py.orig	2013-09-19 00:32:04 UTC
+++ scripts/gmock_doctor.py
@@ -590,7 +590,7 @@ def main():
     print ('Please copy and paste the compiler errors here.  Press c-D when '
            'you are done:')
   else:
-    print 'Waiting for compiler errors on stdin . . .'
+    print ('Waiting for compiler errors on stdin . . .')
 
   msg = sys.stdin.read().strip()
   diagnoses = Diagnose(msg)
@@ -608,18 +608,18 @@ If you send your source code and the com
 %s, you can be helped and I can get smarter --
 win-win for us!""" % (msg, _EMAIL))
   else:
-    print '------------------------------------------------------------'
-    print 'Your code appears to have the following',
+    print ('------------------------------------------------------------')
+    print ('Your code appears to have the following',)
     if count > 1:
-      print '%s diseases:' % (count,)
+      print ('%s diseases:' % (count,))
     else:
-      print 'disease:'
+      print ('disease:')
     i = 0
     for d in diagnoses:
       i += 1
       if count > 1:
-        print '\n#%s:' % (i,)
-      print d
+        print ('\n#%s:' % (i,))
+      print (d)
     print ("""
 How did I do?  If you think I'm wrong or unhelpful, please send your
 source code and the compiler's error messages to %s.
