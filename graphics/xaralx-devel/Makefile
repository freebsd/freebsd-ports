# New ports collection makefile for:	XaraLX development version
# Date created:				12 Apr 2006
# Whom:					Vasil Dimov <vd@FreeBSD.org>
#
# $FreeBSD$
#

PORTVERSION=	0.7r1768
PORTREVISION=	3
PKGNAMESUFFIX=	-devel
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.bz2

COMMENT=	Top-tier vector/general purpose graphics program (development version)

MASTERDIR=	${.CURDIR}/../xaralx
MD5_FILE=	${.CURDIR}/distinfo
PLIST=		${.CURDIR}/pkg-plist
PATCHDIR=	${.CURDIR}/files
EXTRA_PATCHES=	${MASTERDIR}/files/patch-configure.in \
		${MASTERDIR}/files/patch-wxOil_compatdef.h

.include "${MASTERDIR}/Makefile"
