diff -uNr src/kernel/qinputcontext_x11.cpp.orig src/kernel/qinputcontext_x11.cpp
--- src/kernel/qinputcontext_x11.cpp.orig	Thu Nov  7 22:07:34 2002
+++ src/kernel/qinputcontext_x11.cpp	Thu Nov 28 16:52:24 2002
@@ -153,6 +153,13 @@
 	    }
 	}
 
+	if (! qic->composing) {
+	    qic->composing = TRUE;
+	    qic->focusWidget = qApp->focusWidget();
+	    QIMEvent startevent(QEvent::IMStart, QString::null, -1);
+	    QApplication::sendEvent(qic->focusWidget, &startevent);
+	}
+
 	if (! qic->composing || ! qic->focusWidget) {
 	    // qDebug("compose event: invalid compose event %d %p",
 	    // qic->composing, qic->focusWidget);
