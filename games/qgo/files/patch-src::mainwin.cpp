--- src/mainwin.cpp.orig	Mon Nov 29 15:42:39 2004
+++ src/mainwin.cpp	Tue Dec 14 19:37:16 2004
@@ -1571,10 +1571,10 @@
       //set the params of "who command"
       if ((whoBox1->currentItem() >1)  || (whoBox2->currentItem() >1))
         {
-             wparam.append(whoBox1->currentItem()==1 ? "9p" : whoBox1->currentText());
+             wparam.append(whoBox1->currentItem()==1 ? QString("9p") : whoBox1->currentText());
              if ((whoBox1->currentItem())  && (whoBox2->currentItem()))
                 wparam.append("-");
-             wparam.append(whoBox2->currentItem()==1 ? "9p" : whoBox2->currentText());
+             wparam.append(whoBox2->currentItem()==1 ? QString("9p") : whoBox2->currentText());
          }
       else if ((whoBox1->currentItem())  || (whoBox2->currentItem()))
            wparam.append("1p-9p");
