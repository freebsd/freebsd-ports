--- pdns/recursor_cache.cc	(revision 533)
+++ pdns/recursor_cache.cc	(revision 534)
@@ -61,7 +61,12 @@
 void MemRecursorCache::replace(const string &qname, const QType& qt,  const set<DNSResourceRecord>& content)
 {
   set<StoredRecord>& stored=d_cache[toLowerCanonic(qname)+"|"+qt.getName()];
+
+  for(set<StoredRecord>::iterator k=stored.begin();k!=stored.end();++k) 
+    k->d_string.prune();
+
   stored.clear();
+
   for(set<DNSResourceRecord>::const_iterator i=content.begin(); i != content.end(); ++i) {
     StoredRecord dr;
     dr.d_ttd=i->ttl;
@@ -88,7 +93,6 @@
     if(j->second.empty()) { // everything is gone
       d_cache.erase(j++);
       names++;
-      
     }
     else {
       ++j;
