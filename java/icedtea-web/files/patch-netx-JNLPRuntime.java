--- netx/net/sourceforge/jnlp/runtime/JNLPRuntime.java	Tue Jun 18 15:57:01 2013 -0400
+++ netx/net/sourceforge/jnlp/runtime/JNLPRuntime.java	Thu Jun 20 15:20:57 2013 +0200
@@ -234,7 +234,7 @@
         try {
             UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
         } catch (Exception e) {
-            // ignore it
+            e.printStackTrace();
         }
 
         doMainAppContextHacks();
