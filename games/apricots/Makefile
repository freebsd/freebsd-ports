# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	apricots
PORTVERSION=	0.2.6
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://www.fishies.org.uk/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Fly a little plane around and shoot things and drop bombs

USE_SDL=	sdl
USES=		dos2unix
DOS2UNIX_GLOB=	*.cpp
SUB_FILES=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} libexec/${PORTNAME}
PORTDATA=	*
PORTDOCS=	*
CPPFLAGS+=	-DAP_PATH="\"${DATADIR}/\""
LLD_UNSAFE=	yes

DESKTOP_ENTRIES="Apricots" \
		"${COMMENT}" \
		"" \
		"${PORTNAME}" \
		"Game;ArcadeGame;" \
		false

OPTIONS_DEFINE=	DOCS OPENAL
OPTIONS_DEFAULT=OPENAL

OPENAL_USES=	openal:al,alut
OPENAL_CPPFLAGS=-DAP_AUDIO_OPENAL
OPENAL_LDFLAGS=	-L${LOCALBASE}/lib -lopenal -lalut

do-build:
	cd ${WRKSRC}/apricots && ${CXX} ${CXXFLAGS} ${CPPFLAGS} ${LDFLAGS} \
		`${SDL_CONFIG} --cflags --libs` *.cpp -o ${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/apricots/${PORTNAME} ${STAGEDIR}${PREFIX}/libexec
	${MKDIR} ${STAGEDIR}${DATADIR}
.for ext in wav shapes psf cfg
	${INSTALL_DATA} ${WRKSRC}/apricots/*.${ext} ${STAGEDIR}${DATADIR}
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
