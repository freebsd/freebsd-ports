# New ports collection makefile for:	Japanese gnome-core
# Date created:        28 October 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

# This port does not work with another version of master port.
#PORTVERSION=	1.2.4
CATEGORIES=	japanese x11 gnome

MASTERDIR=	${.CURDIR}/../../x11/gnomecore

EXTRA_PATCHES=	${.CURDIR}/files/patch-*

MAINTAINER=	nakai@FreeBSD.org

BUILD_DEPENDS=	gnome-libs-jp:${PORTSDIR}/japanese/gnomelibs

.include "${MASTERDIR}/Makefile"
