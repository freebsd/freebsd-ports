#!/bin/sh -e
#
# Copyright (c) 2004 Oliver Eikemeier.  All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#
# 1. Redistributions of source code must retain the above copyright notice
#    this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# 3. Neither the name of the author nor the names of its contributors may be
#    used to endorse or promote products derived from this software without
#    specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
# INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
# AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
# COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
# NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
# THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# $FreeBSD$
#
# MAINTAINER=	eik@FreeBSD.org
#
# These variables are referenced and must be exported from the Makefile:
#
# CURDIR
# OBJDIR
# MASTERDIR
# OPTIONS_MASTER
# OPTIONS_OVERRIDE
# OPTIONS_FILE
# OPTIONS_CMD
# PKGNAME
#

# utilities

LOCALBASE="${LOCALBASE:-/usr/local}"

AWK=/usr/bin/awk
CAT=/bin/cat
CHMOD=/bin/chmod
CP=/bin/cp
CUT=/usr/bin/cut
DIALOG=/usr/bin/dialog
EXPR=/bin/expr
FETCH=/usr/bin/fetch
GREP=/usr/bin/grep
LS=/bin/ls
MKDIR='/bin/mkdir -p'
MKTEMP=/usr/bin/mktemp
MV=/bin/mv
REALPATH=/bin/realpath
RM=/bin/rm
SED=/usr/bin/sed
SETENV=/usr/bin/env
SORT=/usr/bin/sort
TR=/usr/bin/tr
WC=/usr/bin/wc

# global constants

### utility functions ###

###
# do_create generates default options for a master (or override) options files
###

do_create()
{
  local rc

  if [ -n "$OPTIONS_OVERRIDE" ]; then
    OVERRIDEFILE="$OPTIONS_DEFAULT"
  elif [ "$CURDIR" != `$REALPATH "$MASTERDIR"` ]; then
    if [ -f "$CURDIR/options" ]; then
      OVERRIDEFILE="$CURDIR/options"
    elif [ -n "$PKGNAMESUFFIX" -a -f "$MASTERDIR/options.${PKGNAMESUFFIX#-}" ]; then
      OVERRIDEFILE="$MASTERDIR/options.${PKGNAMESUFFIX#-}"
    else
      OVERRIDEFILE=
    fi
  else
    OVERRIDEFILE=
  fi

  if [ -n "$OPTIONS_MASTER" ]; then
    MASTERFILE="$OPTIONS_MASTER"
  elif [ -f "$MASTERDIR/options" ]; then
    MASTERFILE="$MASTERDIR/options"
  else
    echo ">> makeconfig: Can't find $MASTERDIR/options" >&2
    return 1
  fi

  if [ -n "$OVERRIDEFILE" ]; then
    SRCFILE="$OVERRIDEFILE"
  else
    SRCFILE="$MASTERFILE"
  fi

  if ! TMP_OPTIONS=`$MKTEMP -q "$SRCFILE.XXXXXX"`; then
    echo ">> makeconfig: Can't create temporary options file"
    return 1
  fi

  $SED -e '/^##/,$d' "$SRCFILE" > "$TMP_OPTIONS"

  echo "## AUTOMATICALLY GENERATED FILE - DO NOT CHANGE ANYTHING BELOW THIS LINE ##" >> "$TMP_OPTIONS"
  echo "# use \`make config' to edit the local configuration" >> "$TMP_OPTIONS"
  echo "# use \`make makeconfig' to edit the defaults (MAINTAINER only)" >> "$TMP_OPTIONS"
  echo >> "$TMP_OPTIONS"

  if $OPTIONS_CMD -p "default" -M "$MASTERFILE" -O "$OVERRIDEFILE" -o >> "$TMP_OPTIONS"; then
    $MV -f "$TMP_OPTIONS" "$SRCFILE"
    $CHMOD a+r "$SRCFILE"
  else
    $RM -f "$TMP_OPTIONS"
  fi
  
  return $rc
}

###
# do_delete removes a saved configuration
###

do_delete()
{
  local rc

  $RM -f "$OPTIONS_FILE"

  return $rc
}

###
# do_edit edits a custom configuration
###

do_edit()
{
  local rc

  OPTIONS_DIR="${OPTIONS_FILE%/*}"
  if [ ! -d "$OPTIONS_DIR" ] && ! $MKDIR "$OPTIONS_DIR"; then
    echo ">> config: Can't create $OPTIONS_DIR." 2>&1
    return 1
  fi

  if [ -n "$OPTIONS_OVERRIDE" ]; then
    OVERRIDE="$OPTIONS_DEFAULT"
  elif [ "$CURDIR" != `$REALPATH "$MASTERDIR"` ]; then
    if [ -f "$CURDIR/options" ]; then
      OVERRIDE="$CURDIR/options"
    elif [ -n "$PKGNAMESUFFIX" -a -f "$MASTERDIR/options.${PKGNAMESUFFIX#-}" ]; then
      OVERRIDE="$MASTERDIR/options.${PKGNAMESUFFIX#-}"
    else
      OVERRIDE=
    fi
  else
    OVERRIDE=
  fi

  if [ -n "$OPTIONS_MASTER" ]; then
    MASTER="$OPTIONS_MASTER"
  elif [ -f "$MASTERDIR/options" ]; then
    MASTER="$MASTERDIR/options"
  else
    echo ">> makeconfig: Can't find $MASTERDIR/options" >&2
    return 1
  fi

  TMP_OPTIONS=`$MKTEMP -t options`

  $OPTIONS_CMD -p "$PKGNAME" -M "$MASTER" -O "$OVERRIDE" -g "$OPTIONS_FILE" -e > "$TMP_OPTIONS"

  ${EDITOR:-/usr/bin/vi} "$TMP_OPTIONS"

  TMP_OPTIONS_FILE=`$MKTEMP -q "$OPTIONS_FILE.XXXXXX"`
  echo "## AUTOMATICALLY GENERATED FILE - DO NOT EDIT ##" > "$TMP_OPTIONS_FILE"
  $OPTIONS_CMD -p "$PKGNAME" -M "$MASTER" -O "$OVERRIDE" -g "$OPTIONS_FILE" -t "$TMP_OPTIONS" -o >> "$TMP_OPTIONS_FILE"
  $RM -f "$TMP_OPTIONS"

  $MV -f "$TMP_OPTIONS_FILE" "$OPTIONS_FILE"
  $CHMOD a+r "$OPTIONS_FILE"

  return $rc
}

###
# do_graphical displays a menu to generate a custom configuration
###

do_graphical()
{
  local rc

  if [ -n "$OPTIONS_OVERRIDE" ]; then
    OVERRIDE="$OPTIONS_DEFAULT"
  elif [ "$CURDIR" != `$REALPATH "$MASTERDIR"` ]; then
    if [ -f "$CURDIR/options" ]; then
      OVERRIDE="$CURDIR/options"
    elif [ -n "$PKGNAMESUFFIX" -a -f "$MASTERDIR/options.${PKGNAMESUFFIX#-}" ]; then
      OVERRIDE="$MASTERDIR/options.${PKGNAMESUFFIX#-}"
    else
      OVERRIDE=
    fi
  else
    OVERRIDE=
  fi

  if [ -n "$OPTIONS_MASTER" ]; then
    MASTER="$OPTIONS_MASTER"
  elif [ -f "$MASTERDIR/options" ]; then
    MASTER="$MASTERDIR/options"
  else
    echo ">> makeconfig: Can't find $MASTERDIR/options" >&2
    return 1
  fi

  TMP_OPTIONS=`$MKTEMP -t options`

  DIALOGRC=`$OPTIONS_CMD -p "$PKGNAME" -M "$MASTER" -O "$OVERRIDE" -g "$OPTIONS_FILE" -d`

  /bin/sh -c "$DIALOG --checklist \"Options for $PKGNAME\" 21 70 15 $DIALOGRC 2>\"$TMP_OPTIONS\""

  #TMP_OPTIONS_FILE=`$MKTEMP -q "$OPTIONS_FILE.XXXXXX"`
  #echo "## AUTOMATICALLY GENERATED FILE - DO NOT EDIT ##" > "$TMP_OPTIONS_FILE"
  #$OPTIONS_CMD -p "$PKGNAME" -M "$MASTER" -O "$OVERRIDE" -g "$OPTIONS_FILE" -t "$TMP_OPTIONS" -o >> "$TMP_OPTIONS_FILE"
  $CAT "$TMP_OPTIONS"

  $RM -f "$TMP_OPTIONS"
  #$MV -f "$TMP_OPTIONS_FILE" "$OPTIONS_FILE"

  return $rc
}

###
# do_list lists the current configuration
###

do_list()
{
  local rc

  return $rc
}

###
# main
###

opt_create=false
opt_delete=false
opt_edit=false
opt_graphical=false
opt_list=false

while getopts "cdegl" opt; do
  case "$opt" in
  c) opt_create=true;;
  d) opt_delete=true;;
  e) opt_edit=true;;
  g) opt_graphical=true;;
  l) opt_list=true;;
  ?) echo "Usage: $0 -cdegl"; exit 1;;
  esac
done

shift $(($OPTIND-1))

$opt_create &&
  { do_create || exit 1; }

$opt_delete &&
  { do_delete || exit 1; }

$opt_edit &&
  { do_edit || exit 1; }

$opt_graphical &&
  { do_graphical || exit 1; }

$opt_list &&
  { do_list || exit 1; }

exit 0
