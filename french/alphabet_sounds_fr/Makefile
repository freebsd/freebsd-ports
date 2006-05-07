# New ports collection makefile for:	alphabet_sounds_fr
# Date created:				6 July 2004
# Whom:					bruno
# $FreeBSD$

PORTNAME=	alphabet_sounds_fr
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	french games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	childsplay
DISTNAME=	alphabet_sounds_fr

MAINTAINER=	bruno@tinkerbox.org
COMMENT=	Educative games for children. Alphabet sounds package (french)

BUILD_DEPENDS=	${X11BASE}/bin/childsplay:${PORTSDIR}/games/childsplay
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_X_PREFIX=	yes

post-patch:
	@${REINPLACE_CMD} -e "s@PREFIX=/usr/local@PREFIX=${PREFIX}@g " ${WRKSRC}/install.sh

.include <bsd.port.mk>
