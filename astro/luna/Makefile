# New ports collection makefile for:	luna
# Date created:		03 July 1996
# Whom:			ABURAYER Rewsirow <rewsirow@ff.iij4u.or.jp>
#
# $FreeBSD$
#

PORTNAME=	luna
PORTVERSION=	1.9
CATEGORIES=	astro games
MASTER_SITES=	ftp://ftp.vector.co.jp/pack/dos/edu/science/space/
DISTNAME=	luna19s
EXTRACT_SUFX=	.lzh

MAINTAINER=	rewsirow@ff.iij4u.or.jp

BUILD_DEPENDS=	lha:${PORTSDIR}/archivers/lha

EXTRACT_CMD=	lha
EXTRACT_BEFORE_ARGS=	xtfqw=${WRKDIR}
EXTRACT_AFTER_ARGS=	# empty

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile

.include <bsd.port.mk>
