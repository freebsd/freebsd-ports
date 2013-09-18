--- plee-the-bear/src/ptb/expr/impl/boolean_player_function.tpp.orig	2011-07-17 23:01:25.000000000 +0400
+++ plee-the-bear/src/ptb/expr/impl/boolean_player_function.tpp	2013-09-18 00:33:39.358695760 +0400
@@ -37,7 +37,7 @@
 template<typename FunctionType>
 ptb::boolean_player_function<FunctionType>::boolean_player_function
 ( unsigned int player_index, const bear::engine::level_globals* g )
-  : m_player_index(player_index), m_player(NULL), m_level_globals(g)
+  : m_player_index(player_index), m_player(), m_level_globals(g)
 {
   search_player();
 } // boolean_player_function::boolean_player_function()
