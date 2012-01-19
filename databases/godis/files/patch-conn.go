--- conn.go.orig	2011-09-04 22:00:03.000000000 +0200
+++ conn.go	2012-01-18 21:31:25.000000000 +0100
@@ -342,8 +342,8 @@
 }
 
 func (cc *conn) configConn(db int, password string) os.Error {
-    if db != 0 {
-        buf := [][]byte{[]byte("SELECT"), []byte(strconv.Itoa(db))}
+    if password != "" {
+        buf := [][]byte{[]byte("AUTH"), []byte(password)}
         _, err := cc.rwc.Write(buildCmd(buf))
 
         if err != nil {
@@ -356,8 +356,8 @@
         }
     }
 
-    if password != "" {
-        buf := [][]byte{[]byte("AUTH"), []byte(password)}
+    if db != 0 {
+        buf := [][]byte{[]byte("SELECT"), []byte(strconv.Itoa(db))}
         _, err := cc.rwc.Write(buildCmd(buf))
 
         if err != nil {