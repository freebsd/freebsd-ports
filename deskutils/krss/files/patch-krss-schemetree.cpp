--- krss/schemetree.cpp.orig	Mon Nov 26 10:16:21 2001
+++ krss/schemetree.cpp	Wed May 21 10:33:35 2003
@@ -24,6 +24,8 @@
 
 #include "colourconverter.h"
 
+using namespace std;
+
 SchemeTree::SchemeTree()
 {	
 	clear();
@@ -178,7 +180,6 @@
 				ctfelm.setAttribute("underline", "true");
 			else
 				ctfelm.setAttribute("underline", "false");
-			ctfelm.setAttribute("charset", QString::number(channelTitleFont().charSet()));
 		ctelm.appendChild(ctfelm);
 		QDomElement ctaelm = doc.createElement("align");
 			QDomText ctatxt = doc.createTextNode(QString::number(channelTitleAlign()));
@@ -220,7 +221,6 @@
 				cdfelm.setAttribute("underline", "true");
 			else
 				cdfelm.setAttribute("underline", "false");
-			cdfelm.setAttribute("charset", QString::number(channelDescriptionFont().charSet()));
 		cdelm.appendChild(cdfelm);
 			QDomElement cdaelm = doc.createElement("align");
 				QDomText cdatxt = doc.createTextNode(QString::number(channelDescriptionAlign()));
@@ -251,7 +251,6 @@
 				ntfelm.setAttribute("underline", "true");
 			else
 				ntfelm.setAttribute("underline", "false");
-			ntfelm.setAttribute("charset", QString::number(newsTitleFont().charSet()));
 		ntelm.appendChild(ntfelm);
 		QDomElement ntaelm = doc.createElement("align");
 			QDomText ntatxt = doc.createTextNode(QString::number(newsTitleAlign()));
@@ -283,7 +282,6 @@
 				ndfelm.setAttribute("underline", "true");
 			else
 				ndfelm.setAttribute("underline", "false");
-			ndfelm.setAttribute("charset", QString::number(newsDescriptionFont().charSet()));
 		ndelm.appendChild(ndfelm);
 			QDomElement ndaelm = doc.createElement("align");
 				QDomText ndatxt = doc.createTextNode(QString::number(newsDescriptionAlign()));
