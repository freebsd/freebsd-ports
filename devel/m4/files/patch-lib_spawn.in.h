2010-03-02  Bruno Haible  <bruno@clisp.org>

	spawn: Don't override the system defined values on FreeBSD 8.
	* lib/spawn.in.h (POSIX_SPAWN_RESETIDS, POSIX_SPAWN_SETPGROUP,
	POSIX_SPAWN_SETSIGDEF, POSIX_SPAWN_SETSIGMASK,
	POSIX_SPAWN_SETSCHEDPARAM, POSIX_SPAWN_SETSCHEDULER): Don't redefine
	if HAVE_POSIX_SPAWN is 1.
	Reported by Johan van Selst <johans@stack.nl> via Eric Blake.

*** lib/spawn.in.h.orig	Tue Mar  2 11:53:02 2010
--- lib/spawn.in.h	Tue Mar  2 11:48:54 2010
***************
*** 110,126 ****
  
  
  /* Flags to be set in the `posix_spawnattr_t'.  */
! #if @REPLACE_POSIX_SPAWN@
  /* Use the values from the system, for better compatibility.  */
  /* But this implementation does not support AIX extensions.  */
! # undef POSIX_SPAWN_FORK_HANDLERS
! #else
! # define POSIX_SPAWN_RESETIDS           0x01
! # define POSIX_SPAWN_SETPGROUP          0x02
! # define POSIX_SPAWN_SETSIGDEF          0x04
! # define POSIX_SPAWN_SETSIGMASK         0x08
! # define POSIX_SPAWN_SETSCHEDPARAM      0x10
! # define POSIX_SPAWN_SETSCHEDULER       0x20
  #endif
  /* A GNU extension.  Use the next free bit position.  */
  #define POSIX_SPAWN_USEVFORK \
--- 110,128 ----
  
  
  /* Flags to be set in the `posix_spawnattr_t'.  */
! #if !@HAVE_POSIX_SPAWN@
! # if @REPLACE_POSIX_SPAWN@
  /* Use the values from the system, for better compatibility.  */
  /* But this implementation does not support AIX extensions.  */
! #  undef POSIX_SPAWN_FORK_HANDLERS
! # else
! #  define POSIX_SPAWN_RESETIDS           0x01
! #  define POSIX_SPAWN_SETPGROUP          0x02
! #  define POSIX_SPAWN_SETSIGDEF          0x04
! #  define POSIX_SPAWN_SETSIGMASK         0x08
! #  define POSIX_SPAWN_SETSCHEDPARAM      0x10
! #  define POSIX_SPAWN_SETSCHEDULER       0x20
! # endif
  #endif
  /* A GNU extension.  Use the next free bit position.  */
  #define POSIX_SPAWN_USEVFORK \
