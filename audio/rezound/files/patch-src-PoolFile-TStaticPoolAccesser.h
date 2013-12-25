--- src/PoolFile/TStaticPoolAccesser.h.orig
+++ src/PoolFile/TStaticPoolAccesser.h
@@ -43,7 +43,7 @@ public:
 
 
 	// stream-like access methods
-	void read(pool_element_t buffer[],const l_addr_t count) const;
+	void read(pool_element_t buffer[],l_addr_t count) const;
 	void write(const pool_element_t buffer[],const l_addr_t count);
 
 	void seek(const l_addr_t where);
@@ -112,7 +112,7 @@ public:
 	mutable l_addr_t position;
 
 
-	void overflowWrite(const pool_element_t buffer[],const l_addr_t count,const bool append);
+	void overflowWrite(const pool_element_t buffer[],l_addr_t count,const bool append);
 
 	void cacheBlock(const l_addr_t where) const;
 
