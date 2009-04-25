*** test/test23.sc.orig	Mon Feb 22 11:27:23 1993
--- test/test23.sc	Sat Mar 14 22:05:08 2009
***************
*** 330,338 ****
  
  ;;; Access to an external array.
  
! (define-c-external _\i\o\b* ARRAY "_iob")
! (eval-when (load) (define _iob _\i\o\b*))
! (eval-when (eval) (define _iob 0))
  
  ;;; Access to an external procedure pointer.
  
--- 330,338 ----
  
  ;;; Access to an external array.
  
! ;(define-c-external _\i\o\b* ARRAY "_iob")
! ;(eval-when (load) (define _iob _\i\o\b*))
! ;(eval-when (eval) (define _iob 0))
  
  ;;; Access to an external procedure pointer.
  
***************
*** 409,415 ****
  
      (chk 130 (string-ref "" 0) (integer->char #o21))
  
!     (chk 140 (number? _iob) #t)
      (chk 141 (number? hypot) #t)
  
      (chk 150 (letrec ((x 1)) (define x 2) x) 2)
--- 409,415 ----
  
      (chk 130 (string-ref "" 0) (integer->char #o21))
  
!     ;(chk 140 (number? _iob) #t)
      (chk 141 (number? hypot) #t)
  
      (chk 150 (letrec ((x 1)) (define x 2) x) 2)
