--- texk/web2c/tex.ch.orig	Sat May  1 07:34:40 1999
+++ texk/web2c/tex.ch	Tue Jan 11 11:43:50 2005
@@ -190,10 +190,10 @@
 @y
 @d file_name_size == maxint
 @d ssup_error_line = 255
-@d ssup_max_strings ==65535
+@d ssup_max_strings == 262143
 {Larger values may be used, but then the arrays consume much more memory.}
 @d ssup_trie_opcode == 65535
-@d ssup_trie_size == 65535
+@d ssup_trie_size == 262143
 
 @d ssup_hyph_size == 65535 {Changing this requires changing (un)dumping!}
 @d iinf_hyphen_size == 610 {Must be not less than |hyph_prime|!}
@@ -212,17 +212,17 @@
   {Use |mem_bot=0| for compilers which cannot decrement pointers.}
 @!hash_offset=514; {smallest index in hash array, i.e., |hash_base| }
   {Use |hash_offset=0| for compilers which cannot decrement pointers.}
-@!trie_op_size=1501; {space for ``opcodes'' in the hyphenation patterns;
+@!trie_op_size=35111; {space for ``opcodes'' in the hyphenation patterns;
   best if relatively prime to 313, 361, and 1009.}
-@!neg_trie_op_size=-1501; {for lower |trie_op_hash| array bound;
+@!neg_trie_op_size=-35111; {for lower |trie_op_hash| array bound;
   must be equal to |-trie_op_size|.}
 @!min_trie_op=0; {first possible trie op code for any language}
 @!max_trie_op=ssup_trie_opcode; {largest possible trie opcode for any language}
 @!pool_name=TEX_POOL_NAME; {this is configurable, for the sake of ML-\TeX}
   {string of length |file_name_size|; tells where the string pool appears}
 @#
-@!inf_main_memory = 2999;
-@!sup_main_memory = 8000000;
+@!inf_main_memory = 3000;
+@!sup_main_memory = 32000000;
 
 @!inf_trie_size = 8000;
 @!sup_trie_size = ssup_trie_size;
@@ -260,7 +260,7 @@
 @!inf_font_max = 50; {could be smaller, but why?}
 
 @!inf_pool_size = 32000;
-@!sup_pool_size = 10000000;
+@!sup_pool_size = 40000000;
 @!inf_pool_free = 1000;
 @!sup_pool_free = sup_pool_size;
 @!inf_string_vacancies = 8000;
