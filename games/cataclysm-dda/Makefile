# Created by: Vladimir Kondratiev <wulf@cicgroup.ru>
# $FreeBSD$

PORTNAME=		cataclysm-dda
DISTVERSION=		0.C-26605
PORTREVISION=	1
DISTVERSIONSUFFIX=	-g2009bc2950
PORTEPOCH=		1
CATEGORIES=		games

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Roguelike set in a post-apocalyptic world

LICENSE=	CC-BY-SA-3.0
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		alias compiler:c++14-lang gmake shebangfix
SHEBANG_FILES=	lang/*.sh gfx/make_iso.py
bash_CMD=	/bin/sh
python_CMD=	${LOCALBASE}/bin/python2.7

USE_GITHUB=	yes
GH_ACCOUNT=	CleverRaven
GH_PROJECT=	Cataclysm-DDA

MAKE_ARGS=	CXX="${CXX}" LD="${CXX}" RELEASE=1 WARNINGS=-w USE_XDG_DIR=1

PORTDOCS=	*

OPTIONS_DEFINE=		NLS DOCS LUA SOUND
OPTIONS_DEFAULT=	NLS NCURSES LUA
OPTIONS_SINGLE=		UI
OPTIONS_SINGLE_UI=	NCURSES SDL
OPTIONS_SUB=		yes

UI_DESC=	User Interface
SOUND_DESC=	Sound support (SDL UI only)

NCURSES_USES=			ncurses
SDL_CONFLICTS_INSTALL=		${PORTNAME}-[0-9]*
SDL_CONFLICTS_INSTALL_OFF=	${PORTNAME}-sdl-[0-9]*
SDL_USE=			SDL=image2,ttf2
SDL_USES=			pkgconfig
SDL_MAKE_ARGS=			TILES=1 TILESTARGET=cataclysm
SDL_CPPFLAGS=			$$(sdl2-config --cflags)
SDL_LDFLAGS=			$$(sdl2-config --libs)
SDL_DESKTOP_ENTRIES=		"Cataclysm: DDA" "" "" "cataclysm" "" ""
NLS_USES=			gettext iconv localbase
NLS_MAKE_ARGS=			LANGUAGES=all
NLS_MAKE_ARGS_OFF=		LOCALIZE=0
LUA_USES=			lua:53 pkgconfig
LUA_MAKE_ARGS=			LUA=1 LUA_BINARY="${LUA_CMD}"
SOUND_MASTER_SITES=		http://polehammer.com/azmodean/:sound
SOUND_DISTFILES=		${SOUND_FILES:S/$/:sound/}
SOUND_EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}
SOUND_USE=			SDL=mixer2
SOUND_MAKE_ARGS=		SOUND=1
SOUND_IMPLIES=			SDL

SOUND_FILES=	cataclysmthemeREV6.ogg Dark_Days_Ahead_demo_2.ogg

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang && ${COMPILER_VERSION} >= 36
CXXFLAGS+=	-Wno-inconsistent-missing-override
.endif

.if ${CHOSEN_COMPILER_TYPE} == gcc
CPPFLAGS+=	-DCATA_NO_CPP11_STRING_CONVERSIONS
.endif

post-patch:
	 @${REINPLACE_CMD} -e \
		's|--mode=|-m | ; \
		 s|--no-preserve=ownership|| ; \
		 s|-t ||' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|/usr/local/share/fonts|${LOCALBASE}/share/fonts|' \
		${WRKSRC}/src/sdltiles.cpp
	@${REINPLACE_CMD} -e \
		's|.wav|.ogg|' \
		${WRKSRC}/data/sound/Basic/musicset.json

post-patch-NLS-off:
	 @${REINPLACE_CMD} -e \
		'/LOCALE_DIR/s|^|#|' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cataclysm

post-install-SOUND-on:
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} sound ${STAGEDIR}${DATADIR}
	cd ${DISTDIR} && ${INSTALL_DATA} ${SOUND_FILES} \
		${STAGEDIR}${DATADIR}/sound/Basic

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.post.mk>
