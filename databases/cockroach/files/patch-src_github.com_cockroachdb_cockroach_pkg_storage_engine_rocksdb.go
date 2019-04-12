--- src/github.com/cockroachdb/cockroach/pkg/storage/engine/rocksdb.go.orig	2018-12-10 15:51:01 UTC
+++ src/github.com/cockroachdb/cockroach/pkg/storage/engine/rocksdb.go
@@ -1986,22 +1986,22 @@ func (r *rocksDBIterator) Valid() (bool, error) {
 
 func (r *rocksDBIterator) Next() {
 	r.checkEngineOpen()
-	r.setState(C.DBIterNext(r.iter, false /* skip_current_key_versions */))
+	r.setState(C.DBIterNext(r.iter, C.bool(false) /* skip_current_key_versions */))
 }
 
 func (r *rocksDBIterator) Prev() {
 	r.checkEngineOpen()
-	r.setState(C.DBIterPrev(r.iter, false /* skip_current_key_versions */))
+	r.setState(C.DBIterPrev(r.iter, C.bool(false) /* skip_current_key_versions */))
 }
 
 func (r *rocksDBIterator) NextKey() {
 	r.checkEngineOpen()
-	r.setState(C.DBIterNext(r.iter, true /* skip_current_key_versions */))
+	r.setState(C.DBIterNext(r.iter, C.bool(true) /* skip_current_key_versions */))
 }
 
 func (r *rocksDBIterator) PrevKey() {
 	r.checkEngineOpen()
-	r.setState(C.DBIterPrev(r.iter, true /* skip_current_key_versions */))
+	r.setState(C.DBIterPrev(r.iter, C.bool(true) /* skip_current_key_versions */))
 }
 
 func (r *rocksDBIterator) Key() MVCCKey {
