/* ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc
 *
 *    Copyright c 1988 The Board of Trustees of the Leland Stanford
 *    Junior University. All rights reserved.  This routine may not
 *    be used without the prior written consent of Stanford University.
 *
 * ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc
 */

/*  XTIMER - return cpu time usage. */

/* =======================================================================
 * "XTIMER" - Return current (user) cpu time (in seconds) usage.
 *
 *  Usage:
 *     subroutine xdate(tim)
 *       real tim		- user seconds of cpu used.
 *
 *  Original: Michael Eldredge -- Stanford University (may 88)
 *
 * -----------------------------------------------------------------------
 */

#include <sys/types.h>
#include <sys/times.h>


/*CENTRY*/
void
xtimer_(tim)
	float*	tim ;
	{

	float	x ;
	struct tms t ;
	clock_t times() ;

	(void)times(&t) ;
	x = (float)t.tms_utime / 60.0 ;

	*tim = x ;
	}
/*ENDCENTRY*/
