--- main/gui_gtk/main_gtk.c.orig	Tue Aug 10 22:44:44 2004
+++ main/gui_gtk/main_gtk.c	Tue Aug 10 22:54:47 2004
@@ -1783,16 +1783,19 @@
 			printf( "SIGSEGV in core thread caught:\n" );
 			printf( "\terrno = %d (%s)\n", info->si_errno, strerror( info->si_errno ) );
 			printf( "\taddress = 0x%08X\n", (unsigned int)info->si_addr );
+#ifdef SEGV_MAPERR
 			switch( info->si_code )
 			{
 			case SEGV_MAPERR: printf( "                address not mapped to object\n" ); break;
 			case SEGV_ACCERR: printf( "                invalid permissions for mapped object\n" ); break;
 			}
+#endif
 			break;
 		case SIGILL:
 			printf( "SIGILL in core thread caught:\n" );
 			printf( "\terrno = %d (%s)\n", info->si_errno, strerror( info->si_errno ) );
 			printf( "\taddress = 0x%08X\n", (unsigned int)info->si_addr );
+#ifdef ILL_ILLOPC
 			switch( info->si_code )
 			{
 			case ILL_ILLOPC: printf( "\tillegal opcode\n" ); break;
@@ -1804,6 +1807,7 @@
 			case ILL_COPROC: printf( "\tcoprocessor error\n" ); break;
 			case ILL_BADSTK: printf( "\tinternal stack error\n" ); break;
 			}
+#endif
 			break;
 		case SIGFPE:
 			printf( "SIGFPE in core thread caught:\n" );
