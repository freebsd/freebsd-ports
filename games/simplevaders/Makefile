# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	simplevaders
PORTVERSION=	0.8
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://dusted.dk/download/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Space-Invaders like 2D space shooter

LICENSE=	GPLv3

USES=		tar:bzip2
USE_SDL=	sdl mixer image ttf
USE_GL=		gl glu

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -e 's|data/|${DATADIR}/|' ${WRKSRC}/main.cpp
	@${RM} ${WRKSRC}/data/*\~

do-build:
	(cd ${WRKSRC} && ${CXX} ${CPPFLAGS} ${CXXFLAGS} ${LDFLAGS} main.cpp \
		-o ${PORTNAME} `${SDL_CONFIG} --cflags --libs` -lSDL_ttf \
		-lSDL_mixer -lSDL_image -lGL -lGLU)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
