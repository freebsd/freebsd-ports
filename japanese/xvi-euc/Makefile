# New ports collection makefile for:	ja-xvi-euc
# Date created:		07 Aug 2002
# Whom:			KIMURA Shigekazu <zau50357@lion.zero.ad.jp>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-euc

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A portable multi-window 'vi', handles japanese EUC

MASTERDIR=	${.CURDIR}/../xvi-euc

COMMENT=	${.CURDIR}/pkg-comment
PLIST=		${.CURDIR}/pkg-plist

PROG=		xvi

post-install:
	cd ${PREFIX}/bin; ${LN} -f ${PROG} jxvi

.include "${MASTERDIR}/Makefile.common"
