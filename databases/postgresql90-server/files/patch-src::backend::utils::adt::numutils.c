Index: src/backend/utils/adt/numutils.c
===================================================================
RCS file: /cvsroot/pgsql-server/src/backend/utils/adt/numutils.c,v
retrieving revision 1.54
diff -c -c -r1.54 numutils.c
*** src/backend/utils/adt/numutils.c	4 Sep 2002 20:31:28 -0000	1.54
--- src/backend/utils/adt/numutils.c	19 Dec 2002 17:10:56 -0000
***************
*** 70,76 ****
  	if (s == (char *) NULL)
  		elog(ERROR, "pg_atoi: NULL pointer");
  	else if (*s == 0)
! 		elog(ERROR, "pg_atoi: zero-length string");
  	else
  		l = strtol(s, &badp, 10);
  
--- 70,80 ----
  	if (s == (char *) NULL)
  		elog(ERROR, "pg_atoi: NULL pointer");
  	else if (*s == 0)
! 	{
! 		/* 7.3.X workaround for broken apps, bjm  2002-12-19 */
! 		elog(WARNING, "pg_atoi: zero-length string");
! 		l = (long) 0;
! 	}
  	else
  		l = strtol(s, &badp, 10);
  

