$OpenBSD: patch-src_os_unix_pa_unix_hostapis_c,v 1.2 2013/03/12 00:59:50 brad Exp $

Difference to OpenBSD patch: PA_USE_SNDIO has been moved before
PA_USE_OSS, so that portaudio prefers the sndio output.

--- src/os/unix/pa_unix_hostapis.c.orig	2016-06-22 08:28:31 UTC
+++ src/os/unix/pa_unix_hostapis.c
@@ -44,6 +44,7 @@
 
 PaError PaJack_Initialize( PaUtilHostApiRepresentation **hostApi, PaHostApiIndex index );
 PaError PaAlsa_Initialize( PaUtilHostApiRepresentation **hostApi, PaHostApiIndex index );
+PaError PaSndio_Initialize( PaUtilHostApiRepresentation **hostApi, PaHostApiIndex index );
 PaError PaOSS_Initialize( PaUtilHostApiRepresentation **hostApi, PaHostApiIndex index );
 /* Added for IRIX, Pieter, oct 2, 2003: */
 PaError PaSGI_Initialize( PaUtilHostApiRepresentation **hostApi, PaHostApiIndex index );
@@ -69,6 +70,10 @@ PaUtilHostApiInitializer *paHostApiIniti
 
 #else   /* __linux__ */
 
+#ifdef PA_USE_SNDIO
+	PaSndio_Initialize,
+#endif
+
 #if PA_USE_OSS
         PaOSS_Initialize,
 #endif
