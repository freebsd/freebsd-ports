--- ./conexao.h.orig	Tue Sep 28 20:48:00 2004
+++ ./conexao.h	Tue Mar 27 14:57:10 2007
@@ -46,7 +46,7 @@
 
 	
 		Conexao(Jogo *j);
-		Conexao::~Conexao();
+		~Conexao();
 		void servidor(int porta, void (*eventos) (void *,void*));
 		void cliente(string enderecoservidor, int porta, void (*eventos) (void *,void *));
 		void limparMsg();
