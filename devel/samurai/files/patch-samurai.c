Stub out -w which is used by gyp when building Chromium to pass
dupbuild=err to ninja.

samuari treats multiple build lines for a target and cycles as an error
by default.

--- samurai.c.orig	2018-04-30 05:02:22 UTC
+++ samurai.c
@@ -133,6 +133,9 @@ main(int argc, char *argv[])
 	case 'v':
 		buildopts.verbose = true;
 		break;
+	case 'w':
+		EARGF(usage());
+		break;
 	default:
 		usage();
 	} ARGEND
