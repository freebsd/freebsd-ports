Fix improper argument reference.
https://git.savannah.gnu.org/cgit/tar.git/commit/?id=2251317e3fe971fd34608cf312c8120141d8fce4

--- src/tar.c.orig	2021-01-17 15:26:53 UTC
+++ src/tar.c
@@ -2248,7 +2248,7 @@ parse_default_options (struct tar_args *args)
       if (argp_parse (&argp,
 		      ws.ws_offs + ws.ws_wordc,
 		      ws.ws_wordv,
-		      ARGP_IN_ORDER|ARGP_NO_EXIT, &idx, &args))
+		      ARGP_IN_ORDER|ARGP_NO_EXIT, &idx, args))
 	abort (); /* shouldn't happen */
       args->loc = save_loc_ptr;
       if (name_more_files ())
