--- src/mainwin.cpp.orig	Mon Mar 27 06:37:41 2006
+++ src/mainwin.cpp	Wed Apr 12 13:36:58 2006
@@ -1589,11 +1589,11 @@
       			//set the params of "who command"
 			if ((whoBox1->currentItem() >1)  || (whoBox2->currentItem() >1))
         		{
-				wparam.append(whoBox1->currentItem()==1 ? "9p" : whoBox1->currentText());
+				wparam.append(whoBox1->currentItem()==1 ? QString("9p") : whoBox1->currentText());
 				if ((whoBox1->currentItem())  && (whoBox2->currentItem()))
 					wparam.append("-");
 
-				wparam.append(whoBox2->currentItem()==1 ? "9p" : whoBox2->currentText());
+				wparam.append(whoBox2->currentItem()==1 ? QString("9p") : whoBox2->currentText());
          		} 
 			else if ((whoBox1->currentItem())  || (whoBox2->currentItem()))
         			wparam.append("1p-9p");
