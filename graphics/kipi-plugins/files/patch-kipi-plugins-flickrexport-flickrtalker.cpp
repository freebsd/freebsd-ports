--- kipi-plugins/flickrexport/flickrtalker.cpp.orig	Tue Oct 24 18:07:24 2006
+++ kipi-plugins/flickrexport/flickrtalker.cpp	Tue Oct 24 18:09:52 2006
@@ -277,7 +277,7 @@
 
 		QString isfriend=(info.is_friend==1)?"1":"0";
 		form.addPair("is_friend",isfriend);
-		headers.append("api_key="+ isfriend);
+		headers.append("is_friend="+ isfriend);
 
 		QString tags=info.tags.join(" ");
 		if(tags.length()>0){	
@@ -297,6 +297,7 @@
 		}
 
 		QString md5=getApiSig(m_secret,headers);
+		form.addPair("api_sig", md5);
 		headers.append("api_sig="+ md5);
 		QString queryStr=headers.join("&");
 		QString postUrl=url+queryStr;
