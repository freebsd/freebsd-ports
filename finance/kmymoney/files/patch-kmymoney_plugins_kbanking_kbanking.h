Fix build with gwenhywfar >= 5.7.2. The DEPRECATED macro was renamed to
GWEN_DEPRECATED.

--- kmymoney/plugins/kbanking/kbanking.h.orig	2022-02-22 15:26:27 UTC
+++ kmymoney/plugins/kbanking/kbanking.h
@@ -158,7 +158,7 @@ class KBanking : public KMyMoneyPlugin::OnlinePluginEx
       *
       * @deprecated
       */
-    bool updateAccount(const MyMoneyAccount& acc) DEPRECATED;
+    bool updateAccount(const MyMoneyAccount& acc) GWEN_DEPRECATED;
 
     /**
       * Trigger the password cache timer
