--- src/information/CInformationElementHistory.cpp.orig	Fri Dec  5 07:22:09 2003
+++ src/information/CInformationElementHistory.cpp	Tue Jul 13 22:32:26 2004
@@ -156,7 +156,7 @@
 
       CInformationElement* pIE = mList.at(i);
       std::cout<<i<<sSeparator<<pIE<<"\t";
-      sDesc =  (NULLPTR != pIE) ? pIE->getDescription() : "NULLPTR";
+      sDesc =  (NULLPTR != pIE) ? pIE->getDescription() : QString("NULLPTR");
       std::cout<<sDesc<<std::endl;
    }
 
