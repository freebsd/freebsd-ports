commit af27c422f551e16989ff6f1722d83614c8550eb5
Author: Scott Cantor <cantor.2@osu.edu>
Date:   Wed Mar 6 21:14:13 2019 -0500

    CPPXT - Crash due to uncaught DOMException
    
    https://issues.shibboleth.net/jira/browse/CPPXT-143

diff --git a/xmltooling/util/ParserPool.cpp b/xmltooling/util/ParserPool.cpp
index 5d96b66..da23846 100644
--- xmltooling/util/ParserPool.cpp
+++ xmltooling/util/ParserPool.cpp
@@ -148,14 +148,28 @@ DOMDocument* ParserPool::parse(DOMLSInput& domsrc)
         checkinBuilder(janitor.release());
         return doc;
     }
-    catch (XMLException& ex) {
+    catch (const DOMException& ex) {
+        parser->getDomConfig()->setParameter(XMLUni::fgDOMErrorHandler, (void*)nullptr);
+        parser->getDomConfig()->setParameter(XMLUni::fgXercesUserAdoptsDOMDocument, true);
+        checkinBuilder(janitor.release());
+        auto_ptr_char temp(ex.getMessage());
+        throw XMLParserException(string("DOM error during parsing: ") + (temp.get() ? temp.get() : "no message"));
+    }
+    catch (const SAXException& ex) {
+        parser->getDomConfig()->setParameter(XMLUni::fgDOMErrorHandler, (void*)nullptr);
+        parser->getDomConfig()->setParameter(XMLUni::fgXercesUserAdoptsDOMDocument, true);
+        checkinBuilder(janitor.release());
+        auto_ptr_char temp(ex.getMessage());
+        throw XMLParserException(string("SAX error during parsing: ") + (temp.get() ? temp.get() : "no message"));
+    }
+    catch (const XMLException& ex) {
         parser->getDomConfig()->setParameter(XMLUni::fgDOMErrorHandler, (void*)nullptr);
         parser->getDomConfig()->setParameter(XMLUni::fgXercesUserAdoptsDOMDocument, true);
         checkinBuilder(janitor.release());
         auto_ptr_char temp(ex.getMessage());
         throw XMLParserException(string("Xerces error during parsing: ") + (temp.get() ? temp.get() : "no message"));
     }
-    catch (XMLToolingException&) {
+    catch (const XMLToolingException&) {
         parser->getDomConfig()->setParameter(XMLUni::fgDOMErrorHandler, (void*)nullptr);
         parser->getDomConfig()->setParameter(XMLUni::fgXercesUserAdoptsDOMDocument, true);
         checkinBuilder(janitor.release());
