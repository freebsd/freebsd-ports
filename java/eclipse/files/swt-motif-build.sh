#*******************************************************************************
# Copyright (c) 2000, 2004 IBM Corporation and others.
# All rights reserved. This program and the accompanying materials
# are made available under the terms of the Common Public License v1.0
# which accompanies this distribution, and is available at
# http://www.eclipse.org/legal/cpl-v10.html
# 
# Contributors:
#     IBM Corporation - initial API and implementation
#     Kevin Cornell (Rational Software Corporation)
#     Tom Tromey (Red Hat, Inc.)
#     Sridhar Bidigalu (ICS)
#*******************************************************************************

#!/bin/sh

# Determine the operating system being built
OS=`uname -s`

# build according to the operating system
case $OS in

    "AIX")
        if  [ "$1" = "clean" ]; then
            make -f make_aix.mak clean
        else
            echo "Building AIX version of SWT and CDE DLLs."
            make -f make_aix.mak make_swt
            make -f make_aix.mak make_cde
        fi
        ;;

    "FreeBSD")
        if  [ "$1" = "clean" ]; then
            gmake -f make_freebsd.mak clean
        else
            echo "Building FreeBSD version of SWT and GNOME DLLs."
            gmake -f make_freebsd.mak ${1} ${2} ${3} ${4}
            build_kde=`pkg_info -xc kdebase | grep "no packages match"`
            if [ "$build_kde" != "" ]; then
                echo "Building FreeBSD version of KDE DLL."
                gmake -f make_freebsd.mak make_kde
            fi
        fi
        ;;

    "Linux")
        if  [ "$1" = "clean" ]; then
            make -f make_linux.mak clean
        else
            echo "Building Linux version of SWT and GNOME DLLs."
            make -f make_linux.mak make_swt make_awt make_gnome make_gtk

            build_kde=`rpm -q kdebase | grep "not installed"`
            if [ "$build_kde" = "" ]; then
                echo "Building Linux version of KDE DLL."
                make -f make_linux.mak make_kde
            fi
        fi
        ;;

    "SunOS")
        if  [ "$1" = "clean" ]; then
            make -f make_solaris.mak clean
        else
            echo "Building Solaris version of SWT and CDE DLLs."
            make -f make_solaris.mak make_swt
            make -f make_solaris.mak make_cde
        fi
        ;;

        "HP-UX")
        # Determine the model number system being built
        MODEL=`uname -m`
       
        case $MODEL in

        "ia64")
           # ia64 based systems
           if  [ "$1" = "clean" ]; then
               make -f make_hpux_ia64.mak clean
           else
               echo "Building HP-UX ia64 version of SWT and CDE DLLs."
               make -f make_hpux_ia64.mak make_swt
               make -f make_hpux_ia64.mak make_cde
           fi
           ;;

        *)
          # PA_RISC based systems 
	      if  [ "$1" = "clean" ]; then
               make -f make_hpux_PA_RISC.mak clean
          else
               echo "Building HP-UX PA_RISC version of SWT and CDE DLLs."
               make -f make_hpux_PA_RISC.mak make_swt
               make -f make_hpux_PA_RISC.mak make_cde
           fi
           ;;
        esac
        ;;

    *)
        echo "Unknown OS -- build aborted"
        ;;
esac
