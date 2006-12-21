# New ports collection makefile for:	untahris
# Date created:		08 Sep 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	untahris
DISTVERSION=	1.0beta
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${DISTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	Play several classic fun, simple arcade games in multiplayer mode

USE_SDL=	sdl net ttf
USE_GCC=	3.4+

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/untahris %%DATADIR%%/VeraBd.ttf %%DATADIR%%/graph16.unt
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		does not compile on 4.x
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|verabd.ttf|${DATADIR}/VeraBd.ttf|; \
		s|graph%d|${DATADIR}/graph%d|' ${WRKSRC}/intface.cpp
	@${REINPLACE_CMD} -e 's|TPlayground::||' ${WRKSRC}/untahris.h

do-build:
	cd ${WRKSRC} && ${CXX} ${CXXFLAGS} `${SDL_CONFIG} --libs --cflags` \
		-lSDL_net -lSDL_ttf untahris.cpp -o untahris

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/untahris ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/VeraBd.ttf ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/graph16.unt ${DATADIR}

.include <bsd.port.post.mk>
