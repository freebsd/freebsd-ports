#!/bin/sh

# $FreeBSD$

# dialog wrapper script

AWK="/usr/bin/awk"
DIALOG="/usr/bin/dialog"
ECHO="/bin/echo"
SED="/usr/bin/sed"
STTY="/bin/stty"

# get terminal size
size=$( ${STTY} size )
visheight="${size%%[$IFS]*}"
visheight=$(($visheight-3))
listheight=$(($visheight-6))
viswidth="${size#*[$IFS]}"
viswidth=$(($viswidth-10))
descwidth=$(($viswidth-22))

# test for a minimum version of dialog(1)
DIALOG_VER="0"
DIALOG_MIN="1.1-20100428"
dialogout=$( ${DIALOG} --print-version 2>&1 )
if [ $? -eq 0 ]; then
  DIALOG_VER=$( ${ECHO} "$dialogout" | ${SED} -e 's/^[^0-9]*//' )
  # only newer versions of dialog have --item-help
  HAS_ITEM_HELP="1"
fi

# escape the menu title
TITLE=$( ${AWK} -v title="$2" \
	'BEGIN { gsub(/'\''/, "'\''\\'\'\''", title); print title }' )

cmdstr=""
[ "${HAS_ITEM_HELP}" ] && cmdstr="--item-help"
cmdstr="$cmdstr $1 '$2' $visheight $viswidth $listheight"
shift 5

menulist=$(
  varlist=
  _maxvarlen=0
  while [ $# -gt 0 ]; do
    var="$1"
    [ ${#var} -gt $_maxvarlen ] && export _maxvarlen=${#var}
    varlist="$varlist${varlist:+
}$var"
    # build hashed environment variables
    export _${var}_desc="$2"
    export _${var}_val="$3"
    shift 3
  done
  ${ECHO} "$varlist" \
  | ${AWK} -v hasitemhelp="${HAS_ITEM_HELP}" -v viswid="$viswidth" '
  {
    var  = $1
    desc = ENVIRON["_" var "_desc"]
    val  = ENVIRON["_" var "_val"]
    descwid = viswid -(ENVIRON["_maxvarlen"] + 12)
    extdesc = ""
    if ( length(desc) > descwid ) {
      extdesc = substr(desc, descwid)
      gsub(/'\''/, "'\''\\'\'\''", extdesc)
      desc = substr(desc, 1, descwid - 1) "+"
    }
    gsub(/'\''/, "'\''\\'\'\''", desc)
    printf "'\''%s'\'' '\''%s'\'' '\''%s'\''", var, desc, val
    if ( hasitemhelp ) printf " '\''%s'\''", extdesc
    printf "\n"
  } '
)

eval ${DIALOG} $cmdstr $menulist
status="$?"
echo
exit $status
