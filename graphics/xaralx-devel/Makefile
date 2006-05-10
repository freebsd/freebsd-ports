# New ports collection makefile for:	XaraLX development version
# Date created:				12 Apr 2006
# Whom:					Vasil Dimov <vd@FreeBSD.org>
#
# $FreeBSD$
#

PORTVERSION=	0.4r991
PKGNAMESUFFIX=	-devel
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz

COMMENT=	Top-tier vector/general purpose graphics program (development version)

BUILD_DEPENDS=	xml2-config:${PORTSDIR}/textproc/libxml2

MASTERDIR=	${.CURDIR}/../xaralx
MD5_FILE=	${.CURDIR}/distinfo

PATCHDIR=	${.CURDIR}/files
EXTRA_PATCHES=	${MASTERDIR}/files/patch-PreComp_Makefile.am

.include "${MASTERDIR}/Makefile"
