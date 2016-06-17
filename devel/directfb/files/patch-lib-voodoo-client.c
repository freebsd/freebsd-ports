--- lib/voodoo/client.c.orig	2012-05-23 13:43:12 UTC
+++ lib/voodoo/client.c
@@ -164,12 +164,14 @@ voodoo_client_create( const char     *ho
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
