*** osdef.sh.orig	Sun Jun 11 23:36:49 2000
--- osdef.sh	Tue Apr  9 20:28:37 2002
***************
*** 47,56 ****
  # start of the line is matched with "[)*, 	]\1[ 	(]"
  sed < osdef0.cc -e '/\(..*\)/s// \1/' > osdef0.ccc
  
! sed < $srcdir/osdef1.h.in -n -e '/^extern/s@.*[)* 	][)* 	]*\([a-zA-Z_][a-zA-Z0-9_]*\) __ARGS.*@/[)*, 	]\1[ 	(]/i\\\
  \\/\\[^a-zA-Z_\\]\1 __ARGS\\/d@p' > osdef11.sed
  
! sed < $srcdir/osdef2.h.in -n -e '/^extern/s@.*[)* 	][)* 	]*\([a-zA-Z_][a-zA-Z0-9_]*\) __ARGS.*@/[)*, 	]\1[ 	(]/i\\\
  \\/\\[^a-zA-Z_\\]\1 __ARGS\\/d@p' > osdef21.sed
  
  cat << EOF > osdef2.sed
--- 47,56 ----
  # start of the line is matched with "[)*, 	]\1[ 	(]"
  sed < osdef0.cc -e '/\(..*\)/s// \1/' > osdef0.ccc
  
! sed < $srcdir/osdef1.h.in -n -e '/^extern/s@.*[)* 	][)* 	]*\([a-zA-Z_][a-zA-Z0-9_]*\) __ARGS.*@/[)*, 	][(]*\1[)]*[ 	(]/i\\\
  \\/\\[^a-zA-Z_\\]\1 __ARGS\\/d@p' > osdef11.sed
  
! sed < $srcdir/osdef2.h.in -n -e '/^extern/s@.*[)* 	][)* 	]*\([a-zA-Z_][a-zA-Z0-9_]*\) __ARGS.*@/[)*, 	][(]*\1[)]*[ 	(]/i\\\
  \\/\\[^a-zA-Z_\\]\1 __ARGS\\/d@p' > osdef21.sed
  
  cat << EOF > osdef2.sed

