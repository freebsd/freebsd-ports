# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	sdb
PORTVERSION=	1.0.2
PORTREVISION=	14
CATEGORIES=	games
MASTER_SITES=	http://stage.gamecreation.org/shotgund/ \
		http://mirror.amdmi3.ru/distfiles/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Futuristic overhead shooter

LICENSE=	GPLv2

USES=		gmake
USE_SDL=	mixer image sdl
USE_GL=		gl glu

BUILD_WRKSRC=	${WRKSRC}/src

CXXFLAGS+=	`${SDL_CONFIG} --cflags`
LIBS+=		`${SDL_CONFIG} --libs` -lSDL_image -lSDL_mixer -lGL -lGLU
MAKE_ARGS=	CPP="${CXX}" CXXFLAGS="${CXXFLAGS}" LIBS="${LIBS}"

PLIST_FILES=	bin/sdb
PORTDOCS=	*
PORTDATA=	*

DESKTOP_ENTRIES="Shotgun Debugger" \
		"${COMMENT}" \
		"" \
		"${PORTNAME}" \
		"Game;ActionGame;" \
		""

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} != "powerpc" && ${ARCH} != "sparc64"
PLIST_SUB+=	MODEL_SUFFIX="md2"
.else
# big-endian requires different set of models
DISTFILES+=	shotgun-debugger-1.0.mac-ppc.zip
EXTRACT_DEPENDS+=	${UNZIP_CMD}:archivers/unzip
PLIST_SUB+=	MODEL_SUFFIX="md2b"

post-extract:
	${RM} ${WRKSRC}/models/*
	@cd ${WRKSRC}/models && \
		${RM} -f * && \
		${UNZIP_CMD} -qj ${DISTDIR}/shotgun-debugger-1.0.mac-ppc.zip \
			'sdb-1.0-macosx/models/*.md2b'
.endif

post-patch:
	@${REINPLACE_CMD} -Ee 's,(levels|models|snd|sprites)/,${DATADIR}/&,g' \
		${WRKSRC}/src/sdb.h ${WRKSRC}/src/game.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/sdb ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${COPYTREE_SHARE} "levels models snd sprites" ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
