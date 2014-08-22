#!/bin/sh

#
# bump-revision.sh category/portname category/portname ...
# Bump PORTREVISION if it exists or create it with number 1 if it does not
#
# ----------------------------------------------------------------------------
# "THE BEER-WARE LICENSE" (Revision 42, (c) Poul-Henning Kamp):
# Bartek Rutkowski <robak@FreeBSD.org> wrote this file.  As long as you retain
# this notice you can do whatever you want with this stuff. If we meet some
# day, and you think this stuff is worth it, you can buy me a beer in return.
#
# Bartek Rutkowski
# ----------------------------------------------------------------------------
#
# $FreeBSD$
#
# MAINTAINER= robak@FreeBSD.org

#
# functions
#

printc () {
# $1 - msg is obligatory, $2 - color (red/green)of the message, default if not passed
    if [ -t 1 ]; then
        if [ $# -eq 2 ]; then
            if [ $2 == "red" ]; then
                echo -e "\033[1;31m$1\033[m"
            elif [ $2 == "green" ]; then
                echo -e "\033[1;32m$1\033[m"
            else
                echo "$1"
            fi
        fi
    else
        echo $1
    fi
}

#
# main loop
#

tempfile=$(mktemp)
rm -f $tempfile
trap "rm -f $tempfile" 0 1 2 3 15

while [ $# -gt 0 ]
do
    if [ -f "$1/Makefile" ]; then
        echo -n > $tempfile
        revision=`grep "^PORTREVISION?\?=" "$1/Makefile"`
	case $? in
	0)
	    # fixme: gsub fails massively if there are any special
	    # characters inside PORTREVISION.  For now, we will only
	    # catch this bug by checking the replace count, and if not
	    # 1, bail out and complain.
	    # The proper fix is to do a stricter check that PORTREVISION
	    # is an integer.
	    awk -F "\t" '/^PORTREVISION\??=/{ rplc = gsub ($2,$2+1); if (rplc != 1) { exit 1 } };{ print }' "$1/Makefile" > $tempfile \
            && { cat $tempfile > "$1/Makefile" ; printc "$1: $revision found, bumping it by 1." "green" ; } \
	    || printc "$1: FAILED TO BUMP PORTREVISION" red
	    ;;
	1)
            awk '/^PORTVERSION\??=\t/{print;print "PORTREVISION=\t1";next}' "$1/Makefile" > $tempfile \
            && { cat $tempfile > "$1/Makefile" ;printc "$1: PORTREVISION not found, adding PORTREVISION=1" "green" ; } \
	    || printc "$1: FAILED TO BUMP PORTREVISION" red
	    ;;
	*)
	    printc "$1: grepping $1/Makefile failed!" red
	    ;;
	esac
    else
        printc "$1: might not be a port directory as $1/Makefile is missing!" "red"
    fi
    shift
done
