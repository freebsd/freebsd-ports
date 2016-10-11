--- src/lib/openjp2/pi.c.orig	2016-09-14 00:01:22 UTC
+++ src/lib/openjp2/pi.c
@@ -1236,7 +1236,13 @@ opj_pi_iterator_t *opj_pi_create_decode(
 	l_current_pi = l_pi;
 
 	/* memory allocation for include */
-	l_current_pi->include = (OPJ_INT16*) opj_calloc((l_tcp->numlayers +1) * l_step_l, sizeof(OPJ_INT16));
+	/* prevent an integer overflow issue */
+	l_current_pi->include = 00;
+	if (l_step_l <= (SIZE_MAX / (l_tcp->numlayers + 1U)))
+	{
+		l_current_pi->include = (OPJ_INT16*) opj_calloc((l_tcp->numlayers +1) * l_step_l, sizeof(OPJ_INT16));
+	}
+
 	if
 		(!l_current_pi->include)
 	{
