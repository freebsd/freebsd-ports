--- m3-comm/tcp/src/POSIX/IP.m3.orig	2009-03-09 16:55:46.000000000 +0000
+++ m3-comm/tcp/src/POSIX/IP.m3
@@ -77,6 +77,8 @@ PROCEDURE GetAddress (ent: Unetdb.struct
 PROCEDURE GetHostAddr(): Address =
   VAR hname: ARRAY [0..255] OF CHAR;
       hostent: Unetdb.struct_hostent;
+      lochost := ARRAY [0..9] OF CHAR {'1', '2', '7', '.', '0', '.', '0',
+                '.', '1', '\000'};
   BEGIN
     LOCK mu DO
       IF Unix.gethostname(ADR(hname[0]), BYTESIZE(hname)) # 0 THEN
@@ -84,7 +86,10 @@ PROCEDURE GetHostAddr(): Address =
       END;
       VAR h := Unetdb.gethostbyname(ADR(hname[0]), ADR(hostent));
       BEGIN
-        IF h = NIL THEN IPError.Die(); END;
+        IF h = NIL THEN
+          h := Unetdb.gethostbyname(ADR(lochost[0]), ADR(hostent)); 
+          IF h = NIL THEN IPError.Die(); END;
+        END;
         RETURN GetAddress(h);
       END;
     END;
