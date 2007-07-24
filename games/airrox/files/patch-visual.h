--- visual.h.orig	Fri Oct  8 09:22:08 2004
+++ visual.h	Sun Jul 22 14:04:49 2007
@@ -46,7 +46,7 @@
 
 	public:		
 		GLuint listaMesa;
-		int font;
+		long font;
 		int telaLargura;
 		int telaAltura;
 		int telaCheia;
@@ -70,7 +70,7 @@
 		int setarTelaCheia(void);
 		int aumentarResolucao(void);
 		int diminuirResolucao(void);
-		GLvoid matarJanela(GLvoid);
+		void matarJanela(void);
 		
 		void Escrita2D(void);
 		void EscreveString(float x, float y, void *font, const char *string);
