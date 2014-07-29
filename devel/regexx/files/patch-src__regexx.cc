--- src/regexx.cc.orig	Tue Mar 13 22:42:21 2001
+++ src/regexx.cc	Sat Dec 29 08:27:24 2001
@@ -27,7 +27,7 @@
 // $Date: 2001/03/13 14:42:21 $
 
 #include "regexx.hh"
-#include "../pcre/pcre.h"
+#include "pcre.h"
 
 const unsigned int&
 regexx::Regexx::exec(int _flags)
@@ -43,13 +43,13 @@
     if(m_preg == NULL) {
       throw CompileException(errptr);
     }
-    pcre_fullinfo(m_preg, NULL, PCRE_INFO_CAPTURECOUNT, (void*)&m_capturecount);
+    pcre_fullinfo((const pcre *)m_preg, NULL, PCRE_INFO_CAPTURECOUNT, (void*)&m_capturecount);
     m_compiled = true;
   }
 
   if(!m_study && (_flags&study)) {
     const char *errptr;
-    m_extra = pcre_study(m_preg, 0, &errptr);
+    m_extra = pcre_study((const pcre *)m_preg, 0, &errptr);
     if(errptr != NULL)
       throw CompileException(errptr);
     m_study = true;
@@ -63,20 +63,20 @@
   int ssc;
   m_matches = 0;
 
-  ssc = pcre_exec(m_preg,m_extra,m_str.c_str(),m_str.length(),0,eflags,ssv,33);
+  ssc = pcre_exec((const pcre *)m_preg,(const pcre_extra *)m_extra,m_str.c_str(),m_str.length(),0,eflags,ssv,33);
   bool ret = (ssc > 0);
 
   if(_flags&global) {
     if(_flags&nomatch)
       while(ret) {
 	m_matches++;
-	ret = (pcre_exec(m_preg,m_extra,m_str.c_str(),m_str.length(),ssv[1],eflags,ssv,33) > 0);
+	ret = (pcre_exec((const pcre *)m_preg,(const pcre_extra *)m_extra,m_str.c_str(),m_str.length(),ssv[1],eflags,ssv,33) > 0);
       }
     else if(_flags&noatom)
       while(ret) {
 	m_matches++;
 	match.push_back(RegexxMatch(m_str,ssv[0],ssv[1]-ssv[0]));
-	ret = (pcre_exec(m_preg,m_extra,m_str.c_str(),m_str.length(),ssv[1],eflags,ssv,33) > 0);
+	ret = (pcre_exec((const pcre *)m_preg,(const pcre_extra *)m_extra,m_str.c_str(),m_str.length(),ssv[1],eflags,ssv,33) > 0);
       }
     else
       while(ret) {
@@ -89,7 +89,7 @@
 	  else
 	    match.back().atom.push_back(RegexxMatchAtom(m_str,0,0));
         }
-	ret = (pcre_exec(m_preg,m_extra,m_str.c_str(),m_str.length(),ssv[1],eflags,ssv,33) > 0);
+	ret = (pcre_exec((const pcre *)m_preg,(const pcre_extra *)m_extra,m_str.c_str(),m_str.length(),ssv[1],eflags,ssv,33) > 0);
       }
   }
   else {
@@ -114,7 +114,7 @@
 	  else
 	    match.back().atom.push_back(RegexxMatchAtom(m_str,0,0));
 	}
-	ret = (pcre_exec(m_preg,m_extra,m_str.c_str(),m_str.length(),ssv[1],eflags,ssv,33) > 0);
+	ret = (pcre_exec((const pcre *)m_preg,(const pcre_extra *)m_extra,m_str.c_str(),m_str.length(),ssv[1],eflags,ssv,33) > 0);
       }
     }
   }
