--- src/kernel/qapplication_x11.cpp.orig	Mon Dec  9 18:40:39 2002
+++ src/kernel/qapplication_x11.cpp	Fri Apr 25 16:57:49 2003
@@ -3136,6 +3136,7 @@
 	  IMEnd with empty text (meaning the user has cancelled the
 	  input).
 	*/
+#if 0
 	QInputContext *qic =
 	    (QInputContext *) keywidget->topLevelWidget()->topData()->xic;
 	extern bool qt_compose_emptied; // qinputcontext_x11.cpp
@@ -3168,6 +3169,7 @@
 	    qt_compose_emptied = FALSE;
 	    qic->focusWidget = 0;
 	}
+#endif
 #endif // QT_NO_XIM
 
 	return 1;
@@ -4831,6 +4833,13 @@
 	    if ( qic ) {
 		mb=TRUE;
 		count = qic->lookupString(&xkeyevent, chars, &key, &status);
+		
+		if (qic->composing && qic->focusWidget) {
+		    QIMEvent event(QEvent::IMEnd, QString::null, -1);
+		    QApplication::sendEvent(qic->focusWidget, &event);
+		    qic->composing = FALSE;
+		    qic->focusWidget = 0;
+		}
 	    }
 	}
 	if ( !mb ) {
