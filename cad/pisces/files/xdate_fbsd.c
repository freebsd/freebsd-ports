/* ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc
 *
 *     Copyright c 1988 The Board of Trustees of the Leland Stanford
 *     Junior University. All rights reserved.  This routine may not
 *     be used without the prior written consent of Stanford University.
 *
 *ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc
*/


/* XDATE, XTIME - return current date and current time strings */

/* ======================================================================
 * "XDATE": Return current date string.
 *
 *  Usage:
 *     call xdate(str)
 *  Notes:
 *     + Format is somewhat arbitrary; however, a good one is:
 *          "23 Sep 88"   "04 sep 88"   " 4 Sep 88"  "04-Sep-88"
 *       or 9 (or less) characters long.
 *     + In clock() the time and date strings are cat'ed together
 *       like: str = date // '  ' // time
 *       This resultant string MUST be 20 or less characters or
 *       saved solution files will not work (lodsol will always
 *       read and write 20 characters)
 *
 *  Original: Michael Eldredge -- Stanford University (may 88)
 *
 * -----------------------------------------------------------------------
 */

void
xdate_(str)
	char	str[] ;
	{

	int*	_stack_ = (int*)&str ;
	int	strLEN  = _stack_[1] ;
	int	i ;
	long	t = time(0) ;
	char*	dat ;

	char*	ctime() ;

/* -----------------------------------------------------------------------
 *..get the Unix ctime() string
 *....  1234 6789,1234 6789,1234 6789,
 *.... "Mon May 23 18:34:22 1988"
 */
	dat = ctime(&t) ;

/* reformat to our liking. */
       for (i = 0 ; i < strLEN; i) str[i++] = ' ' ;

       strncpy(&str[0], &dat[ 8], 2) ;	/* str(1: 2) = dat(9:10) */
       str[2] = '-' ;			/* str(3: 3) = '-' */
       strncpy(&str[3], &dat[ 4], 3) ;	/* str(4: 6) = dat( 5: 7) */
       str[6] = '-' ;			/* str(7: 7) = '-' */
       strncpy(&str[7], &dat[22], 2) ;	/* str(8: 9) = dat(23:24) */
       }
	

/* =====================================================================
 * "XTIME": Return current time of day string.
 *
 *  Usage:
 *     call xtime(str)
 *  Notes:
 *     + Format is somewhat arbitrary; however, a good one is:
 *	   23:04:56     23:04:00    11:04:56pm
 *       or 8 to 10 characters long (but no more than 10 - see note
 *       for XDATE.
 *
 *  Original: Michael Eldredge -- Stanford University (may 88)
 *
 * -----------------------------------------------------------------------
 */

void
xtime_(str)
	char	str[] ;
	{
	int*	_stack_ = (int*)&str ;
	int	strLEN = _stack_[1] ;
	int	i ;
	long	t = time(0) ;
	char*	tim ;

	char*	ctime() ;

	/* get the Unix ctime() string
	 *....  1234 6789,1234 6789,1234 6789,
	 *.... "Mon May 23 18:34:22 1988"
	 */
	tim = ctime(&t) ;

	/* reformat to our liking. */
	for (i = 0 ; i < strLEN; ) str[i++] = ' ' ;

	strncpy(str, &tim[11], 8) ;	/* str = tim(12:19) */
	}

