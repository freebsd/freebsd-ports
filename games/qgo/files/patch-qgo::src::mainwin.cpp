--- qgo/src/mainwin.cpp.orig	Sat Jun 19 07:38:43 2004
+++ qgo/src/mainwin.cpp	Sun Aug 22 15:55:59 2004
@@ -1604,10 +1604,10 @@
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
