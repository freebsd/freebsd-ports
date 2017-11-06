#!/bin/sh
#
# portsvar.sh:
#   print out variable defined through bsd.port.mk
#
# example:
#   % portsvar.sh PORTSDIR OSVERSION
#   PORTSDIR = /usr/ports
#   OSVERSION = 600034
#   % portsvar.sh -e "PORTS[^_]"
#   PORTSDIR = /usr/ports
#   PORTSSUPFILE = /usr/share/examples/cvsup/ports-supfile
#   % portsvar.sh USE_RUBY=yes RUBY_VER RUBY_ARCH
#   RUBY_VER = 1.8
#   RUBY_ARCH = i386-freebsd6
#   % portsvar.sh -w ruby RUBY_VER RUBY_ARCH
#   RUBY_VER = 1.8
#   RUBY_ARCH = i386-freebsd6
#   % portsvar.sh -w kde -e KDE_
#   KDE_MAINTAINER = will@FreeBSD.org
#   KDE_ORIGVER = ${KDE_VERSION}
#   KDE_PREFIX = ${LOCALBASE}
#   KDE_VERSION = 3.5.0
#   MASTER_SITE_KDE_kde = ${kmaster:S@%SUBDIR%/@@g}
#   % portsvar.sh -a
#   list all variables through bsd.port.mk
#   % portsvar.sh -a -w kde
#   list all variables through bsd.port.mk including kde
#
# $FreeBSD$
#
# MAINTAINER= daichi@FreeBSD.org

usage_msg="usage:
    portsvar.sh [-a] [-e] [-w target] [-h] [var=val ...] var1 [var2 ...]
        print out variable that includes var1 [var2 ...] through bsd.port.mk
    -a  print all variables defined through bsd.port.mk
    -e  regex search mode
    -w  set target bsd.*.mk name, for ex. -w kde
    -h  print this message"

# default values
alllistmode=off
regexmode=off

# options
while getopts aew:h? option
do
    case "$option" in
    a)
        alllistmode=on
        ;;
    e)
        regexmode=on
        ;;
    w)
        case $OPTARG in
        apache) setvar="$setvar USE_APACHE=yes";;
        autotools) setvar="$setvar USE_AUTOTOOLS=yes";;
        database) setvar="$setvar USE_MYSQL=yes USE_PGSQL=yes"
                  setvar="$setvar USE_BDB=yes";;
        emacs) setvar="$setvar EMACS_PORT_NAME=yes";;
        gcc) setvar="$setvar USE_GCC=yes";;
        gnome) setvar="$setvar USE_GNOME=yes";;
        gnustep) setvar="$setvar USE_GNUSTEP=yes";;
        gstreamer) setvar="$setvar USE_GSTREAMER=yes";;
        java) setvar="$setvar USE_JAVA=yes";;
        kde) setvar="$setvar USE_QT_VER=3";;
        openssl) setvar="$setvar USE_OPENSSL=yes";;
        php) setvar="$setvar USE_PHP=yes";;
        python) setvar="$setvar USE_PYTHON=yes";;
        ruby) setvar="$setvar USE_RUBY=yes";;
        sdl) setvar="$setvar USE_SDL=yes";;
        tcl) setvar="$setvar USE_TCL=yes USE_TK=yes";;
        esac
        ;;
    h|\?)
        echo "$usage_msg" 1>&2
        exit 1
        ;;
    esac
done
shift $(($OPTIND - 1))

# variables and set-variables
for target in $@
do
    case $target in
    *=*)
	setvar="$setvar $target"
	;;
    *)
	var="$var $target"
	;;
    esac
done

# all list
case $alllistmode in
on)
    make -f bsd.port.mk $setvar -dv 2>&1 | grep Global: | 
    sed 's/Global://' | sort -u | uniq
    exit 0
    ;;
esac

# usage
case $var in
"")
    echo "$usage_msg" 1>&2
    exit 1
    ;;
esac

# main
case $regexmode in
on)
    regex="^ " # like nop
    for target in $var
    do
        regex="$regex|^[^=]*${target}.*=.*"
    done
    make -f bsd.port.mk $setvar -dv 2>&1 | grep Global: | 
    sed 's/Global://' | sort -u | uniq | egrep "($regex)"
    ;;
off)
    for target in $var
    do
        echo -n "$target = "
        make -f bsd.port.mk $setvar -V $target
    done
    ;;
esac
