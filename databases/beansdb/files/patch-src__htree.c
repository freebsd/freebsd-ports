--- src/htree.c.orig	2013-07-17 08:09:12 UTC
+++ src/htree.c
@@ -74,23 +74,23 @@ static void split_node(HTree *tree, Node
 static void merge_node(HTree *tree, Node *node);
 static void update_node(HTree *tree, Node *node);
 
-inline uint32_t get_pos(HTree *tree, Node *node)
+static inline uint32_t get_pos(HTree *tree, Node *node)
 {
     return (node - tree->root) - g_index[(int)node->depth];
 }
 
-inline Node *get_child(HTree *tree, Node *node, int b)
+static inline Node *get_child(HTree *tree, Node *node, int b)
 {
     int i = g_index[node->depth + 1] + (get_pos(tree, node) << 4) + b;
     return tree->root + i;
 }
 
-inline Data* get_data(Node *node)
+static inline Data* get_data(Node *node)
 {
     return node->data;
 }
 
-inline void set_data(Node *node, Data *data)
+static inline void set_data(Node *node, Data *data)
 {
     if (data != node->data) {
         if (node->data) free(node->data);
@@ -98,7 +98,7 @@ inline void set_data(Node *node, Data *d
     }
 }
 
-inline uint32_t key_hash(HTree *tree, Item* it)
+static inline uint32_t key_hash(HTree *tree, Item* it)
 {
     char buf[255];
     int n = dc_decode(tree->dc, buf, it->key, KEYLENGTH(it));
@@ -256,8 +256,7 @@ static void merge_node(HTree *tree, Node
     for (i=0; i<BUCKET_SIZE; i++){
         Data *data = get_data(child+i); 
         Item *it = data->head;
-        int count = (child+i)->count;
-        for (j=0; j < count; j++){
+        for (j=0; j < data->count; j++){
             if (it->ver > 0) {
                 add_item(tree, node, it, key_hash(tree, it), false);
             } // drop deleted items, ver < 0
@@ -315,7 +314,7 @@ static Item* get_item_hash(HTree* tree, 
     return r;
 }
 
-inline int hex2int(char b)
+static inline int hex2int(char b)
 {
     if (('0'<=b && b<='9') || ('a'<=b && b<='f')) {
         return (b>='a') ?  (b-'a'+10) : (b-'0');
@@ -690,7 +689,7 @@ void ht_destroy(HTree *tree)
     free(tree);
 }
 
-inline uint32_t keyhash(const char *s, int len)
+static inline uint32_t keyhash(const char *s, int len)
 {
     return fnv1a(s, len);
 }
