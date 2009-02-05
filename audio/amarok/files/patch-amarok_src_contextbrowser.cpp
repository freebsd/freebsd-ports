
$FreeBSD$

--- amarok/src/contextbrowser.cpp.orig
+++ amarok/src/contextbrowser.cpp
@@ -4189,7 +4189,7 @@
     }
 
     // Ok lets remove the top and bottom parts of the page
-    m_wiki = m_wiki.mid( m_wiki.find( "<h1 class=\"firstHeading\">" ) );
+    m_wiki = m_wiki.mid( m_wiki.find( "<h1 id=\"firstHeading\"" ) );
     m_wiki = m_wiki.mid( 0, m_wiki.find( "<div class=\"printfooter\">" ) );
     // Adding back license information
     m_wiki += copyright;
