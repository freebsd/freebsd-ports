# New ports collection makefile for:	libvorbis-aotuv
# Date created:		28 May 2004
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

MASTERDIR=	${.CURDIR}/../libvorbis

PKGNAMESUFFIX=	-aotuv

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A variant of libvorbis enhanced for sound quality

PATCH_SITES=	ftp://ftp.iDaemons.org/pub/distfiles/
PATCHFILES=	libvorbis-aotuv_b2.patch.bz2
PATCH_DIST_STRIP=	-p1

CONFLICTS=	libvorbis-[0-9]*

DESCR=		${.CURDIR}/pkg-descr
MD5_FILE=	${.CURDIR}/distinfo

.include "${MASTERDIR}/Makefile"
