--- o_dbm.rb.orig	Fri Dec 12 00:31:32 1997
+++ o_dbm.rb	Fri Mar 16 18:29:28 2001
@@ -13,5 +13,4 @@
 require "e2mmap"
 require "dbm"
-require "marshal"
 
 class ObjectDBM
@@ -20,7 +19,7 @@
   extend Exception2MessageMapper
 
-  def_exception :ErrOnlyUsableTopTransaction, "トップトランザクションでしか実行できないオペレーション(%s)を実行しようとしました."
-  def_exception :ErrOnlyUsableInTransaction, "トランザクション内でないと実行できないオペレーション(%s)を実行しようとしました."
-  def_exception :ErrMixedTransaction, "静的トランザクションと動的トランザクションを混在して利用しようとしました."
+  def_exception :ErrOnlyUsableTopTransaction, "The operation (%s) can only be executed in the top level transaction."
+  def_exception :ErrOnlyUsableInTransaction, "The operation (%s) can only be executed within a transaction."
+  def_exception :ErrMixedTransaction, "Static transactions and dynamic transactions cannot be mixed together."
 
   include Enumerable
@@ -401,6 +400,6 @@
 
     extend Exception2MessageMapper
-    def_exception :ErrNoStartedTransaction, "トランザクションが開始されていません."
-    def_exception :ErrClosedTransaction, "トランザクションはすでに終了しています."
+    def_exception :ErrNoStartedTransaction, "Transaction is not started yet."
+    def_exception :ErrClosedTransaction, "Transaction is closed already."
 
     NO_START = :ObjectDBM__TXN_NO_START
