# New ports collection makefile for:	prboom
# Date created:				10 June 2001
# Whom:					Jordan DeLong <fracture@allusion.net>
#
# $FreeBSD$
#

PORTNAME=	prboom
PORTVERSION=	2.2.6
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	robin.schoonover@gmail.com
COMMENT=	A multiplayer-capable and modified version of ID's classic doom game

LIB_DEPENDS=	smpeg.1:${PORTSDIR}/multimedia/smpeg

USE_SDL=	mixer net sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS+="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=--disable-cpu-opt

MAN5=		boom.cfg.5
MAN6=		prboom.6 prboom-game-server.6

.if defined(WITH_GL)
CONFIGURE_ARGS+=--enable-gl
USE_GL= 	yes
.endif

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/prboom
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/prboom
	${INSTALL_DATA} ${WRKSRC}/doc/README.compat ${PREFIX}/share/doc/prboom
	${INSTALL_DATA} ${WRKSRC}/doc/README.demos ${PREFIX}/share/doc/prboom
	${INSTALL_DATA} ${WRKSRC}/doc/boom.txt ${PREFIX}/share/doc/prboom
.endif

.include <bsd.port.post.mk>
