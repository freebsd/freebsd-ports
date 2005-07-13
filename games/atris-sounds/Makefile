# New ports collection makefile for:	games/atris-sounds
# Date created:			9 Aug 2005
# Whom:				Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	atris
PORTVERSION=	1.0.1
CATEGORIES=	games
MASTER_SITES=	http://www.cs.berkeley.edu/~weimer/atris/
PKGNAMESUFFIX=	-sounds
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	alejandro@varnet.biz
COMMENT=	Sounds for Atris: Alizarin Tetris

RUN_DEPENDS=	atris:${PORTSDIR}/games/atris

USE_GMAKE=	yes
USE_REINPLACE=	yes

GNU_CONFIGURE=	yes

post-patch:
# Fix path to ${DATADIR}
	${REINPLACE_CMD} -e 's|\(GAME_INSTALLDIR=\).*|\1"${DATADIR}"|' \
			${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
