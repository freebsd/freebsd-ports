--- visual.cpp.orig	Fri Oct  8 09:22:08 2004
+++ visual.cpp	Sun Jul 22 14:04:48 2007
@@ -37,15 +37,15 @@
 Visual::Visual(Jogo *j, int telaLargura, int telaAltura, bool telaCheia, string telaTitulo) {
 	jogo = j;
 	
-	this->font = (int)GLUT_BITMAP_8_BY_13;
+	this->font = (long)GLUT_BITMAP_8_BY_13;
 	this->telaLargura = telaLargura;
 	this->telaAltura = telaAltura;
 	this->telaTitulo = telaTitulo.c_str();
 
-	Load3DS (&mesa,"../meshs/mesa.3ds");
-	Load3DS(&mallet,"../meshs/mallet.3ds");
-	Load3DS(&puck,"../meshs/puck.3ds");
-	Load3DS(&placar,"../meshs/placar.3ds");
+	Load3DS (&mesa,"/usr/local/share/airrox/meshs/mesa.3ds");
+	Load3DS(&mallet,"/usr/local/share/airrox/meshs/mallet.3ds");
+	Load3DS(&puck,"/usr/local/share/airrox/meshs/puck.3ds");
+	Load3DS(&placar,"/usr/local/share/airrox/meshs/placar.3ds");
 
 	criarJanela();	
 	setarVideo(telaLargura, telaAltura, telaCheia);
@@ -96,22 +96,22 @@
 	glEnable(GL_LIGHT0);
 	
 	/*TODO criar uma variavel Path de texturas e meshs*/
-	mesa.id_texture=LoadBitmap("../texturas/mesa.bmp");
-	mallet.id_texture=LoadBitmap("../texturas/mallet.bmp");
-    	puck.id_texture=LoadBitmap("../texturas/puck.bmp");
-	placar.id_texture=LoadBitmap("../texturas/placar.bmp");
+	mesa.id_texture=LoadBitmap("/usr/local/share/airrox/texturas/mesa.bmp");
+	mallet.id_texture=LoadBitmap("/usr/local/share/airrox/texturas/mallet.bmp");
+    	puck.id_texture=LoadBitmap("/usr/local/share/airrox/texturas/puck.bmp");
+	placar.id_texture=LoadBitmap("/usr/local/share/airrox/texturas/placar.bmp");
 	
-	display[0]=LoadBitmap("../texturas/display0.bmp");
-	display[1]=LoadBitmap("../texturas/display1.bmp");
-	display[2]=LoadBitmap("../texturas/display2.bmp");
-	display[3]=LoadBitmap("../texturas/display3.bmp");
-	display[4]=LoadBitmap("../texturas/display4.bmp");
-	display[5]=LoadBitmap("../texturas/display5.bmp");
-	display[6]=LoadBitmap("../texturas/display6.bmp");
-	display[7]=LoadBitmap("../texturas/display7.bmp");
-	//display[8]=LoadBitmap("../texturas/display8.bmp");
-	//display[9]=LoadBitmap("../texturas/display9.bmp");
-	logomesa=LoadBitmap("../texturas/logomesa.bmp");
+	display[0]=LoadBitmap("/usr/local/share/airrox/texturas/display0.bmp");
+	display[1]=LoadBitmap("/usr/local/share/airrox/texturas/display1.bmp");
+	display[2]=LoadBitmap("/usr/local/share/airrox/texturas/display2.bmp");
+	display[3]=LoadBitmap("/usr/local/share/airrox/texturas/display3.bmp");
+	display[4]=LoadBitmap("/usr/local/share/airrox/texturas/display4.bmp");
+	display[5]=LoadBitmap("/usr/local/share/airrox/texturas/display5.bmp");
+	display[6]=LoadBitmap("/usr/local/share/airrox/texturas/display6.bmp");
+	display[7]=LoadBitmap("/usr/local/share/airrox/texturas/display7.bmp");
+	//display[8]=LoadBitmap("/usr/local/share/airrox/texturas/display8.bmp");
+	//display[9]=LoadBitmap("/usr/local/share/airrox/texturas/display9.bmp");
+	logomesa=LoadBitmap("/usr/local/share/airrox/texturas/logomesa.bmp");
 
 	/*TODO Criar metodo pra fazer isso abaixo */
 	if (mesa.id_texture==-1) {
@@ -165,7 +165,7 @@
 
 	//telaBpp = telaInfo->vfmt->BitsPerPixel;
 
-	SDL_WM_SetIcon(SDL_LoadBMP("../icones/airrox.bmp"), NULL);
+	SDL_WM_SetIcon(SDL_LoadBMP("/usr/local/share/airrox/icones/airrox.bmp"), NULL);
 	SDL_WM_SetCaption(this->telaTitulo.c_str(),NULL);
 
 	return 1;
@@ -219,7 +219,7 @@
 	return 1;
 }
 
-GLvoid Visual::matarJanela(GLvoid) {}
+void Visual::matarJanela(void) {}
 
 /**************** Metodos auxiliares ***********************************/
 
