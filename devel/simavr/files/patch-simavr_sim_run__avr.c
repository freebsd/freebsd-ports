--- simavr/sim/run_avr.c.orig	2018-01-10 10:05:15 UTC
+++ simavr/sim/run_avr.c
@@ -106,7 +106,7 @@ main(
 			display_usage(basename(argv[0]));
 		} else if (!strcmp(argv[pi], "-m") || !strcmp(argv[pi], "--mcu")) {
 			if (pi < argc-1)
-				strncpy(name, argv[++pi], sizeof(name));
+				snprintf(name, sizeof(name), "%s", argv[++pi]);
 			else
 				display_usage(basename(argv[0]));
 		} else if (!strcmp(argv[pi], "-f") || !strcmp(argv[pi], "--freq")) {
