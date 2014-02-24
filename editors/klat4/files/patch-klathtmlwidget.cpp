--- klathtmlwidget.cpp.orig
+++ klathtmlwidget.cpp
@@ -73,7 +73,7 @@
 			}
 			if(cURL.protocol() == LTRTOKLATPROT && found == true)
 			{
-				for (i ,found = false ; !found && i < len ; i++)
+				for (i = 0, found = false ; !found && i < len ; i++)
 				{
 					if (code[i] == '}')
 					{
@@ -85,7 +85,9 @@
 		}
 		
 		emit signalSymbolCodeSelected(code,advance);
+		return found;
 	}
+	return false;
 }
 
 void KlatHTMLWidget::openAppDataUrl(const QString &relpath)
