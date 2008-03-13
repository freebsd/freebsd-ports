# New ports collection makefile for:	untahris
# Date created:		08 Sep 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	untahris
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	Play several classic fun, simple arcade games in multiplayer mode

USE_SDL=	sdl net ttf mixer

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|VeraBd.ttf|${DATADIR}/VeraBd.ttf|; \
		s|graph%d|${DATADIR}/&|; s|[a-z]*\.wav|${DATADIR}/&|' \
		${WRKSRC}/intface.cpp
	@${REINPLACE_CMD} -e 's|TPlayground::||' ${WRKSRC}/untahris.h

do-build:
	cd ${WRKSRC} && ${CXX} ${CXXFLAGS} `${SDL_CONFIG} --libs --cflags` \
		-lSDL_net -lSDL_ttf -lSDL_mixer untahris.cpp -o untahris

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/untahris ${PREFIX}/bin
	${MKDIR} ${DATADIR}
.for f in VeraBd.ttf graph16.unt *.wav
	${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}
.endfor
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
