--- ./lib/direct/log.c.orig	2010-11-15 22:12:08.000000000 +0100
+++ ./lib/direct/log.c	2010-12-03 16:44:12.000000000 +0100
@@ -335,12 +335,14 @@
                     D_ERROR( "Direct/Log: Port %s is unreachable!\n", portstr );
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
