*** faxIt.t.org	Thu Jan 16 21:08:00 2003
--- faxIt.t	Thu Jan 16 21:10:58 2003
***************
*** 66,80 ****
  	          $Th_Info(notifyOnRetry)
  
      if {[string length $Th_Info(name)]} {
-         # This MUST appear.
- 	regsub -all {["'$\\]} $Th_Info(name) {\\&} name
-         append options " -d \"$name@$Th_Info(phone)\""
- 
          # Make an ID string for later usage
  	regsub -all {["'$\\]} $Th_Info(company) {\\&} company
          append options " -i \"$name@$company\"" 
      } else {
!         # This MUST appear.
          append options " -d $Th_Info(phone)"
      }
  
--- 66,80 ----
  	          $Th_Info(notifyOnRetry)
  
      if {[string length $Th_Info(name)]} {
  	# Make an ID string for later usage
+ 	regsub -all {["'$\\]} $Th_Info(name) {\\&} name
            regsub -all {["'$\\]} $Th_Info(company) {\\&} company
  	append options " -i \"$name@$company\""
+ 
+ 	# This MUST appear last.
+ 	append options " -d \"$name@$Th_Info(phone)\""
      } else {
! 	# This MUST appear last.
  	append options " -d $Th_Info(phone)"
      }
  
