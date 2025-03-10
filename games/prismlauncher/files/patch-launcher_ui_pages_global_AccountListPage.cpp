# Patch taken from er2off: https://github.com/er2off/freebsd-ports
--- launcher/ui/pages/global/AccountListPage.cpp.orig        2024-03-03 19:37:21 UTC
+++ launcher/ui/pages/global/AccountListPage.cpp
@@ -147,6 +147,7 @@ void AccountListPage::on_actionAddOffline_triggered()
 
 void AccountListPage::on_actionAddOffline_triggered()
 {
+#ifdef NO_OFFLINE
     if (!m_accounts->anyAccountIsValid()) {
         QMessageBox::warning(this, tr("Error"),
                              tr("You must add a Microsoft account that owns Minecraft before you can add an offline account."
@@ -154,6 +155,7 @@ void AccountListPage::on_actionAddOffline_triggered()
                                 "If you have lost your account you can contact Microsoft for support."));
         return;
     }
+#endif
 
     MinecraftAccountPtr account =
         OfflineLoginDialog::newAccount(this, tr("Please enter your desired username to add your offline account."));
