*** psgml-parse.el.orig	Sun Mar  6 01:23:40 2005
--- psgml-parse.el	Wed Jun  8 12:47:33 2005
***************
*** 568,574 ****
        (setq s1 (car l)
  	    allfinal (and allfinal (sgml-state-final-p s1))
  	    s2 (sgml-get-move s1 token)
! 	    res (and s2 (sgml-make-and-state s2 (remq s1 dfas) next))
  	    l (cdr l)))
      (cond (res)
  	  (allfinal (sgml-get-move next token)))))
--- 568,580 ----
        (setq s1 (car l)
  	    allfinal (and allfinal (sgml-state-final-p s1))
  	    s2 (sgml-get-move s1 token)
! 	    res (and s2
! 		     (sgml-make-and-state
! 		      s2
! 		      (if (memq s1 dfas)
! 			  (delq s1 (copy-sequence dfas))
! 			dfas)
! 		      next))
  	    l (cdr l)))
      (cond (res)
  	  (allfinal (sgml-get-move next token)))))
