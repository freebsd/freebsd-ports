--- kpdf/part.cpp	2006/01/18 21:57:05	499855
+++ kpdf/part.cpp	2006/01/23 23:11:54	501814
@@ -697,6 +697,11 @@
     KURL saveURL = KFileDialog::getSaveURL( url().isLocalFile() ? url().url() : url().fileName(), QString::null, widget() );
     if ( saveURL.isValid() && !saveURL.isEmpty() )
     {
+        if (saveURL == url())
+        {
+            KMessageBox::information( widget(), i18n("You are trying to overwrite \"%1\" with itself. This is not allowed. Please save it in another location.").arg(saveURL.filename()) );
+            return;
+        }
         if ( KIO::NetAccess::exists( saveURL, false, widget() ) )
         {
             if (KMessageBox::warningContinueCancel( widget(), i18n("A file named \"%1\" already exists. Are you sure you want to overwrite it?").arg(saveURL.filename()), QString::null, i18n("Overwrite")) != KMessageBox::Continue)
