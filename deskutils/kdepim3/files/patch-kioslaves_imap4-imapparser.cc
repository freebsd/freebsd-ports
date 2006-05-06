Index: kioslaves/imap4/imapparser.cc
===================================================================
--- kioslaves/imap4/imapparser.cc	(revision 537000)
+++ kioslaves/imap4/imapparser.cc	(revision 537001)
@@ -949,7 +949,9 @@ QAsciiDict < QString > imapParser::parse
 
     while (!inWords.isEmpty () && inWords[0] != ')')
     {
-      retVal.insert (parseLiteralC(inWords), new QString(parseLiteralC(inWords)));
+      QCString l1 = parseLiteralC(inWords);
+      QCString l2 = parseLiteralC(inWords);
+      retVal.insert (l1, new QString(l2));
     }
 
     if (inWords[0] != ')')
