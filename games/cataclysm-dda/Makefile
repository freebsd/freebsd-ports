# Created by: Vladimir Kondratiev <wulf@cicgroup.ru>
# $FreeBSD$

PORTNAME=	cataclysm-dda
DISTVERSION=	0.E
PORTREVISION?=	0
PORTEPOCH=	1
CATEGORIES=	games

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Roguelike set in a post-apocalyptic world

LICENSE=	CC-BY-SA-3.0
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		alias compiler:c++14-lang gmake shebangfix
SHEBANG_FILES=	lang/*.sh build-scripts/validate_pr_in_jenkins
bash_CMD=	/bin/sh

USE_GITHUB=	yes
GH_ACCOUNT=	CleverRaven
GH_PROJECT=	Cataclysm-DDA

MAKE_ARGS=	CXX="${CXX}" LD="${CXX}" RELEASE=1 WARNINGS=-w USE_XDG_DIR=1 ASTYLE=0

OPTIONS_DEFINE=		NLS DATA DOCS SOUND
OPTIONS_DEFAULT=	NLS
OPTIONS_SINGLE=		UI
OPTIONS_SINGLE_UI=	NCURSES SDL
OPTIONS_SUB=		yes
OPTIONS_SLAVE?=		DATA NCURSES
OPTIONS_EXCLUDE:=	${OPTIONS_SINGLE_UI}

UI_DESC=	User Interface
SOUND_DESC=	Sound support (SDL UI only)

NCURSES_USES=		ncurses
NCURSES_ALL_TARGET=	cataclysm
SDL_BUILD_DEPENDS=	convert:graphics/ImageMagick6
SDL_USE=		SDL=image2,ttf2
SDL_USES=		pkgconfig sdl
SDL_MAKE_ARGS=		TILES=1
SDL_ALL_TARGET=		cataclysm-tiles
SDL_DESKTOP_ENTRIES=	"Cataclysm: DDA" "${COMMENT}" "cataclysm" "cataclysm-tiles" "Game;" ""
NLS_USES=		gettext gettext-runtime iconv localbase
NLS_MAKE_ARGS=		LANGUAGES=all
NLS_MAKE_ARGS_OFF=	LOCALIZE=0
NLS_ALL_TARGET=		localization
SOUND_USE=		SDL=mixer2
SOUND_MAKE_ARGS=	SOUND=1
SOUND_IMPLIES=		SDL

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang && ${COMPILER_VERSION} >= 36
CXXFLAGS+=	-Wno-inconsistent-missing-override
.endif

.if ${CHOSEN_COMPILER_TYPE} == gcc
CPPFLAGS+=	-DCATA_NO_CPP11_STRING_CONVERSIONS
.endif

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|--mode=|-m | ; \
		 s|--no-preserve=ownership|| ; \
		 s|LDFLAGS += -lintl -liconv|LDFLAGS += -L${LOCALBASE}/lib -lintl| ; \
		 s|-t ||' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|/usr/local/share/fonts|${LOCALBASE}/share/fonts|' \
		${WRKSRC}/src/sdltiles.cpp

post-patch-NLS-off:
	 @${REINPLACE_CMD} -e \
		'/LOCALE_DIR/s|^|#|' \
		${WRKSRC}/Makefile

post-install-NCURSES-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cataclysm

post-install-SDL-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cataclysm-tiles
.for size in 16x16 24x24 32x32 48x48 64x64 128x128
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}/apps
	@convert -verbose -resize ${size} ${STAGEDIR}${DATADIR}/cataicon.ico \
		-unsharp 0x6 ${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}/apps/cataclysm.png
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . \
		${STAGEDIR}${DOCSDIR})
.if ${PORT_OPTIONS:MNCURSES}
	@${INSTALL_MAN} ${STAGEDIR}${DOCSDIR}/cataclysm.6 \
		${STAGEDIR}${MANPREFIX}/share/man/man6
.endif
.if ${PORT_OPTIONS:MSDL}
	@${INSTALL_MAN} ${STAGEDIR}${DOCSDIR}/cataclysm-tiles.6 \
		${STAGEDIR}${MANPREFIX}/share/man/man6
.endif
	@${RM} ${STAGEDIR}${DOCSDIR}/cataclysm.6 ${STAGEDIR}${DOCSDIR}/cataclysm-tiles.6

.include <bsd.port.post.mk>
