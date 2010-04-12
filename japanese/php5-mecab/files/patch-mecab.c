--- ./mecab.c.orig	2010-04-12 16:37:55.000000000 -0400
+++ ./mecab.c	2010-04-12 16:38:00.000000000 -0400
@@ -347,19 +347,16 @@
 /* {{{ argument informations */
 #ifdef ZEND_BEGIN_ARG_INFO
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_mecab__mecab, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
 	ZEND_ARG_INFO(0, mecab)
 ZEND_END_ARG_INFO()
 
 #ifdef IS_UNICODE
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_mecab_set_encoding, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
 	ZEND_ARG_INFO(0, encoding)
 ZEND_END_ARG_INFO()
 #endif
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_mecab_split, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
 	ZEND_ARG_INFO(0, str)
 	ZEND_ARG_INFO(0, dicdir)
@@ -368,59 +365,49 @@
 	ZEND_ARG_INFO(0, persistent)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_mecab_new, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 0)
 	ZEND_ARG_ARRAY_INFO(0, arg, 1)
 	ZEND_ARG_INFO(0, persistent)
 ZEND_END_ARG_INFO()
 
 #if PHP_MECAB_VERSION_NUMBER >= 97
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_mecab_set_partial, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
 	ZEND_ARG_INFO(0, mecab)
 	ZEND_ARG_INFO(0, partial)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_mecab_set_partial_m, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 0)
 	ZEND_ARG_INFO(0, partial)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_mecab_set_theta, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
 	ZEND_ARG_INFO(0, mecab)
 	ZEND_ARG_INFO(0, theta)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_mecab_set_theta_m, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 0)
 	ZEND_ARG_INFO(0, theta)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_mecab_set_lattice_level, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
 	ZEND_ARG_INFO(0, mecab)
 	ZEND_ARG_INFO(0, level)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_mecab_set_lattice_level_m, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 0)
 	ZEND_ARG_INFO(0, level)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_mecab_set_all_morphs, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
 	ZEND_ARG_INFO(0, mecab)
 	ZEND_ARG_INFO(0, all_morphs)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_mecab_set_all_morphs_m, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 0)
 	ZEND_ARG_INFO(0, all_morphs)
 ZEND_END_ARG_INFO()
 #endif /* MeCab 0.97 or later */
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_mecab_sparse_tostr, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 2)
 	ZEND_ARG_INFO(0, mecab)
 	ZEND_ARG_INFO(0, str)
@@ -428,27 +415,23 @@
 	ZEND_ARG_INFO(0, olen)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_mecab_sparse_tostr_m, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
 	ZEND_ARG_INFO(0, str)
 	ZEND_ARG_INFO(0, len)
 	ZEND_ARG_INFO(0, olen)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_mecab_sparse_tonode, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 2)
 	ZEND_ARG_INFO(0, mecab)
 	ZEND_ARG_INFO(0, str)
 	ZEND_ARG_INFO(0, len)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_mecab_sparse_tonode_m, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
 	ZEND_ARG_INFO(0, str)
 	ZEND_ARG_INFO(0, len)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_mecab_nbest_sparse_tostr, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 3)
 	ZEND_ARG_INFO(0, mecab)
 	ZEND_ARG_INFO(0, n)
@@ -457,7 +440,6 @@
 	ZEND_ARG_INFO(0, olen)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_mecab_nbest_sparse_tostr_m, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 2)
 	ZEND_ARG_INFO(0, n)
 	ZEND_ARG_INFO(0, str)
@@ -465,79 +447,65 @@
 	ZEND_ARG_INFO(0, olen)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_mecab_nbest_init, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 2)
 	ZEND_ARG_INFO(0, mecab)
 	ZEND_ARG_INFO(0, str)
 	ZEND_ARG_INFO(0, len)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_mecab_nbest_init_m, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
 	ZEND_ARG_INFO(0, str)
 	ZEND_ARG_INFO(0, len)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_mecab_nbest_next_tostr, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
 	ZEND_ARG_INFO(0, mecab)
 	ZEND_ARG_INFO(0, olen)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_mecab_nbest_next_tostr_m, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 0)
 	ZEND_ARG_INFO(0, olen)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_mecab_format_node, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
 	ZEND_ARG_INFO(0, mecab)
 	ZEND_ARG_INFO(0, node)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_mecab_format_node_m, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
 	ZEND_ARG_OBJ_INFO(0, node, MeCab_Node, 0)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_mecab_node__node, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
 	ZEND_ARG_INFO(0, node)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_mecab_node_toarray, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
 	ZEND_ARG_INFO(0, node)
 	ZEND_ARG_INFO(0, dump_all)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_mecab_node_toarray_m, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 0)
 	ZEND_ARG_INFO(0, dump_all)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_mecab_node__list, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
 	ZEND_ARG_INFO(0, node)
 	ZEND_ARG_INFO(0, index)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_mecab_node__list_m, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
 	ZEND_ARG_INFO(0, index)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_mecab_node_settraverse, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
 	ZEND_ARG_INFO(0, traverse)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_mecab_path__path, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
 	ZEND_ARG_INFO(0, path)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_mecab__magic_getter, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
 	ZEND_ARG_INFO(0, name)
 ZEND_END_ARG_INFO()
