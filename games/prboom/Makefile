# New ports collection makefile for:	prboom
# Date created:				10 June 2001
# Whom:					Jordan DeLong <fracture@allusion.net>
#
# $FreeBSD$
#

PORTNAME=	prboom
PORTVERSION=	2.2.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	fracture@allusion.net
COMMENT=	A multiplayer-capable and modified version of ID's classic doom game

LIB_DEPENDS=	smpeg.1:${PORTSDIR}/multimedia/smpeg

USE_SDL=	mixer net sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS+="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN5=		boom.cfg.5
MAN6=		prboom.6 prboom-game-server.6

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/prboom
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/prboom
	${INSTALL_DATA} ${WRKSRC}/doc/README.compat ${PREFIX}/share/doc/prboom
	${INSTALL_DATA} ${WRKSRC}/doc/README.demos ${PREFIX}/share/doc/prboom
	${INSTALL_DATA} ${WRKSRC}/doc/boom.txt ${PREFIX}/share/doc/prboom
.endif

.include <bsd.port.mk>
