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
            if [ $2 = "red" ]; then
                echo -e "\033[1;31m$1\033[m"
            elif [ $2 = "green" ]; then
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
trap "rm -f $tempfile" 0 1 2 3 15

while [ $# -gt 0 ]
do
    if [ -f "$1/Makefile" ]; then
        # See what the port thinks its PORTREVISION is and save that.
        pre=$(make -C "$1" -V PORTREVISION)

        # If the Makefile exists, continue and empty the tempfile, set up variables
	echo -n > $tempfile
        revision_str=`grep "^PORTREVISION?\?=" "$1/Makefile"`

        case $? in
        0)
            # If the exit code is 0, then PORTREVISION line was found
            if [ `echo "$revision_str" | wc -l` = 1 ]; then
                # If the $revision_str variable has only 1 line, then proceed with processing it
                case `echo "$revision_str" | awk -F "\t+" '{ print $2 }'` in
                    (*[^0-9]*|'')
                        # If the value of PORTREVISION is not an integer, we can't bump its value
                        printc "ERROR: $1 PORTREVISION value is not a number, unable to solve!" "red"
                        ;;
                    (*)
                        # If the value of PORTREVISION is an integer, increase it by 1
                        printc "INFO: $1 $revision_str found, bumping it by 1." "green"
                        rm -f $tempfile && awk -F "\t+" '/^PORTREVISION\??=/{ gsub ($2, $2+1) }; { print }' "$1/Makefile" > $tempfile \
                        && cat $tempfile > "$1/Makefile" \
                        || printc "ERROR: $1 PORTREVISION found but failed to bump it!" "red"
                        ;;
                esac
            else
                # If the $revision_str variable had more than 1 line, we can't bump its value safely
                printc "ERROR: $1 PORTREVISION found more than once, unable to bump it reliably!" "red"
            fi
            ;;
        1)
            # If the exit code is 1 then PORTREVISION wasn't found, so we need to add one with value of 1
            printc "INFO: $1 PORTREVISION not found, adding PORTREVISION= 1" "green"
            rm -f $tempfile && awk '/^(PORT|DIST)VERSION\??=\t/{ print; print "PORTREVISION=\t1"; next } { print }' "$1/Makefile" > $tempfile \
            && cat $tempfile > "$1/Makefile"
            # If there is not PORTREVISION line, maybe it is a slave port, try
            # to add it before a CATEGORIES, PKGNAMESUFFIX or PKGNAMEPREFIX line:
            for line in CATEGORIES PKGNAMEPREFIX PKGNAMESUFFIX; do
                    if ! grep -q "^PORTREVISION?\?=" $1/Makefile; then
                            rm -f $tempfile && awk '/^'${line}'\??=\t/{ print "PORTREVISION=\t1"; print; next } { print }' "$1/Makefile" > $tempfile \
                                    && cat $tempfile > "$1/Makefile"
                    fi
            done
            # If it still is not there, bail out
            if ! grep -q "^PORTREVISION?\?=" $1/Makefile; then
                    printc "ERROR: $1 PORTREVISION not found and failed to add it!" "red"
            fi

            # See what the port now has for PORTREVISION.
            post=$(make -C "$1" -V PORTREVISION)

            if [ "$post" -le "$pre" ]; then
                printc "ERROR: $1 PORTREVISION went backwards from $pre to $post!" "red"
            fi
            ;;
        *)
            printc "ERROR: PORTREVISION grep for $1 exited with error!" "red"
            ;;
        esac
    else
        # The directory specified had no Makefile, so it seems like a mistake
        printc "ERROR: $1 might not be a port directory because $1/Makefile is missing!" "red"
    fi
    shift
done

