--- io_lib/tokenise_name3.c.orig	2018-10-18 16:21:37 UTC
+++ io_lib/tokenise_name3.c
@@ -457,13 +457,13 @@ static int encode_token_diff(name_context *ctx, uint32
 
 //-----------------------------------------------------------------------------
 // Trie implementation for tracking common name prefixes.
-typedef struct trie {
+struct trie {
     char c;
     int count;
     //struct trie *next[128];
     struct trie *next, *sibling;
     int n; // Nth line
-} trie_t;
+};
 
 //static trie_t *t_head = NULL;
 
