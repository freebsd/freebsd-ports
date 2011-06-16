# New ports collection makefile for:	ja-xvi-sjis
# Date created:		07 Aug 2002
# Whom:			KIMURA Shigekazu <rikimura@a011.broada.jp>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-sjis

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A portable multi-window 'vi', handles Japanese SJIS

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2011-08-01

MASTERDIR=	${.CURDIR}/../xvi-euc

PATCHDIR=	${.CURDIR}/files

EXTRA_PATCHES=	${MASTERDIR}/files/patch-unix.h

PLIST=		${.CURDIR}/pkg-plist

PROG=		sxvi

.include "${MASTERDIR}/Makefile.common"
