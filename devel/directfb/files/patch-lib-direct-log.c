--- lib/direct/log.c.orig	2012-05-23 13:43:12 UTC
+++ lib/direct/log.c
@@ -335,12 +335,14 @@ parse_host_addr( const char       *hostp
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
