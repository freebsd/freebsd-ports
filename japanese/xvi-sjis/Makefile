# New ports collection makefile for:	ja-xvi-sjis
# Date created:		07 Aug 2002
# Whom:			KIMURA Shigekazu <zau50357@lion.zero.ad.jp>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-sjis

MAINTAINER=	ports@FreeBSD.org

MASTERDIR=	${.CURDIR}/../xvi-euc

PATCHDIR=	${.CURDIR}/files

EXTRA_PATCHES=	${MASTERDIR}/files/patch-unix.h

COMMENT=	${.CURDIR}/pkg-comment
PLIST=		${.CURDIR}/pkg-plist

PROG=		sxvi

.include "${MASTERDIR}/Makefile.common"
