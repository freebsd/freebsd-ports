--- kfax/kfax.cpp.orig	Fri Dec  1 13:48:29 2000
+++ kfax/kfax.cpp	Fri Dec  1 13:51:10 2000
@@ -46,6 +46,7 @@
 #include <kmessagebox.h>
 #include <kcmdlineargs.h>
 #include <kio/netaccess.h>
+#include <ktempfile.h>
 
 #include "kfax.h"
 #include "kfax.moc"
@@ -994,14 +995,12 @@
       if(defaultpage.expander ==  g31expand)
 	faxtype = 31;
 
+      KTempFile tmpFile;
+      tmpFile.setAutoDelete(true);
 
-      QString tempfile;
-      tempfile = tmpnam(NULL);
+      fax2tiffmain(pn->pathname,QFile::encodeName(tmpFile.name()),pn->lsbfirst,pn->vres?0:1,faxtype);
 
-      fax2tiffmain(pn->pathname,tempfile.ascii(),pn->lsbfirst,pn->vres?0:1,faxtype);
-      fax2psmain(tempfile.ascii(),psfile,width,height,pi.scale);
-
-      remove(tempfile.ascii());
+      fax2psmain(QFile::encodeName(tmpFile.name()),psfile,width,height,pi.scale);
 
     }
 
