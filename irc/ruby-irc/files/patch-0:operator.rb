--- cpi/operator.cpi.orig	Wed Jun 14 10:03:51 2000
+++ cpi/operator.cpi	Fri Jan 19 17:15:50 2001
@@ -15,7 +15,7 @@
   include IRC
   def start(client)
     super
-    @operator = User.parse("igapon!igarashi@mahon.ueda.info.waseda.ac.jp")
+    @operator = User.parse(Operator)
     report("こんにちわ")
   end
   def stop
