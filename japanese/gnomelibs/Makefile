# New ports collection makefile for:	Japanese gnome-libs
# Date created:        28 October 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

# This port does not work with another version of master port.
#PORTVERSION=	1.2.8
CATEGORIES=	japanese x11 gnome

MASTERDIR=	${.CURDIR}/../../x11/gnomelibs

EXTRA_PATCHES=	${.CURDIR}/files/patch-*

MAINTAINER=	nakai@FreeBSD.org

PLIST=		${.CURDIR}/pkg-plist

post-install:
	${TOUCH} ${PREFIX}/bin/gnome-libs-jp
	${CHMOD} 755 ${PREFIX}/bin/gnome-libs-jp

.include "${MASTERDIR}/Makefile"
