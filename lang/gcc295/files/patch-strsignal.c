--- libiberty/strsignal.c.orig	Fri May 15 16:42:42 1998
+++ libiberty/strsignal.c	Mon May  6 14:01:43 2002
@@ -244,7 +244,7 @@
 #else
 
 #ifdef NSIG
-static int sys_nsig = NSIG;
+static int Gsys_nsig = NSIG;
 #else
 #ifdef _NSIG
 static int sys_nsig = _NSIG;
@@ -330,7 +330,7 @@
       if ((sys_siglist = (const char **) malloc (nbytes)) != NULL)
 	{
 	  memset (sys_siglist, 0, nbytes);
-	  sys_nsig = num_signal_names;
+	  Gsys_nsig = num_signal_names;
 	  for (eip = signal_table; eip -> name != NULL; eip++)
 	    {
 	      sys_siglist[eip -> value] = eip -> msg;
@@ -379,7 +379,7 @@
     {
       init_signal_tables ();
     }
-  maxsize = MAX (sys_nsig, num_signal_names);
+  maxsize = MAX (Gsys_nsig, num_signal_names);
   return (maxsize - 1);
 }
 
@@ -432,7 +432,7 @@
 
 #endif
 
-  if ((signo < 0) || (signo >= sys_nsig))
+  if ((signo < 0) || (signo >= Gsys_nsig))
     {
       /* Out of range, just return NULL */
       msg = NULL;
@@ -591,7 +591,7 @@
     {
       init_signal_tables ();
     }
-  if ((signo <= 0) || (signo >= sys_nsig))
+  if ((signo <= 0) || (signo >= Gsys_nsig))
     {
       fprintf (stderr, "%s: unknown signal\n", message);
     }
@@ -621,7 +621,7 @@
 
   maxsigno = signo_max ();
   printf ("%d entries in names table.\n", num_signal_names);
-  printf ("%d entries in messages table.\n", sys_nsig);
+  printf ("%d entries in messages table.\n", Gsys_nsig);
   printf ("%d is max useful index.\n", maxsigno);
 
   /* Keep printing values until we get to the end of *both* tables, not
