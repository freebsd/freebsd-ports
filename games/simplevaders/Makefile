# New ports collection makefile for:	simplevaders
# Date created:		21 Apr 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	simplevaders
PORTVERSION=	0.8
CATEGORIES=	games
MASTER_SITES=	http://dusted.dk/download/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A Space-Invaders like 2D space shooter

USE_BZIP2=	yes
USE_SDL=	sdl mixer image ttf
USE_GL=		gl glu

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|data/|${DATADIR}/|' ${WRKSRC}/main.cpp
	@${RM} ${WRKSRC}/data/*\~

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} main.cpp -o ${PORTNAME} \
		`${SDL_CONFIG} --cflags --libs` -lSDL_ttf -lSDL_mixer \
		-lSDL_image -lGL -lGLU

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${DATADIR}

.include <bsd.port.mk>
