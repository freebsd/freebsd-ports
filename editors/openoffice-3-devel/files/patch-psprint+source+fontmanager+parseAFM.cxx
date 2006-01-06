Issuetracker : #i60097#
CWS          : N/A
Author       : <maho@openoffice.org> (JCA)
Description  : getc and ungetc are defined at stdio.h

Index: psprint/source/fontmanager/parseAFM.cxx
===================================================================
RCS file: /cvs/gsl/psprint/source/fontmanager/parseAFM.cxx,v
retrieving revision 1.6
diff -u -r1.6 parseAFM.cxx
--- psprint/source/fontmanager/parseAFM.cxx	28 Dec 2005 17:08:38 -0000	1.6
+++ psprint/source/fontmanager/parseAFM.cxx	5 Jan 2006 22:05:26 -0000
@@ -113,8 +113,8 @@
     FileInputStream( const char* pFilename );
     ~FileInputStream();
     
-    int getc() { return (m_nPos < m_nLen) ? int(m_pMemory[m_nPos++]) : -1; }
-    void ungetc()
+    int getc_() { return (m_nPos < m_nLen) ? int(m_pMemory[m_nPos++]) : -1; }
+    void ungetc_()
     {
         if( m_nPos > 0 )
             m_nPos--;
@@ -278,18 +278,18 @@
 
     /* skip over white space */
     // relies on EOF = -1
-    while( is_white_Array[ (ch = stream->getc()) & 255 ] )
+    while( is_white_Array[ (ch = stream->getc_()) & 255 ] )
         ;
     
     idx = 0;
     while( ch != -1 && ! is_delimiter_Array[ ch & 255 ] )
     {
         ident[idx++] = ch;
-        ch = stream->getc();
+        ch = stream->getc_();
     }
 
     if (ch == -1 && idx < 1) return ((char *)NULL);
-    if (idx >= 1 && ch != ':' ) stream->ungetc();
+    if (idx >= 1 && ch != ':' ) stream->ungetc_();
     if (idx < 1 ) ident[idx++] = ch;    /* single-character token */
     ident[idx] = 0;
     rLen = idx;
@@ -311,16 +311,16 @@
     static char ident[MAX_NAME]; /* storage buffer for keywords */
     int ch, idx;
 
-    while ((ch = stream->getc()) == ' ' || ch == '\t' ); 
+    while ((ch = stream->getc_()) == ' ' || ch == '\t' ); 
     
     idx = 0;
     while (ch != -1 && ch != lineterm && ch != '\r') 
     {
         ident[idx++] = ch;
-        ch = stream->getc();
+        ch = stream->getc_();
     } /* while */
     
-    stream->ungetc();
+    stream->ungetc_();
     ident[idx] = 0;
 
     return(ident);  /* returns pointer to the token */
