PORTNAME=	sdb
PORTVERSION=	1.0.2
PORTREVISION=	17
CATEGORIES=	games
MASTER_SITES=	http://stage.gamecreation.org/shotgund/ \
		https://mirror.amdmi3.ru/distfiles/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Futuristic overhead shooter
WWW=		https://www.gamecreation.org/games/shotgun_debugger

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gl gmake sdl
USE_CXXSTD=	c++14
USE_GL=		gl glu
USE_SDL=	mixer image sdl

MAKE_ARGS=	CPP="${CXX}" CXXFLAGS="${CXXFLAGS}" LIBS="${LIBS}"

CXXFLAGS+=	`${SDL_CONFIG} --cflags`
LIBS+=		`${SDL_CONFIG} --libs` -lSDL_image -lSDL_mixer -lGL -lGLU

DESKTOP_ENTRIES="Shotgun Debugger" \
		"" \
		"" \
		"${PORTNAME}" \
		"Game;ActionGame;" \
		""

BUILD_WRKSRC=	${WRKSRC}/src

PLIST_FILES=	bin/sdb
PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} != "powerpc" && ${ARCH} != "powerpc64"
PLIST_SUB+=	MODEL_SUFFIX="md2"
.else
# big-endian requires different set of models
DISTFILES+=	shotgun-debugger-1.0.mac-ppc.zip
EXTRACT_DEPENDS+=	${UNZIP_CMD}:archivers/unzip
PLIST_SUB+=	MODEL_SUFFIX="md2b"

post-extract:
	${RM} ${WRKSRC}/models/*
	@cd ${WRKSRC}/models && \
		${RM} * && \
		${UNZIP_CMD} -qj ${DISTDIR}/shotgun-debugger-1.0.mac-ppc.zip \
			'sdb-1.0-macosx/models/*.md2b'
.endif

post-patch:
	@${REINPLACE_CMD} -Ee 's,(levels|models|snd|sprites)/,${DATADIR}/&,g' \
		${WRKSRC}/src/sdb.h ${WRKSRC}/src/game.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/sdb ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${COPYTREE_SHARE} "levels models snd sprites" ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
