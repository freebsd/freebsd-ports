# New ports collection makefile for:	luna
# Version required:	1.9
# Date created:		03 July 1996
# Whom:			ABURAYER Rewsirow <rewsirow@ff.iij4u.or.jp>
#
# $FreeBSD$
#

DISTNAME=	luna19s
PKGNAME=	luna-1.9
CATEGORIES=	astro games
MASTER_SITES=	ftp://ftp.vector.co.jp/pack/dos/edu/science/space/
EXTRACT_SUFX=	.lzh

MAINTAINER=	rewsirow@ff.iij4u.or.jp

BUILD_DEPENDS=	lha:${PORTSDIR}/archivers/lha

EXTRACT_CMD=	lha
EXTRACT_BEFORE_ARGS=	xtfqw=${WRKDIR}
EXTRACT_AFTER_ARGS=	# empty

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile

.include <bsd.port.mk>
