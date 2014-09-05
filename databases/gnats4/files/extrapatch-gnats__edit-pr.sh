--- gnats/edit-pr.sh.orig	Sun May 26 16:32:02 2002
+++ gnats/edit-pr.sh	Sat Dec  6 02:43:44 2003
@@ -5,6 +5,8 @@
 # Contributed by Jeffrey Osier (jeffrey@cygnus.com).
 # Majorly revised by Bob Manson (manson@juniper.net).
 # Further improvements by Dirk Bergstrom (dirk@juniper.net).
+# Patches for the FreeBSD Project by Ceri Davies (ceri@FreeBSD.org),
+# based on work by Paul Richards (paul@FreeBSD.org).
 #
 # This file is part of GNU GNATS.
 #
@@ -24,9 +26,12 @@
 
 debug_print=false # or echo to get output.
 BINDIR=xBINDIRx
+DATE=`LC_TIME=C date`	# Some prstats tools rely on this format
+GNATS_ROOT=${GNATS_ROOT:-/usr/local/share/gnats/gnats-db}; export GNATS_ROOT
 LIBEXECDIR=xLIBEXECDIRx
 GNATS_PORT=
 locked=
+rc=0
 version=xVERSIONx
 
 usage="
@@ -99,28 +104,23 @@
 
      *)
        if [ "`echo $1 | grep /`" != "" ]; then
-         pr_id=`echo $1 | awk -F"/" '{print $2}' -`
+         pr=`echo $1 | awk -F"/" '{print $2}' -`
        else
-         pr_id=$1
+         pr=$1
        fi
+       prs="$prs $pr"
        ;;
    esac
    shift
 done
 
+chng_tpl="${GNATS_ROOT}/gnats-adm/edit-pr-msg"
+
 # set command here to always pass host and port, and directory if supplied
 QUERY_PR="$BINDIR/query-pr $GNATS_HOST $GNATS_PORT $GNATS_DB $EDIT_USER $EDIT_PASSWD"
 PR_ADDR="$QUERY_PR --responsible-address"
 PR_EDIT="$LIBEXECDIR/gnats/pr-edit $GNATS_HOST $GNATS_PORT $EDIT_USER $EDIT_PASSWD $GNATS_DB"
 
-# These traps take care of deleting all the /tmp files
-trap 'rm -f $new.old $change_msg $fixfil' 0
-# Don't delete $new on error signals
-trap 'if [ "$locked" != "" ]; then \
-        $PR_EDIT --unlock $pr_id ; \
-	locked= ; \
-      fi' 1 2 3 13 15
-
 # find a user name
 if [ "$USER" != "" ]; then
   me=$USER
@@ -138,85 +138,45 @@
   full_me="$me"
 fi
 
+for pr_id in $prs ; do
+
+epdir=`mktemp -d /tmp/epXXXXXX || exit 75`
+chng_msg="$epdir/chng.$pr_id.$$"
 # new = temp file to use for editing
-new="/tmp/ep$$"
-newtmp="/tmp/ep$$.tp"
-change_msg="/tmp/ep$$.ch"
-fixfil="/tmp/ep$$.fx"
+new="$epdir/$pr_id.ep$$"
+change_msg="$epdir/ep$$.$pr_id.ch"
+keepnew=
+
+# These traps take care of deleting all the /tmp files
+trap 'rm -f $new.old $change_msg chng_msg; rmdir $epdir 2>/dev/null' 0
+trap 'if [ "$locked" != "" ]; then \
+        $PR_EDIT --unlock $pr_id ; \
+	locked= ; \
+      fi; \
+      rm -f $new.old $change_msg chng_msg; rmdir $epdir 2>/dev/null' 1 2 3 13 15
+
 
 # lock the pr
 $debug_print "Locking $pr_id."
-lock=`$PR_EDIT --lock=$full_me --process=$$ $pr_id 2>&1 > $new`
+lock=`$PR_EDIT --lock=$me --process=$$ $pr_id 2>&1 > $new`
 locked=t
 
 if [ "$lock" != "" ] ; then
+  echo "Failed to lock PR $pr_id"
   echo $lock
-  exit 0
+  rc=1
+  rm -r $epdir
+  continue
 fi
 
-rm -f $fixfil
-
-# Now add any missing fields, along with a description.
-
-$QUERY_PR --list-fields | while read field
-do
-    grep -i "^>${field}:" "$new" > /dev/null 2>&1
-    if [ $? != 0 ]
-    then
-	$QUERY_PR --field-flags "$field" | grep -i readonly > /dev/null 2>&1
-	if [ $? != 0 ]
-	then
-	    type="`$QUERY_PR --field-type $field`"
-	    case $type in
-		[Ee][Nn][Uu][Mm])
-		    values=`$QUERY_PR --valid-values $field | tr '\n' ' ' | sed 's/ *$//g; s/ / | /g;s/^/[ /;s/$/ ]/;`
-		    valslen=`echo "$values" | wc -c`
-		    if [ "$valslen" -gt 160 ]
-		    then
-			desc="<`$QUERY_PR --field-description $field` (one line)>";
-		    else
-			desc="<${values} (one line)>";
-		    fi
-		    dpat=`echo "$desc" | tr '][*+^$|\()&/' '............'`
-		    echo "/^>${field}:/ s/${dpat}//" >> $fixfil
-		    echo "/>${field}: ${desc}" >> $new;
-		    ;;
-		[Mm][Uu][Ll][Tt][Ii][Tt][Ee][Xx][Tt])
-		    desc="	<`$QUERY_PR --field-description $field` (multiple lines)>";
-		    dpat=`echo "$desc" | tr '][*+^$|\()&/' '............'`
-		    echo "s/^${dpat}//" >> $fixfil
-		    echo ">${field}:" >> $new;
-		    echo "$desc" >> $new;
-		    ;;
-		*)
-		    desc="<`$QUERY_PR --field-description $field` (one line)>"
-		    dpat=`echo "$desc" | tr '][*+^$|\()&/' '............'`
-		    echo "/^>${field}:/ s/${dpat}//" >> $fixfil
-		    echo ">${field}: ${desc}" >> $new
-		    ;;
-	    esac
-	else
-	    prevfld="$field";
-	fi
-    fi
-done
-
 # here's where we actually call the editor.
 cp $new $new.old
 $VISUAL $new
 if cmp -s $new.old $new ; then
   echo "edit-pr: PR not changed"
   $PR_EDIT --unlock $pr_id
-  exit 0
-fi
-
-if [ -f $fixfil ]
-then
-    sed -f $fixfil < $new > $newtmp
-    mv $newtmp $new
-    sed -f $fixfil < $new.old > $newtmp
-    mv $newtmp $new.old
-    rm -f $fixfil
+  rm -r $epdir
+  continue
 fi
 
 # error-check output by calling pr-edit --check; if mistakes exist,
@@ -233,7 +193,7 @@
         echo "PR $pr_id not updated: changed file is in $new.changed"
         mv $new $new.changed
 	$PR_EDIT --unlock $pr_id
-        exit 0
+        continue 2
         ;;
     esac
     $VISUAL $new
@@ -242,24 +202,37 @@
   fi
 done
 
-exec 3<&0
-
 #
 # Find out what fields have changed; if the changed field requires a
 # change reason, then ask about it.
 #
-$LIBEXECDIR/gnats/diff-prs $new.old $new | while read field
+
+changed_fields=`$LIBEXECDIR/gnats/diff-prs $new.old $new`
+for field in $changed_fields
 do
     flags=`$QUERY_PR --field-flags $field` || echo "edit-pr: Invalid field name $field" 1>&2;
 
     if echo "$flags" | grep -i "requirechangereason" > /dev/null 2>&1
     then
-        echo ">${field}-Changed-Why:" >> $change_msg;
-	echo "Why did the $field field change? (Ctrl-D to end)";
-	cat 0<&3  >> $change_msg;
+	$debug_print "Doing $field change."
+	echo ">$field-Changed-Why: " >> $change_msg
+	if [ -e $chng_msg ]; then
+	    echo "Re-use last message (y/n)?"
+	    read yesno
+	    if [ "$yesno" != "y" ]; then
+		sed "s/%%ITEM%%/$field/" $chng_tpl > $chng_msg
+	    fi
+	else
+	    sed "s/%%ITEM%%/$field/" $chng_tpl > $chng_msg
+	fi
+	$VISUAL $chng_msg
+	sed '/^GNATS:/d' $chng_msg >> $change_msg
     fi
 done
 
+echo "" >> $change_msg
+echo "http://www.FreeBSD.org/cgi/query-pr.cgi?pr=$pr_id" >> $change_msg
+
 if [ -f $change_msg ]
 then
     cat $change_msg >> $new
@@ -269,12 +242,12 @@
 # Submit the changed PR.
 #
 while true; do
-    if $PR_EDIT --email-addr "$full_me" $pr_id < $new
+    if $PR_EDIT --email-addr "$me" $pr_id < $new
     then
 	echo "Edit successful"
 	# we need to unlock the PR
 	$PR_EDIT --unlock $pr_id
-	exit 0
+	break
     else
 	echo "Problems with edit submission."
     fi
@@ -284,9 +257,11 @@
 	case "$input" in
 	    a*)
 		echo "Cancelling edit.  Changed PR is in $new."
-		# we need to ulock the PR no matter what
+		# we need to unlock the PR no matter what
 		$PR_EDIT --unlock $pr_id
-		exit 1 ;;
+		keepnew=y
+		rc=1
+		break 2 ;;
 	    r*)
 		break ;;
 	     *)
@@ -296,6 +271,13 @@
     done
 done
 
-rm -f $new
+rm -f $chng_msg $new.old $change_msg
+if [ "$keepnew" != "y" ]; then
+    rm -f $new
+    rmdir $epdir
+fi
+keepnew=
+
+done		# for pr_id in $prs
 
-exit 0
+exit $rc
