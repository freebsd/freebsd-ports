--- ./lib/voodoo/client.c.orig	2010-11-15 22:13:05.000000000 +0100
+++ ./lib/voodoo/client.c	2010-12-03 16:44:12.000000000 +0100
@@ -161,12 +161,14 @@
                     D_ERROR( "Direct/Log: Service is unreachable!\n" );
                     return DR_FAILURE;
 
+/*
 #ifdef EAI_ADDRFAMILY
                case EAI_ADDRFAMILY:
 #endif
                case EAI_NODATA:
                     D_ERROR( "Direct/Log: Host found, but has no address!\n" );
                     return DR_FAILURE;
+*/
 
                case EAI_MEMORY:
                     return D_OOM();
