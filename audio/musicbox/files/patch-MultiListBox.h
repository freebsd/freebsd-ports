--- MultiListBox.h.orig	Wed Nov 12 10:57:00 1997
+++ MultiListBox.h	Sun Dec 31 06:24:22 2000
@@ -16,7 +16,6 @@
 		Pic = i->Pic;
 		Text = i->Text;
 	} 
-	setPixmap(QPixmap& p) {Pic = p;}
 	int Width(MultiListBox *box);
 	int Height(MultiListBox *box,int max_w);
 	void Paint(QPainter *p,int w,int h,int flag=0);
