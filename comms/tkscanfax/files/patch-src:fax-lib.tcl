*** fax-lib.tcl.orig	Thu May 23 19:49:44 2002
--- fax-lib.tcl	Thu May 23 19:53:24 2002
***************
*** 675,681 ****
          foreach dir {userdir texdir pbookdir tmpdir} {
              exec mkdir $fax($dir)
          }
!         exec echo -e "Misc\tMiscellaneous fax numbers" \
                    > $fax(pbookdir)/group.pbd
          exec touch $fax(pbookdir)/Misc.pbd
      }
--- 675,681 ----
          foreach dir {userdir texdir pbookdir tmpdir} {
              exec mkdir $fax($dir)
          }
!         exec printf "Misc\tMiscellaneous fax numbers" \
                    > $fax(pbookdir)/group.pbd
          exec touch $fax(pbookdir)/Misc.pbd
      }
