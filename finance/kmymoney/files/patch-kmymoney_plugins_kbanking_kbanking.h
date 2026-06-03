Prepend the C++14 [[deprecated]] attribute, which KMYMONEY_DEPRECATED
ultimately resolves to with Qt6 to prevent build errors.

--- kmymoney/plugins/kbanking/kbanking.h.orig	2025-08-04 11:03:25 UTC
+++ kmymoney/plugins/kbanking/kbanking.h
@@ -156,7 +156,8 @@ class KBanking : public KMyMoneyPlugin::OnlinePluginEx
       *
       * @deprecated
       */
-    bool updateAccount(const MyMoneyAccount& acc) KMYMONEY_DEPRECATED;
+    KMYMONEY_DEPRECATED
+    bool updateAccount(const MyMoneyAccount& acc);
 
     /**
       * Trigger the password cache timer
