--- lib/voodoo/client.c
+++ lib/voodoo/client.c
@@ -97,10 +97,12 @@ voodoo_client_create( const char     *hostname,
                     D_ERROR( "Direct/Log: Port 2323 is unreachable!\n" );
                     return DR_FAILURE;
                
+/*
                case EAI_ADDRFAMILY:
                case EAI_NODATA:
                     D_ERROR( "Direct/Log: Host found, but has no address!\n" );
                     return DR_FAILURE;
+*/
                     
                case EAI_MEMORY:
                     return D_OOM();
