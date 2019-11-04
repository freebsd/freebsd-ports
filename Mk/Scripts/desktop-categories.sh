#!/bin/sh
# $FreeBSD$
#
# MAINTAINER: portmgr@FreeBSD.org

set -e

. "${dp_SCRIPTSDIR}/functions.sh"

validate_env dp_CATEGORIES dp_SORT dp_TR dp_ECHO_CMD

[ -n "${DEBUG_MK_SCRIPTS}" ] || [ -n "${DEBUG_MK_SCRIPTS_DESKTOP_CATEGORIES}" ] && set -x

set -u

categories=""
for native_category in ${dp_CATEGORIES}; do
	c=""
	case ${native_category} in
		accessibility)	c="Utility Accessibility"		;;
		archivers)	c="Utility Archiving"			;;
		astro)		c="Education Science Astronomy"		;;
		audio)		c="AudioVideo Audio"			;;
		benchmarks)	c="System"				;;
		biology)	c="Education Science Biology"		;;
		cad)		c="Graphics Engineering"		;;
		comms)		c="Utility"				;;
		converters)	c="Utility"				;;
		databases)	c="Office Database"			;;
		deskutils)	c="Utility"				;;
		devel)		c="Development"				;;
		dns)		c="Network"				;;
		elisp)		c="Development"				;;
		editors)	c="Utility"				;;
		emulators)	c="System Emulator"			;;
		finance)	c="Office Finance"			;;
		ftp)		c="Network FileTransfer"		;;
		games)		c="Game"				;;
		geography)	c="Education Science Geography"		;;
		gnome)		c="GNOME GTK"				;;
		graphics)	c="Graphics"				;;
		hamradio)	c="HamRadio"				;;
		haskell)	c="Development"				;;
		irc)		c="Network IRCClient"			;;
		java)		c="Development Java"			;;
		kde)		c="KDE Qt"				;;
		lang)		c="Development"				;;
		lisp)		c="Development"				;;
		mail)		c="Office Email"			;;
		mate)		c="MATE GTK"				;;
		math)		c="Education Science Math"		;;
		mbone)		c="Network AudioVideo"			;;
		multimedia)	c="AudioVideo"				;;
		net)		c="Network"				;;
		net-im)		c="Network InstantMessaging"		;;
		net-mgmt)	c="Network"				;;
		net-p2p)	c="Network P2P"				;;
		net-vpn)	c="Network VPN"				;;
		news)		c="Network News"			;;
		parallel)	c="ParallelComputing"			;;
		pear)		c="Development WebDevelopment"		;;
		perl5)		c="Development"				;;
		python)		c="Development"				;;
		ruby)		c="Development"				;;
		rubygems)	c="Development"				;;
		scheme)		c="Development"				;;
		science)	c="Science Education"			;;
		security)	c="System Security"			;;
		shells)		c="System Shell"			;;
		sysutils)	c="System"				;;
		tcl*|tk*)	c="Development"				;;
		textproc)	c="Utility TextTools"			;;
		www)		c="Network"				;;
		x11-clocks)	c="Utility Clock"			;;
		x11-fm)		c="System FileManager"			;;
		xfce)		c="GTK XFCE"				;;
		zope)		c="Development WebDevelopment"		;;
	esac
	if [ -n "${c}" ]; then
		categories="${categories} ${c}"
	fi
done

if [ -n "${categories}" ]; then
	for c in ${categories}; do
		${dp_ECHO_CMD} "${c}"
	done | ${dp_SORT} -u | ${dp_TR} '\n' ';'
	${dp_ECHO_CMD}
fi
