--- src/modules/perlapi/perlapi.c.orig	2002-02-14 21:07:31 UTC
+++ src/modules/perlapi/perlapi.c
@@ -36,6 +36,7 @@ static void xs_init() {
 /* extension module support */
 static void xs_init() {
 	char *file = __FILE__;
+	dTHX;
 
 	newXS("DynaLoader::boot_DynaLoader", boot_DynaLoader, file);
 	newXS("Led::bootstrap", boot_Led, file);
@@ -66,6 +67,7 @@ int perlapi_init() {
 	char *args[] = { "", "-e", "" };
 	char *bootargs[] = { "Led", 0 };
 	u_char *expath;
+	dTHX;
 
 	/* add perl commands to the editor */
 	command_addf("perl_eval", input_allocsyms(1), perlapi_doeval);
@@ -124,6 +126,7 @@ void perlapi_eval(u_char *string) {
 /* evaluate some perl */
 void perlapi_eval(u_char *string) {
 	SV *sv;
+	dTHX;
 
 	sv = newSVpv(string, 0);
 	perl_eval_sv(sv, G_DISCARD | G_NOARGS);
