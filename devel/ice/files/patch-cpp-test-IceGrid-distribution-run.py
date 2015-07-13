--- cpp/test/IceGrid/distribution/run.py.orig	2015-07-04 13:42:32.436390995 +0200
+++ cpp/test/IceGrid/distribution/run.py	2015-07-04 13:42:42.506606995 +0200
@@ -25,7 +25,7 @@
     commandProc = TestUtil.spawn('"%s" "%s"' % (icePatch2Calc, os.path.join(datadir, dirname)))
     commandProc.waitTestSuccess()
 
-datadir = os.path.join(os.getcwd(), "data")
+datadir = os.path.join(os.getcwd(), "db/data")
  
 files = [ 
   [ "original/rootfile", "rootfile" ],
