# New ports collection makefile for:	childsplay_plugins
# Date created:				6 July 2004
# Whom:					bruno
#
# $FreeBSD$
#

PORTNAME=	childsplay_plugins
PORTVERSION=	0.90
CATEGORIES=	games
MASTER_SITES=	SF/childsplay/childsplay-plugins/${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	bruno@tinkerbox.org
COMMENT=	Educative games for children

BUILD_DEPENDS=	childsplay:${PORTSDIR}/games/childsplay
RUN_DEPENDS=	childsplay:${PORTSDIR}/games/childsplay

USE_PYTHON=	yes

post-patch:
	@${REINPLACE_CMD} -e "s@PREFIX=/usr/local@PREFIX=${PREFIX}@g " ${WRKSRC}/install.sh

.include <bsd.port.mk>
