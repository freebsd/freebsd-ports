--- cpp/test/IceGrid/distribution/run.py.orig	2019-08-12 19:54:18 UTC
+++ cpp/test/IceGrid/distribution/run.py
@@ -25,7 +25,7 @@ def icepatch2Calc(datadir, dirname):
     commandProc = TestUtil.spawn('"%s" "%s"' % (icePatch2Calc, os.path.join(datadir, dirname)))
     commandProc.waitTestSuccess()
 
-datadir = os.path.join(os.getcwd(), "data")
+datadir = os.path.join(os.getcwd(), "db/data")
  
 files = [ 
   [ "original/rootfile", "rootfile" ],
