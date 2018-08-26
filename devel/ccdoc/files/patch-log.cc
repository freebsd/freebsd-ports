log.cc:236:8: error: invalid operands to binary expression ('std::__1::ostream' (aka 'basic_ostream<char>') and 'std::__1::ostream')
        (*os) << fct( *os );
                ~~~~~ ^  ~~~~~~~~~~

Never used

--- log.cc.orig	2018-08-26 04:28:55 UTC
+++ log.cc
@@ -225,20 +225,6 @@ ccdoc::log& ccdoc::log::operator << (const vector<stri
   return *this;
 }
 // ================================================================
-// operator <<
-// ================================================================
-ccdoc::log& ccdoc::log::operator << (ostream& (fct)(ostream&) ) {
-  if(m_output_flag) {
-    vector<ostream*>::iterator i = m_os.begin();
-    for( ; i!=m_os.end(); ++i) {
-      ostream* os = *i;
-      if(os)
-	(*os) << fct( *os );
-    }
-  }
-  return *this;
-}
-// ================================================================
 // Warning
 // ================================================================
 ccdoc::log& ccdoc::log::warning() {
