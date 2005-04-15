# New ports collection makefile for: xyagamo
# Date created:		5 Nov 1999
# Whom:			Morita Shinya <shinmaru@dokidoki.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	xyagamo
PORTVERSION=	0.1b
CATEGORIES=	japanese games
MASTER_SITES=	http://www.dokidoki.ne.jp/home2/shinmaru/mahjong/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese version of a four player mahjong game

USE_X_PREFIX=	YES
USE_XPM=	yes
USE_REINPLACE=	yes

MAN6=		xyagamo.6
MANLANG=	ja
MAN6COMPRESSED=	no

post-patch:
	@${REINPLACE_CMD} -e 's/-lxpg4//' ${WRKSRC}/src/Makefile

pre-build:
	@cd ${BUILD_WRKSRC}/src; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} depend

.include <bsd.port.mk>
