PORTNAME=	supermodel
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3a-20260506
DISTVERSIONSUFFIX=	-git-9c9e7b7
CATEGORIES=	emulators

MAINTAINER=	owlandrews@protonmail.com
COMMENT=	Sega Model 3 arcade emulator
WWW=		https://github.com/trzy/Supermodel

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/Docs/LICENSE.txt

ONLY_FOR_ARCHS=	amd64

USES=		compiler gl gmake localbase:ldflags sdl

USE_GITHUB=	yes
GH_ACCOUNT=	trzy

USE_GL=		glu opengl
USE_SDL=	net2 sdl2

MAKEFILE=	Makefiles/Makefile.UNIX

DESKTOP_ENTRIES=	"Supermodel" \
			"${COMMENT}" \
			"supermodel" \
			"supermodel" \
			"Game;ArcadeGame;Emulator;" \
			false
SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/Supermodel-${DISTVERSION}${DISTVERSIONSUFFIX}

PORTDOCS=	README.txt

OPTIONS_DEFINE=	DEBUGGER DOCS EXTRA_DEBUGGING

DEBUGGER_DESC=		Include console-based debugger in emulator
EXTRA_DEBUGGING_DESC=	Enable extra debug logging and render state analyser for the legacy 3D engine

DEBUGGER_MAKE_ARGS=	ENABLE_DEBUGGER=1
DEBUGGER_MAKE_ARGS_OFF=	ENABLE_DEBUGGER=0

EXTRA_DEBUGGING_MAKE_ARGS=	EXTRA_DEBUG=1
EXTRA_DEBUGGING_MAKE_ARGS_OFF=	EXTRA_DEBUG=0

post-patch:
	@${REINPLACE_CMD} -e 's|CC =|CC ?=|g' \
		-e 's|CXX =|CXX ?=|g' \
		-e 's|LD = gcc|LD = ${CC}|g' \
		-e 's|^PLATFORM_LDFLAGS = \(.*\)|PLATFORM_LDFLAGS := \1 $$(LDFLAGS)|' \
		${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e 's|^COMMON_CFLAGS = \(.*\)|COMMON_CFLAGS = \1 $$(CPPFLAGS)|' \
		${WRKSRC}/Makefiles/Rules.inc

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/Config/Games.xml ${STAGEDIR}${ETCDIR}/Games.xml.sample
	${INSTALL_DATA} ${WRKSRC}/Config/Music.xml ${STAGEDIR}${ETCDIR}/Music.xml.sample
	${INSTALL_DATA} ${WRKSRC}/Assets/p1crosshair.bmp ${STAGEDIR}${DATADIR}/p1crosshair.bmp
	${INSTALL_DATA} ${WRKSRC}/Assets/p2crosshair.bmp ${STAGEDIR}${DATADIR}/p2crosshair.bmp
	${INSTALL_PROGRAM} ${WRKSRC}/bin/supermodel ${STAGEDIR}${PREFIX}/bin/supermodel

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Docs/${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
