Index: trek/main.c
@@ -47,10 +47,12 @@
 
 # include	"trek.h"
 # include	<stdio.h>
-# include	<sgtty.h>
+# include 	<termios.h>
 # include	<setjmp.h>
 # include       <stdlib.h>
 
+# define gtty(_a,_b) tcgetattr(_a,_b)
+
 # define	PRIO		00	/* default priority */
 
 int	Mother	= 51 + (51 << 8);
@@ -163,7 +165,7 @@
 	int			prio;
 	int		ac;
 	char		**av;
-	struct	sgttyb		argp;
+	struct	termios		argp;
 
 	/* revoke */
 	setgid(getgid());
@@ -176,7 +178,7 @@
 	prio = PRIO;
 	if (gtty(1, &argp) == 0)
 	{
-		if ((argp.sg_ispeed ) < B1200)
+		if ((cfgetispeed(&argp)) < B1200)
 			Etc.fast++;
 	}
 	while (ac > 1 && av[0][0] == '-')
