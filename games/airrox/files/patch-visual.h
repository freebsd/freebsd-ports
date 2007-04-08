--- ./visual.h.orig	Tue Mar 27 14:57:10 2007
+++ ./visual.h	Tue Mar 27 15:00:26 2007
@@ -70,7 +70,7 @@
 		int setarTelaCheia(void);
 		int aumentarResolucao(void);
 		int diminuirResolucao(void);
-		GLvoid matarJanela(GLvoid);
+		void matarJanela(void);
 		
 		void Escrita2D(void);
 		void EscreveString(float x, float y, void *font, const char *string);
