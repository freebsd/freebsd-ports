--- src/nivel.h	2005-06-24 13:00:26.000000000 -0500
+++ src/nivel.h	2013-03-24 00:23:03.000000000 -0500
@@ -34,7 +34,7 @@
 class nivel
 {
 	public:
-		void iniciar(juego *_pjuego, grafico *grafico, grafico *pfondos, SDL_Surface *fondo);
+		void iniciar(juego *_pjuego, grafico *grafico, class grafico *pfondos, SDL_Surface *fondo);
 		int avanzar_nivel(int salto = 1);
 		int reiniciar_nivel(void);
 		int get_dist_suelo(int x, int y, int max);
