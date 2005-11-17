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

USE_GMAKE=	yes
USE_SDL=	mixer net sdl

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS+="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=--disable-cpu-opt

OPTIONS=	GL "Enable OpenGL support" off

MAN5=		boom.cfg.5
MAN6=		prboom.6 prboom-game-server.6

DATADIR=	${DMDIR}

.include "${.CURDIR}/../doom-data/Makefile.include"

.include <bsd.port.pre.mk>

.if defined(WITH_GL)
CONFIGURE_ARGS+=--enable-gl
USE_GL=		yes
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.   for f in README doc/README.compat doc/README.demos doc/boom.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.   endfor
.endif

.include <bsd.port.post.mk>
