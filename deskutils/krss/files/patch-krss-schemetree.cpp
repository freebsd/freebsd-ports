--- krss/schemetree.cpp~	Sun Nov 25 17:16:21 2001
+++ krss/schemetree.cpp	Tue Sep 10 23:01:49 2002
@@ -178,7 +178,6 @@
 				ctfelm.setAttribute("underline", "true");
 			else
 				ctfelm.setAttribute("underline", "false");
-			ctfelm.setAttribute("charset", QString::number(channelTitleFont().charSet()));
 		ctelm.appendChild(ctfelm);
 		QDomElement ctaelm = doc.createElement("align");
 			QDomText ctatxt = doc.createTextNode(QString::number(channelTitleAlign()));
@@ -220,7 +219,6 @@
 				cdfelm.setAttribute("underline", "true");
 			else
 				cdfelm.setAttribute("underline", "false");
-			cdfelm.setAttribute("charset", QString::number(channelDescriptionFont().charSet()));
 		cdelm.appendChild(cdfelm);
 			QDomElement cdaelm = doc.createElement("align");
 				QDomText cdatxt = doc.createTextNode(QString::number(channelDescriptionAlign()));
@@ -251,7 +249,6 @@
 				ntfelm.setAttribute("underline", "true");
 			else
 				ntfelm.setAttribute("underline", "false");
-			ntfelm.setAttribute("charset", QString::number(newsTitleFont().charSet()));
 		ntelm.appendChild(ntfelm);
 		QDomElement ntaelm = doc.createElement("align");
 			QDomText ntatxt = doc.createTextNode(QString::number(newsTitleAlign()));
@@ -283,7 +280,6 @@
 				ndfelm.setAttribute("underline", "true");
 			else
 				ndfelm.setAttribute("underline", "false");
-			ndfelm.setAttribute("charset", QString::number(newsDescriptionFont().charSet()));
 		ndelm.appendChild(ndfelm);
 			QDomElement ndaelm = doc.createElement("align");
 				QDomText ndatxt = doc.createTextNode(QString::number(newsDescriptionAlign()));
