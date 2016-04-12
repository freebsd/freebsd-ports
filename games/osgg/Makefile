# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	osgg
PORTVERSION=	0.99
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	OldSkool Gravity Game

USES=		tar:bzip2
USE_SDL=	sdl image ttf mixer
USE_GL=		yes

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

post-extract:
	@${FIND} -d ${WRKSRC} -name .svn -exec ${RM} -rf {} \;

post-patch:
	@${RM} -f ${WRKSRC}/osgg
	@${REINPLACE_CMD} -e 's|"[a-z]*.txt"|DATADIR&|; s|endian.h|sys/&|' \
		${WRKSRC}/main.cpp

do-build:
	cd ${WRKSRC} && ${CXX} ${CXXFLAGS} `${SDL_CONFIG} --libs --cflags` \
		-lGL -lSDL_image -lSDL_ttf -lSDL_mixer -o ${PORTNAME} \
		-DDATADIR="\"${DATADIR}/\"" \
		main.cpp text.cpp sound.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC} && ${COPYTREE_SHARE} "*.txt *.ogg Bandal.ttf icon.png levels" ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
