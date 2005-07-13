--- jogo.cpp.orig	Sat Oct  9 10:35:22 2004
+++ jogo.cpp	Tue Jul 12 15:28:30 2005
@@ -45,7 +45,16 @@
 
 void Jogo::inicializacao()
 {
-	config = new Config("config.txt");
+	char *home, *pathtocfg, *cfgname = ".airrox";
+	int len1, len2;
+
+	home = getenv("HOME");
+	len1 = strlen(home);
+	len2 = strlen(cfgname);
+	pathtocfg = new char[len1 + len2];
+	sprintf(pathtocfg, "%s/%s", home, cfgname);
+
+	config = new Config(pathtocfg);
 	// parametros de configuracao
 	config->cria("TelaLargura", INT);
 	config->cria("TelaAltura", INT);
