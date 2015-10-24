--- armoryengine/Transaction.py.orig	2015-06-10 21:49:31 UTC
+++ armoryengine/Transaction.py
@@ -15,6 +15,7 @@ from armoryengine.BinaryUnpacker import 
 
 from armoryengine.AsciiSerialize import AsciiSerializable
 
+from armoryengine.MultiSigUtils import *
 
 UNSIGNED_TX_VERSION = 1
 
@@ -2674,7 +2675,6 @@ def PyCreateAndSignTx(ustxiList, dtxoLis
 #
 def PyCreateAndSignTx_old(srcTxOuts, dstAddrsVals):
    # This needs to support multisig. Perhaps the funct should just be moved....
-   from armoryengine.MultiSigUtils import *
 
    newTx = PyTx()
    newTx.version    = 1
