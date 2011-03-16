# New ports collection makefile for:	ja-xvi-euc
# Date created:		07 Aug 2002
# Whom:			KIMURA Shigekazu <rikimura@a011.broada.jp>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-euc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A portable multi-window 'vi', handles Japanese EUC

MASTERDIR=	${.CURDIR}/../xvi-euc

PLIST=		${.CURDIR}/pkg-plist

PROG=		xvi

post-install:
	cd ${PREFIX}/bin; ${LN} -f ${PROG} jxvi

.include "${MASTERDIR}/Makefile.common"
