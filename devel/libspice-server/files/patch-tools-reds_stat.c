--- tools/reds_stat.c.orig	2017-09-21 11:05:07 UTC
+++ tools/reds_stat.c
@@ -34,11 +34,47 @@
 #define VALUE_TABS 7
 #define INVALID_STAT_REF (~(uint32_t)0)
 
+#define MREMAP_MAYMOVE     1
+
 verify(sizeof(SpiceStat) == 20 || sizeof(SpiceStat) == 24);
 
 static SpiceStatNode *reds_nodes = NULL;
 static uint64_t *values = NULL;
 
+void *mremap(int fd,void *oldaddr,size_t oldlen,size_t newlen,int prot,int flags);
+
+void *mremap(int fd,void *oldaddr,size_t oldlen,
+                                size_t newlen,int prot,int flags){
+        void *ret;
+
+        // From mmap(2) on freebsd 6.3: A successful FIXED mmap deletes any
+        // previous mapping in the allocated address range. This means:
+        // remapping over a current map will blow it away (unless FIXED isn't
+        // provided, in which case it can't overlap an old mapping. See bug
+        // 733 for extensive discussion of this issue for Linux and FreeBSD).
+        if((ret = mmap((char *)oldaddr + oldlen,newlen - oldlen,prot,flags,fd,oldlen)) == MAP_FAILED){
+                // We couldn't get the memory whatsoever (or we were a fresh
+                // allocation that succeeded). Return the immediate result...
+                return ret;
+        } // ret != MAP_FAILED. Did we squash?
+        if(ret != (char *)oldaddr + oldlen){
+                // We got the memory, but not where we wanted it. Copy over the
+                // old map, and then free it up...
+                //nag("Wanted %p, got %p\n",(char *)oldaddr + oldlen,ret);
+                munmap(ret,newlen - oldlen);
+//                Munmap(ret,newlen - oldlen);
+                if((ret = mmap(NULL,newlen,prot,flags,fd,0)) == MAP_FAILED){
+                        return ret;
+                }
+                memcpy(ret,oldaddr,oldlen);
+                munmap(oldaddr,oldlen); // Free the old mapping
+//                Munmap(oldaddr,oldlen); // Free the old mapping
+                return ret;
+        } // We successfully squashed. Return a pointer to the first buf.
+        return oldaddr;
+}
+
+
 static void print_stat_tree(int32_t node_index, int depth)
 {
     SpiceStatNode *node = &reds_nodes[node_index];
@@ -144,7 +180,8 @@ int main(int argc, char **argv)
             num_of_nodes = reds_stat->num_of_nodes;
             shm_old_size = shm_size;
             shm_size = header_size + num_of_nodes * sizeof(SpiceStatNode);
-            reds_stat = mremap(reds_stat, shm_old_size, shm_size, MREMAP_MAYMOVE);
+// todo
+//            reds_stat = mremap(reds_stat, shm_old_size, shm_size, MREMAP_MAYMOVE);
             if (reds_stat == (SpiceStat *)MAP_FAILED) {
                 perror("mremap");
                 goto error;
