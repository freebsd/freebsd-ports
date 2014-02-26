--- ./request.go.orig	2014-02-25 00:55:56.000000000 -0500
+++ ./request.go	2014-02-26 11:51:45.000000000 -0500
@@ -15,19 +15,34 @@
 	PathParams map[string]string
 }
 
+func CToGoString(c []byte) string {
+    n := -1
+    for i, b := range c {
+        if b == 0 {
+            break
+        }
+        n = i
+    }
+    return string(c[:n+1])
+}
+
 // Provide a convenient access to the PathParams map
 func (self *Request) PathParam(name string) string {
 	return self.PathParams[name]
 }
 
 // Read the request body and decode the JSON using json.Unmarshal
-func (self *Request) DecodeJsonPayload(v interface{}) error {
+func (self *Request) DecodeJsonPayload(v interface{}, decodeBody bool) error {
 	content, err := ioutil.ReadAll(self.Body)
 	self.Body.Close()
 	if err != nil {
 		return err
 	}
-	err = json.Unmarshal(content, v)
+    contentstr := ""
+    if decodeBody == true {
+        contentstr, _ = url.QueryUnescape(CToGoString(content))
+    }
+	err = json.Unmarshal([]byte(contentstr), v)
 	if err != nil {
 		return err
 	}
