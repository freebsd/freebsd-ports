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
# DISABLE_SIZE
# DISTFILES
# DISTINFO_ALGORITHMS
# DISTINFO_LABEL
# DIST_SUBDIR
# ECHO_MSG
# FETCH_AFTER_ARGS
# FETCH_BEFORE_ARGS
# FETCH_CMD
# FETCH_ENV
# FETCH_SYMLINK_DISTFILES
# IGNOREFILES
# LOCALBASE
# MASTER_SITES
# MASTER_SITE_BACKUP
# MASTER_SITE_OVERRIDE
# MASTER_SORT_AWK
# MASTER_SORT_CMD
# MASTER_SORT_ENV
# MK_FILE
# NO_SIZE
# PATCHFILES
# PATCH_SITES
# PERL5
# VALID_ALGORITHMS
#
# These variables are user settable:
#
# DISABLE_SIZE
# NO_CHECKSUM
# FETCH_REGET
#

# utilities

LOCALBASE="${LOCALBASE:-/usr/local}"

AWK=/usr/bin/awk
CAT=/bin/cat
CUT=/usr/bin/cut
EXPR=/bin/expr
FETCH=/usr/bin/fetch
GREP=/usr/bin/grep
LS=/bin/ls
MD5=/sbin/md5
MKDIR='/bin/mkdir -p'
MKTEMP=/usr/bin/mktemp
PERL5="${PERL5:-/usr/bin/perl}"
RM=/bin/rm
[ -x /sbin/rmd160 ] && RMD160=/sbin/rmd160
SED=/usr/bin/sed
SETENV=/usr/bin/env
[ -x /sbin/sha1 ] && SHA1=/sbin/sha1
SORT=/usr/bin/sort
TR=/usr/bin/tr
WC=/usr/bin/wc

if [ -x /usr/bin/openssl ]; then
  OPENSSL=/usr/bin/openssl
elif -x "$LOCALBASE/bin/openssl" ];then
  OPENSSL="$LOCALBASE/bin/openssl"
fi

# global constants

MK_FILE_ENDMARKER='^\.include[	 ]*(<bsd\.port(\.post)?\.mk>|"\${MASTERDIR}\/Makefile")$'

FETCH_REGET="${FETCH_REGET:-1}"

### utility functions ###

###
# do_hash is a wrapper for md5/openssl/digest to calculate MD5/SHA1/RMD160 hashes
###

do_hash()
{
  local alg
  alg="$1"
  shift

  case "$alg" in
  [Mm][Dd]5)
    if [ $# -eq 0 ]; then
      $MD5
    else
      $MD5 -- "$@"
    fi;;
  [Ss][Hh][Aa]1)
    if [ -n "$SHA1" ]; then
      echo $SHA1
      if [ $# -eq 0 ]; then
        $SHA1
      else
        $SHA1 -- "$@"
      fi
    else
      if [ $# -eq 0 ]; then
        "${OPENSSL:-true}" sha1
      else
        "${OPENSSL:-true}" sha1 ./"$@" |
          $SED -En -e 's/^[[:alnum:]]+ *\((\.\/)?(.*)\) *= *([[:xdigit:]]+)$/SHA1 (\2) = \3/p'
      fi
    fi;;
  [Rr][Mm][Dd]160)
    if [ -n "$RMD160" ]; then
      if [ $# -eq 0 ]; then
        $RMD160
      else
        $RMD160 -- "$@"
      fi
    else
      if [ $# -eq 0 ]; then
        "${OPENSSL:-true}" rmd160
      else
        "${OPENSSL:-true}" rmd160 ./"$@" |
          $SED -En -e 's/^[[:alnum:]]+ *\((\.\/)?(.*)\) *= *([[:xdigit:]]+)$/RMD160 (\2) = \3/p'
      fi
    fi;;
  [Ss][Ii][Zz][Ee])
    if [ $# -eq 0 ]; then
      $WC -c
    else
      while [ $# -gt 0 ]; do
        # avoid hassle with CLICOLOR_FORCE
        $LS -ALdfln -- "$1" | $AWK '{ print "SIZE ('"$1"') = " $5 }'
        shift
      done
    fi;;
  *)
    return 1;;
  esac
}

###
# extract_sum extracts all checksums for a file in distinfo
###

extract_sum()
{
  local algorithms pattern
  algorithms=`echo -n "$1" | $TR -s ' \t\n' '|'`
  pattern=`echo "$2$3" | $SED -e 's;[/.[\(*+?{|^$];\\\\&;g'`
  # distfiles match [a-zA-Z0-9.,_/@&%?=+-]+

  [ $# -eq 3 ] || return 1

  if [ -f "$MD5_FILE" ]; then
    $SED -En -e '/^('"$algorithms"') *\('"$pattern"'\) *= */s//\1=/p' "$MD5_FILE"
  elif $GREP -qs "^#:distinfo${DISTINFO_LABEL:+\.$DISTINFO_LABEL}$" "$MK_FILE"; then
    $SED -En -e '
      1,/'"$MK_FILE_ENDMARKER"'/d
      /^#/!q
      /^#:distinfo'"${DISTINFO_LABEL:+.$DISTINFO_LABEL}"'$/,/^#:/ {
        s/^#('"$algorithms"') *\('"$pattern"'\) *= */\1=/
        t match
        b nomatch
        :match
        H
        :nomatch
      }
      $ {
        g
        p
      }
    ' "$MK_FILE"
  else
    for alg in $1; do
      for sum in `eval echo \\$DISTINFO_$alg`; do
        if [ "${sum%:*}" = "$3" ]; then
          echo "$alg=${sum##*:}"
        fi
      done
    done
  fi
}

###
# chksumfiles calculates CKSUMFILES = DISTFILES + PATCHFILES - IGNOREFILES
###

chksumfiles()
{
  echo "$IGNOREFILES" '<>' "$DISTFILES" "$PATCHFILES" |
    $TR -s ' \t' '\n' | $AWK '
      BEGIN { isignore=1 }
      /^$/ { next }
      /^<>$/ { isignore=0; next }
      {
        sub(/:[^:]+$/, "")
        if (isignore !=0)
          ignore[$0]=1
        else if (!($0 in ignore))
          print
      }
    '
}

### fetching distfiles ###

###
# fetch_xxx are wrappers for fetch
###

setup_fetch_cmd()
{
  [ -z "$fetch_cmd" ] || return 0

  case "${FETCH_CMD%% *}" in
  */curl)
    fetch_cmd=fetch_curl;;
  */wget)
    fetch_cmd=fetch_wget;;
  *)
    fetch_cmd=fetch_fetch;;
  esac
}

fetch_curl()
{
  local cksize

  cksize=
  if [ -n "$3" ]; then
    cksize=" --max-filesize $3"
  fi

  $SETENV $FETCH_ENV $FETCH_CMD $FETCH_BEFORE_ARGS$cksize \
    -o "$2" "$1" $FETCH_AFTER_ARGS
}

fetch_fetch()
{
  local cksize

  case "$2" in
  */*)
    [ -d "${file%/*}" ] || $MKDIR "${file%/*}";;
  esac

  symlink=
  if [ -n "$FETCH_SYMLINK_DISTFILES" ]; then
    symlink=" -l"
  fi

  cksize=
  if [ -n "$3" -a "$OSVERSION" -ge 480000 ]; then
    cksize=" -S $3"
  fi

  $SETENV $FETCH_ENV $FETCH_CMD $FETCH_BEFORE_ARGS$symlink$cksize \
    -o "$2" "$1" $FETCH_AFTER_ARGS
}

fetch_wget()
{
  case "$1" in
  file:*)
    fetch_fetch "$@" || return 1
    return 0;;
  esac

  case "$2" in
  */*)
    [ -d "${file%/*}" ] || $MKDIR "${file%/*}";;
  esac

  $SETENV $FETCH_ENV $FETCH_CMD $FETCH_BEFORE_ARGS \
    -O "$2" "$1" $FETCH_AFTER_ARGS
}

###
# get_master_sites returns a list of $1_SITES for groups $2
###

get_master_sites()
{
  [ $# -eq 2 ] || return 1

  # fun with awk
  for group in $2; do
    eval echo "\"\${$1_SITE_SUBDIR}\"" "'<>'" "\"\${$1_SITES}\"" |
    $TR -s ' \t' '\n' |
    $AWK '
      BEGIN {
        issubdir=1
        subdirs=0
      }
      /^$/ { next }
      /^<>$/ {
        issubdir=0
        if (subdirs == 0)
          subdir[subdirs++]=""
        next
      }
      {
        if ($0 ~ /\/:[^\/:]+$/) {
          if ($0 !~ /\/:([^\/:]*,)*'"$group"'(,[^\/:]*)*$/)
            next
          sub(/\/:[^\/:]+$/, issubdir != 0 ? "" : "/")
        } else if ("'"$group"'" != "DEFAULT") {
          next
        }
      }
      {
        if (issubdir != 0)
          subdir[subdirs++]=($0 == "." ? "" : $0 "/")
        else
          for (i in subdir) {
            site=$0
            gsub(/%SUBDIR%\//, subdir[i], site)
            print site
          }
      }
    ';
  done |
  $AWK '{ if ($0 in done) next; done[$0]=1 } { print }'
}

###
# get_master_sites_sorted returns a sorted list of $1_SITES for groups $2
###

get_master_sites_sorted()
{
  get_master_sites "$@" |
  if [ -n "$MASTER_SORT_CMD" ]; then
    $SETENV $MASTER_SORT_ENV $MASTER_SORT_CMD | $TR -s '\n' ' '
  elif [ -z "$KEEP_MASTER_SITE_ORDER" ]; then
    $AWK 'BEGIN { srand() } { print rand() "\t" $0 }' |
    $SORT -n | $CUT -f 2  | $TR -s '\n' ' ' |
    $AWK "$MASTER_SORT_AWK"
  else
    $TR -s '\n' ' ' |
    $AWK "$MASTER_SORT_AWK"
  fi
}

###
# fetch_file tries to fetch one file from {MASTER,PATCH}_SITES
###

fetch_file()
{
  [ $# -eq 5 ] || return 1

  SORTED_MASTER_SITES_TMP=`get_master_sites_sorted "$1" "$2"`
  reget=false
  [ -f "$file" ] && reget=true
  while true; do
    fetch_reget="${FETCH_REGET}"
    for site in $_MASTER_SITE_OVERRIDE \
        $SORTED_MASTER_SITES_TMP $_MASTER_SITE_BACKUP; do
      $ECHO_MSG ">> Attempting to fetch from $site${4:+ (${4#*=} bytes)}."
      case "$site" in
      *%FILE%*)
        # this expression uses ctrl-A as delimiters
        url=`echo "$site" | $SED -E -e 's/$; s%FILE%'"$file"'g'`;;
      *)
        url="$site$file";;
      esac
      if $fetch_cmd "$url" "$3" "$4"; then
        reget=false
        [ -f "$file" ] || continue
        [ -z "$5" ] && return 0
        for cksum2 in $5; do
          case "${cksum2#*=}" in
          IGNORE)
            return 0;;
          *)
            CKSUM=`do_hash "${cksum2%%=*}" < "$file"`
            if [ "${cksum2#*=}" = "$CKSUM" ]; then
              $ECHO_MSG ">> Checksum OK (${cksum2%%=*}) for $file."
              return 0
            fi;;
          esac
        done
        $ECHO_MSG ">> Checksum mismatch for $_file."
        if [ "$fetch_reget" -gt 0 ]; then
          $ECHO_MSG "===>  Refetch for $fetch_reget more times."
          $RM -f "$file"
          fetch_reget=$(($fetch_reget-1))
        else
          $ECHO_MSG ">> To get this file from more mirrors," \
              "type \"make FETCH_REGET=99 [other args]\"."
          $ECHO_MSG "===>  Giving up on fetching $_file."
          return 1
        fi
      fi
    done
    $reget || break
    $ECHO_MSG "===>  Distfile rerolled? Trying to refetch from start."
    $RM -f "$file"
    reget=false
  done
  $ECHO_MSG ">> Couldn't fetch it - please try to retrieve this"
  $ECHO_MSG ">> file manually into $_DISTDIR and try again."
  return 1
}

###
# do_fetch tries to fetch DISTFILES and PATCHFILES
###

do_fetch()
{
  local _DISTDIR
  local DIR
  local file
  local select

  setup_fetch_cmd

  _DISTDIR="$DISTDIR${DIST_SUBDIR:+/$DIST_SUBDIR}"
  DIR="${DIST_SUBDIR:+$DIST_SUBDIR/}"

  for fileset in MASTER PATCH; do
    case "$fileset" in
    MASTER)
      files="$DISTFILES";;
    PATCH)
      files="$PATCHFILES";;
    *)
      return 1;;
    esac
    for _file in $files; do

      file=`echo "$_file" | $SED -E -e 's/:[^:]+$//'`
      select=`echo "$_file" | $SED -En -e 'y/,/ /; s/.*:([^:]+)$/\1/p'`
      [ -n "$select" ] || select="DEFAULT"

      if [ -z "$NO_CHECKSUM" ]; then
        CKSUM2=`extract_sum "$VALID_ALGORITHMS" "$DIR" "$file"`
        if [ -z "$CKSUM2" ]; then
          $ECHO_MSG ">> No checksum entry for $DIR$file."
          $ECHO_MSG ">> Make sure the Makefile and distinfo file ($MD5_FILE) are"
          $ECHO_MSG ">> up to date.  If you are absolutely sure you want to override"
          $ECHO_MSG ">> this check, type \"make NO_CHECKSUM=yes [other args]\"."
          return 1
        fi
        chkfile=true
        for ignore in $IGNOREFILES; do
          if [ "$file" = "$ignore" ]; then
            chkfile=false
          fi
        done
      else
        CKSUM2=
        chkfile=false
      fi

      if [ -f "$_DISTDIR/$file" ]; then
        fileexists=true
      else
        fileexists=false
        if [ -L "$_DISTDIR/$file" ]; then
          $ECHO_MSG ">> $_DISTDIR/$file is a broken symlink."
          $ECHO_MSG ">> Perhaps a filesystem (most likely a CD) isn't mounted?"
          $ECHO_MSG ">> Please correct this problem and try again."
          return 1
        fi
      fi

      fetchfile=true
      if $fileexists; then
        if [ -n "$CKSUM2" ]; then
          for cksum2 in $CKSUM2; do
            case "${cksum2#*=}" in
            IGNORE)
              if $chkfile; then
                $ECHO_MSG ">> Checksum for $file is set to IGNORE in distinfo file"
                $ECHO_MSG "   even though the file is not in the "'$'"{IGNOREFILES} list."
                return 1
              fi
              fetchfile=false
              break;;
            *)
              if ! $chkfile; then
                $ECHO_MSG ">> Checksum for $file is not set to IGNORE in distinfo file"
                $ECHO_MSG "   even though the file is in the "'$'"{IGNOREFILES} list."
                return 1
              fi
              CKSUM=`do_hash "${cksum2%%=*}" < "$_DISTDIR/$file"`
              if [ "${cksum2#*=}" = "$CKSUM" ]; then
                $ECHO_MSG ">> Checksum OK (${cksum2%%=*}) for $file."
                fetchfile=false
                break
              fi;;
            esac
          done
          if $fetchfile; then
            $ECHO_MSG ">> Checksum mismatch for $file."
          fi
        else
          fetchfile=false
        fi
      else
        if [ -n "$CKSUM2" ]; then
          for cksum2 in $CKSUM2; do
            case "${cksum2#*=}" in
            IGNORE)
              if $chkfile; then
                $ECHO_MSG ">> Checksum for $file is set to IGNORE in distinfo file"
                $ECHO_MSG "   even though the file is not in the "'$'"{IGNOREFILES} list."
                return 1
              fi
              break;;
            *)
              if ! $chkfile; then
                $ECHO_MSG ">> Checksum for $file is not set to IGNORE in distinfo file"
                $ECHO_MSG "   even though the file is in the "'$'"{IGNOREFILES} list."
                return 1
              fi;;
            esac
          done
        fi
        $ECHO_MSG ">> $file doesn't seem to exist in $_DISTDIR."
      fi

      if $fetchfile; then
        if ! { [ -d "$_DISTDIR" ] || $MKDIR "$_DISTDIR"; }; then
           $ECHO_MSG ">> Cannot create $_DISTDIR."
           return 1
        fi
        if [ ! -w "$_DISTDIR" ]; then
           $ECHO_MSG ">> $_DISTDIR is not writable by you; cannot fetch."
           return 1
        fi
        if [ -z "$NO_CHECKSUM" -a -z "$DISABLE_SIZE" ]; then
          CKSIZE=`extract_sum 'SIZE' "$DIR" "$file"`
        else
          CKSIZE=
        fi
        cd "$_DISTDIR"
        if ! fetch_file "$fileset" "$select" "$file" "${CKSIZE#*=}" "$CKSUM2"; then
          return 1
        fi
      fi
    done
  done
}

###
# do_list_sites lists {MASTER,PATCH}_SITES
###

do_list_sites()
{
  [ $# -eq 2 ] || return 1

  local select

  case "$1" in
  MASTER)
    files="$DISTFILES";;
  PATCH)
    files="$PATCHFILES";;
  *)
    return 1;;
  esac

  if [ -n "$2" ]; then
    select="$2"
  else
    select=`echo "$files" | $TR -s ' \t' '\n' | $AWK '
      /.+:/ {
        sub(/.+:/, "")
        g=split($0, a, /,/)
        for (i in a)
          group[a[i]]=1
        next
      }
      { group["DEFAULT"]=1 }
      END {
        for (g in group)
          print g
      }'`
  fi

  SORTED_MASTER_SITES_TMP=`get_master_sites_sorted "$1" "$select"`
  echo $_MASTER_SITE_OVERRIDE \
      $SORTED_MASTER_SITES_TMP $_MASTER_SITE_BACKUP
}

### missing size ###

###
# print_missing_size prints a list of all files that are not in DISTDIR
###

print_missing_size()
{
  local _DISTDIR
  local DIR
  local file
  local select

  CKSUMFILES="${CKSUMFILES:-`chksumfiles`}"

  DIR="${DIST_SUBDIR:+$DIST_SUBDIR/}"

  for _file in $CKSUMFILES; do
    file="$DIR$_file"
    [ -f "$DISTDIR/$file" ] && continue
    CKSIZE=`extract_sum 'SIZE' "$DIR" "$_file"`
    if [ -n "${CKSIZE#*=}" ]; then
      echo "${CKSIZE#*=}	$file"
    else
      echo "0	$file"
    fi
  done

  for _file in $IGNOREFILES; do
    file="$DIR$_file"
    [ -f "$DISTDIR/$file" ] && continue
    echo "0	$file"
  done
}

### fetch all ##

###
# do_fetch_all tries to fetch all files from *every* site
###

do_fetch_all()
{
  local DIR
  local file
  local select

  setup_fetch_cmd

  _FAILED_SITES=
  DIR="${DIST_SUBDIR:+$DIST_SUBDIR/}"

  for fileset in MASTER PATCH; do
    case "$fileset" in
    MASTER)
      files="$DISTFILES";;
    PATCH)
      files="$PATCHFILES";;
    *)
      return 1;;
    esac

    for _file in $files; do
      file=`echo "$_file" | $SED -E -e 's/:[^:]+$//'`
      select=`echo "$_file" | $SED -En -e 'y/,/ /; s/.*:([^:]+)$/\1/p'`
      [ -n "$select" ] || select="DEFAULT"

      CKSUM2=`extract_sum "$VALID_ALGORITHMS" "$DIR" "$file"`
      if [ -z "$CKSUM2" ]; then
        $ECHO_MSG ">> No checksum recorded for $DIR$file."
        return 1
      fi
      CKSIZE=
      if [ -z "$DISABLE_SIZE" ]; then
        CKSIZE=`extract_sum 'SIZE' "$DIR" "$file"`
      fi

      $ECHO_MSG ">> Verifying availability of file $file."
      MASTER_SITES_TMP=`get_master_sites "$fileset" "$select"`
      for site in $MASTER_SITES_TMP; do
        $ECHO_MSG ">> Attempting to fetch from $site${CKSIZE:+ (${CKSIZE#*=} bytes)}."
        case "$site" in
        *%FILE%*)
          # this expression uses ctrl-A as delimiters
          url=`echo "$site" | $SED -E -e 's/$; s%FILE%'"$file"'g'`;;
        *)
          url="$site$file";;
        esac
        if [ -z "$NO_CHECKSUM" ]; then
          for cksum2 in $CKSUM2; do
            _FETCH_RESULT=`{ if ! $fetch_cmd "$url" "-" "${CKSIZE#*=}"; then \
              echo "FAILED: $$?" >&3; fi | do_hash "${cksum2%%=*}"; } 3>&1`;
            case "$_FETCH_RESULT" in
            FAILED:*)
                $ECHO_MSG ">> Fetch from $site failed."
                _FAILED_SITES="${_FAILED_SITES:+$_FAILED_SITES }$url";;
            *)
              case "${cksum2#*=}" in
              IGNORE)
                $ECHO_MSG ">> Checksum IGNORED for $file.";;
              "$_FETCH_RESULT")
                $ECHO_MSG ">> Checksum OK (${cksum2%%=*}) for $file.";;
              *)
                $ECHO_MSG ">> Checksum mismatch (${cksum2%%=*}) for $file."
                _FAILED_SITES="${_FAILED_SITES:+$_FAILED_SITES }$url";;
              esac;;
            esac
            break
          done
        else
          if _FETCH_RESULT=`$SETENV $FETCH_ENV $FETCH -s "$url"`; then
            if [ -n "${CKSIZE}" ]; then
              if [ "${CKSIZE#*=}" = "$_FETCH_RESULT" ]; then
                $ECHO_MSG ">> Size OK (${CKSIZE#*=}) for $file."
              else
                $ECHO_MSG ">> Size mismatch ($_FETCH_RESULT) for $file."
                _FAILED_SITES="${_FAILED_SITES:+$_FAILED_SITES }$url"
              fi
            else
              $ECHO_MSG ">> Found $file."
            fi
          else
            echo ">> Fetch from $site failed."
            _FAILED_SITES="${_FAILED_SITES:+$_FAILED_SITES }$url"
          fi
        fi
      done
    done
  done
  if [ -z "$_FAILED_SITES" ]; then
    echo ">> All files are fetchable."
  else
    echo ">> The following files did not fetch correctly:"
    echo "$_FAILED_SITES" | ${TR} ' ' '\n' | ${SED} -e 's/^/ - /'
  fi
}

###
# do_fetch_list generates a list of files to fetch
###

do_fetch_list()
{
  local _DISTDIR
  local DIR
  local file
  local select

  _DISTDIR="$DISTDIR${DIST_SUBDIR:+/$DIST_SUBDIR}"
  DIR="${DIST_SUBDIR:+$DIST_SUBDIR/}"

  for fileset in MASTER PATCH; do
    case "$fileset" in
    MASTER)
      files="$DISTFILES";;
    PATCH)
      files="$PATCHFILES";;
    *)
      return 1;;
    esac

    for _file in $files; do

      file=`echo "$_file" | $SED -E -e 's/:[^:]+$//'`
      select=`echo "$_file" | $SED -En -e 'y/,/ /; s/.*:([^:]+)$/\1/p'`
      [ -n "$select" ] || select="DEFAULT"

      if [ ! -f "$_DISTDIR/$file" ]; then
        SORTED_MASTER_SITES_TMP=`get_master_sites_sorted "$fileset" "$select"`
        for site in $_MASTER_SITE_OVERRIDE \
            $SORTED_MASTER_SITES_TMP $_MASTER_SITE_BACKUP; do
          case "$site" in
          *%FILE%*)
            # this expression uses ctrl-A as delimiters
            url=`echo "$site" | $SED -E -e 's/$; s%FILE%'"$file"'g'`;;
          *)
            url="$site$file";;
          esac
          if [ -n "$FETCH_ENV" ]; then
            echo -n "$SETENV $FETCH_ENV "
          fi
          echo -n "$FETCH_CMD $FETCH_BEFORE_ARGS" \
            "-o '$file' '$url' $FETCH_AFTER_ARGS || "
        done
        echo "echo '$file not fetched'"
      fi
    done

  done
}

### distinfo ###

###
# make_tmpsum generates a temporary distinfo file
###

make_tmpsum()
{
  local NO_CHECKSUM DISABLE_SIZE

  NO_CHECKSUM=true
  DISABLE_SIZE=true

  do_fetch || return 1

  CKSUMFILES="${CKSUMFILES:-`chksumfiles`}"

  if ! TMPMD5_FILE=`$MKTEMP -q "$MD5_FILE.XXXXXX"`; then
    echo ">> makesum: Can't create temporary checksum file"
    return 1
  fi

  cd "$DISTDIR"
  DIR="${DIST_SUBDIR:+$DIST_SUBDIR/}"

  MY_ALGS="$DISTINFO_ALGORITHMS";
  [ -z "$NO_SIZE" ] && MY_ALGS="$MY_ALGS SIZE"

  # faster, but not the same sort order as the `classic' distinfo
  #for alg in $MY_ALGS; do
  #  do_hash "$alg" `echo "$CKSUMFILES" | $SED -e "s^$DIR"` >> "$TMPMD5_FILE"
  #done

  for _file in $CKSUMFILES; do
    file="$DIR$_file"
    if [ -r "$file" ]; then
      for alg in $MY_ALGS; do
        do_hash "$alg" "$file" >> "$TMPMD5_FILE"
      done
    else
      $ECHO_MSG ">> $file is not in $DISTDIR"
      $RM "$TMPMD5_FILE"
      return 1
    fi
  done
  for _file in $IGNOREFILES; do
    file="$DIR$_file"
    echo "MD5 ($file) = IGNORE" >> "$TMPMD5_FILE"
  done
}

###
# replace_distinfo adds or replaces a distinfo entry in MK_FILE
###

replace_distinfo()
{
  [ $# -eq 1 -a -f "$1" ] || return 1

  if ! TMPMK_FILE=`$MKTEMP -q "$MK_FILE.XXXXXX"`; then
    $ECHO_MSG ">> makesum: Can't create temporary Makefile"
    return 1
  fi
  if ! $AWK -v MD5_FILE="$1" '
    BEGIN { seen=0; ignore=0; first=1 }
    /'"$MK_FILE_ENDMARKER"'/ { seen=NR }
    NR == 1, seen != 0 { print; next }
    !/^#/ { exit 1 }
    /^#:/ { ignore=0 }
    /^#:distinfo'"${DISTINFO_LABEL:+\.$DISTINFO_LABEL}"'$/ {
      if (first)
        while ((getline md5_line < MD5_FILE) > 0) {
          if (first) {
            print "#:distinfo'"${DISTINFO_LABEL:+\.$DISTINFO_LABEL}"'"
            first=0
          }
          print "#" md5_line
        }
      ignore=1
    }
    ignore == 0 { print }
    END {
      if (seen == 0)
        exit 1
      if (first)
        while ((getline md5_line < MD5_FILE) > 0) {
          if (first) {
            print "#:distinfo'"${DISTINFO_LABEL:+\.$DISTINFO_LABEL}"'"
            first=0
          }
          print "#" md5_line
        }
    }
  ' "$MK_FILE" > "$TMPMK_FILE"; then
    $ECHO_MSG ">> Parse error: $MK_FILE, end of file not found"
    $RM "$TMPMK_FILE"
    return 1
  fi
  $CAT "$TMPMK_FILE" > "$MK_FILE"
  $RM "$TMPMK_FILE"
}

###
# replace_distinfo2 adds or replaces a distinfo entry in MK_FILE
###

replace_distinfo2()
{
  [ $# -eq 1 -a -f "$1" ] || return 1

  if [ ! -x "$PERL5" ]; then
    $ECHO_MSG ">> makesum: perl 5 required, please install lang/perl"
    return 1
  fi

  #XXX TODO: honor status of $ECHO_MSG in `die'
  if ! $PERL5 -w -e '
    use strict;
    srand();
    my $marker="##-MARKER_".rand()."-##";
    my $valid_algs=join "|", "SIZE", split " ", $ARGV[3];
    my $distsubdir=$ARGV[1] ? "$ARGV[1]/" : "";
    my $distlabel=$ARGV[2] ? "$ARGV[2]_" : "";
    my %distinfo;

    open DISTINFO, "<$ARGV[0]"
      or die ">> migratesum2: error reading $ARGV[0]\n";
    while(<DISTINFO>) {
      push @{$distinfo{$1}{$2}}, $3
        if /^(\w+) *\($distsubdir(.*)\) *= *([\da-f]+)$/o
    }
    close DISTINFO;
    my $makefile;
    open MAKEFILE, "<$ARGV[4]"
      or die ">> migratesum2: error reading $ARGV[4]\n";
    {
      local $/;
      $makefile = <MAKEFILE>;
    }
    close MAKEFILE;
    my $newinfo;
    foreach my $key (split " ", $ARGV[3]) {
      next
        if !$distinfo{$key};
      my @chksum = ();
      foreach my $file (sort keys %{$distinfo{$key}}) {
        push @chksum, map "$file:$_", @{$distinfo{$key}{$file}};
      }
      $newinfo .= "DISTINFO_$distlabel$key+=\t";
      $newinfo .= join " \\\n\t\t", "", @chksum;
      $newinfo .= "\n";
    }
    $makefile =~ s/^DISTINFO_$distlabel(?:$valid_algs)[+:!?]?=.*(?:\\\n.*)*[^\\\n]\n/$marker\n/mg ||
    $makefile =~ s/^(COMMENT[+:!?]?=.*(?:\\\n.*)*[^\\\n])\n+/$1\n\n$marker\n\n/m ||
    die ">> migratesum2: error parsing $ARGV[4]\n";

    $makefile =~ s/^$marker\n/$newinfo/m;
    $makefile =~ s/^$marker\n//mg;

    open MAKEFILE, ">$ARGV[5]"
      or die ">> migratesum2: error writing $ARGV[4]\n";
    print MAKEFILE $makefile;
    close MAKEFILE;
  ' "$1" "$DIST_SUBDIR" "$DISTINFO_LABEL" "$VALID_ALGORITHMS SIZE" "$MK_FILE" "$MK_FILE"; then
    return 1
  fi
}


###
# do_makesum (re-)calculates distinfo
###

do_makesum()
{
  local algorithms
  algorithms=`echo -n "$VALID_ALGORITHMS SIZE" | $TR -s ' \t\n' '|'`

  make_tmpsum || return 1

  if [ -f "$MD5_FILE" ]; then
    $CAT "$TMPMD5_FILE" > "$MD5_FILE"
  elif $GREP -qs "^#:distinfo${DISTINFO_LABEL:+\.$DISTINFO_LABEL}$" "$MK_FILE"; then
    replace_distinfo "$TMPMD5_FILE"
  elif $GREP -Eqs "^DISTINFO${DISTINFO_LABEL:+_$DISTINFO_LABEL}_($algorithms)[+:!?]?=" "$MK_FILE"; then
    replace_distinfo2 "$TMPMD5_FILE"
  elif [ -s "$TMPMD5_FILE" ]; then
    $CAT "$TMPMD5_FILE" > "$MD5_FILE"
  fi

  $RM "$TMPMD5_FILE"
}

###
# do_migratemakesum integrates distinfo into the port's Makefile
###

do_migratesum()
{
  if [ ! -f "$MD5_FILE" ]; then
    $ECHO_MSG ">> migratesum: no $MD5_FILE"
    return 1
  fi

  if replace_distinfo "$MD5_FILE"; then
    $RM "$MD5_FILE"
    echo ">> Done."
  else
    return 1
  fi
}

###
# do_migratemakesum2 integrates distinfo into the port's Makefile
###

do_migratesum2()
{
  if [ ! -f "$MD5_FILE" ]; then
    $ECHO_MSG ">> migratesum2: no $MD5_FILE"
    return 1
  fi

  if replace_distinfo2 "$MD5_FILE"; then
    $RM "$MD5_FILE"
    echo ">> Done."
  else
    return 1
  fi
}

###
# main
###

opt_list_master=false
opt_list_patch=false
opt_fetch_list=false
opt_makesum=false
opt_migratesum=false
opt_migratesum2=false
opt_fetch=false
opt_fetch_all=false
opt_missing_size=false

while getopts "LmMNfFSt:T:" opt; do
  case "$opt" in
  t) list_master="${OPTARG}";
    opt_list_master=true;;
  T) list_patch="${OPTARG}";
    opt_list_patch=true;;
  L) opt_fetch_list=true;;
  m) opt_makesum=true;;
  M) opt_migratesum=true;;
  N) opt_migratesum2=true;;
  f) opt_fetch=true;;
  F) opt_fetch_all=true;;
  S) opt_missing_size=true;;
  ?) echo "Usage: $0 -LmMfFS"; exit 1;;
  esac
done

shift $(($OPTIND-1))

$opt_list_master &&
  { do_list_sites "MASTER" "$list_master" || exit 1; }

$opt_list_patch &&
  { do_list_sites "PATCH" "$list_patch" || exit 1; }

$opt_fetch_list &&
  { do_fetch_list || exit 1; }

$opt_fetch &&
  { do_fetch || exit 1; }

$opt_makesum &&
  { do_makesum || exit 1; }

$opt_migratesum &&
  { do_migratesum || exit 1; }

$opt_migratesum2 &&
  { do_migratesum2 || exit 1; }

$opt_fetch_all &&
  { do_fetch_all || exit 1; }

$opt_missing_size &&
  { print_missing_size || exit 1; }

exit 0
