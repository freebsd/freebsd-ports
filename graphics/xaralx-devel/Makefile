# New ports collection makefile for:	XaraLX development version
# Date created:				12 Apr 2006
# Whom:					Vasil Dimov <vd@FreeBSD.org>
#
# $FreeBSD$
#

PORTVERSION=	0.4r925
PKGNAMESUFFIX=	-devel
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz

COMMENT=	Top-tier vector/general purpose graphics program (development version)

MASTERDIR=	${.CURDIR}/../xaralx
MD5_FILE=	${.CURDIR}/distinfo

# we need to exclude some of the patches as they are applied upstream
PATCHDIR=	${NONEXISTENT}
EXTRA_PATCHES=	${MASTERDIR}/files/patch-Makefile.am \
		${MASTERDIR}/files/patch-PreComp_Makefile.am \
		${MASTERDIR}/files/patch-configure.in

.include "${MASTERDIR}/Makefile"
