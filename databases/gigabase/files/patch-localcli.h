--- localcli.h.orig	Thu Aug 12 01:46:23 2004
+++ localcli.h	Thu Aug 12 01:47:39 2004
@@ -178,7 +178,7 @@
         for (i = 0; i < descriptor_table_size; i++) {
             table[i] = next = new T(i, next);
         }
-        free_chain = next;
+        this->free_chain = next;
     }
 
     ~descriptor_table() { 
@@ -186,13 +186,13 @@
     }
 
     T* get(int desc) {
-        dbCriticalSection cs(mutex);
+        dbCriticalSection cs(this->mutex);
         return (desc >= descriptor_table_size) ? (T*)0 : table[desc];
     }
 
     T* allocate() {
-        dbCriticalSection cs(mutex);
-        if (free_chain == NULL) {
+        dbCriticalSection cs(this->mutex);
+        if (this->free_chain == NULL) {
             int i, n;
             T** desc = new T*[descriptor_table_size * 2];
             memcpy(desc, table, descriptor_table_size*sizeof(T*));
@@ -202,11 +202,11 @@
             for (i = descriptor_table_size, n = i*2; i < n; i++) {
                 table[i] = next = new T(i, next);
             }
-            free_chain = next;
+            this->free_chain = next;
             descriptor_table_size = n;
         }
-        T* desc = free_chain;
-        free_chain = desc->next;
+        T* desc = this->free_chain;
+        this->free_chain = desc->next;
         return desc;
     }
 };
