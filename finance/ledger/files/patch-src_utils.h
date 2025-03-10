--- src/utils.h.orig	2023-03-30 07:40:48 UTC
+++ src/utils.h
@@ -607,29 +607,39 @@ inline int peek_next_nonws(std::istream& in) {
     *_p = '\0';                                         \
   }
 
-inline string to_hex(unsigned int * message_digest, const int len = 1)
-{
+inline string digest_to_hex(
+  const boost::uuids::detail::sha1::digest_type& message_digest,
+  size_t len = sizeof(boost::uuids::detail::sha1::digest_type) * 2
+) {
   std::ostringstream buf;
+  buf.setf(std::ios_base::hex, std::ios_base::basefield);
+  buf.fill('0');
 
-  for(int i = 0; i < 5 ; i++) {
-    buf.width(8);
-    buf.fill('0');
-    buf << std::hex << message_digest[i];
-    if (i + 1 >= len)
-      break;                    // only output the first LEN dwords
+  // sha1::digest_type is an array type and may change between Boost versions
+  const size_t count = std::min(
+    sizeof(message_digest) / sizeof(message_digest[0]),
+    (len - 1) / (sizeof(message_digest[0]) * 2) + 1
+  );
+  for(size_t i = 0; i < count; i++) {
+    buf.width(sizeof(message_digest[i]) * 2);
+    buf << (unsigned int)message_digest[i];
   }
-  return buf.str();
+  string hex = buf.str();
+  hex.resize(len, '0'); // in case a partial element is requested
+  return hex;
 }
 
-inline string sha1sum(const string& str)
-{
-	boost::uuids::detail::sha1 sha;
+inline string sha1sum(
+  const string& str,
+  size_t len = sizeof(boost::uuids::detail::sha1::digest_type) * 2
+) {
+	static boost::uuids::detail::sha1 sha;
+  boost::uuids::detail::sha1::digest_type message_digest;
 
+	sha.reset();
   sha.process_bytes(str.c_str(), str.length());
-
-  unsigned int message_digest[5];
   sha.get_digest(message_digest);
-  return to_hex(message_digest, 5);
+  return digest_to_hex(message_digest, len);
 }
 
 extern const string version;
