--- krss/configuredialog.cpp~	Thu Dec 13 16:28:44 2001
+++ krss/configuredialog.cpp	Tue Sep 10 23:06:11 2002
@@ -29,6 +29,7 @@
 #include <qlabel.h>
 #include <qtoolbutton.h>
 #include <qradiobutton.h>
+#include <qpushbutton.h>
 
 #include <ktip.h>
 #include <klineeditdlg.h>
@@ -102,9 +103,9 @@
 	/** Calculate the size of the caches **/
 	KURL url;
 	url.setPath(QDir::homeDirPath() + QString("/.krss/feeds/unparsed/"));
-	ccv_bend->mFeedSize->setText(i18n("Size: ") + QString::number(KDirSize::dirSize(url)/1024, KGlobal::locale()->fracDigits()) + QString("KB"));
+	ccv_bend->mFeedSize->setText(i18n("Size: ") + QString::number((long)KDirSize::dirSize(url)/1024, KGlobal::locale()->fracDigits()) + QString("KB"));
 	url.setPath(QDir::homeDirPath() + QString("/.krss/cache/"));
-	ccv_bend->mImageSize->setText(i18n("Size: ") + QString::number(KDirSize::dirSize(url)/1024, KGlobal::locale()->fracDigits()) + QString("KB"));
+	ccv_bend->mImageSize->setText(i18n("Size: ") + QString::number((long)KDirSize::dirSize(url)/1024, KGlobal::locale()->fracDigits()) + QString("KB"));
 	
 	QFrame *page5 = addPage(i18n("MyChannelBar"), i18n("MyChannelBar"), QPixmap(KGlobal::iconLoader()->iconPath("view_icon", KIcon::Desktop)));
 	QHBoxLayout *lay5 = new QHBoxLayout(page5);
@@ -254,9 +255,9 @@
 	
 	KURL url;
 	url.setPath(QDir::homeDirPath() + QString("/.krss/feeds/unparsed/"));
-	ccv_bend->mFeedSize->setText(i18n("Size: ") + QString::number(KDirSize::dirSize(url)/1024) + QString("KB"));
+	ccv_bend->mFeedSize->setText(i18n("Size: ") + QString::number((long)KDirSize::dirSize(url)/1024) + QString("KB"));
 	url.setPath(QDir::homeDirPath() + QString("/.krss/cache/"));
-	ccv_bend->mImageSize->setText(i18n("Size: ") + QString::number(KDirSize::dirSize(url)/1024) + QString("KB"));
+	ccv_bend->mImageSize->setText(i18n("Size: ") + QString::number((long)KDirSize::dirSize(url)/1024) + QString("KB"));
 }
 
 void ConfigureDialog::clearFeedCache(void)
@@ -283,9 +284,9 @@
 	
 	KURL url;
 	url.setPath(QDir::homeDirPath() + QString("/.krss/feeds/unparsed/"));
-	ccv_bend->mFeedSize->setText(i18n("Size: ") + QString::number(KDirSize::dirSize(url)/1024) + QString("KB"));
+	ccv_bend->mFeedSize->setText(i18n("Size: ") + QString::number((long)KDirSize::dirSize(url)/1024) + QString("KB"));
 	url.setPath(QDir::homeDirPath() + QString("/.krss/cache/"));
-	ccv_bend->mImageSize->setText(i18n("Size: ") + QString::number(KDirSize::dirSize(url)/1024) + QString("KB"));
+	ccv_bend->mImageSize->setText(i18n("Size: ") + QString::number((long)KDirSize::dirSize(url)/1024) + QString("KB"));
 }
 
 void ConfigureDialog::clearImageCache(void)
