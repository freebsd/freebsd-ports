# Created by: Vladimir Kondratiev <wulf@cicgroup.ru>
# $FreeBSD$

PORTNAME=	cataclysm-dda
PORTVERSION=	0.C
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fork/variant of Cataclysm Roguelike by Whales

LICENSE=	CC-BY-SA-3.0
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_aarch64=		fails to compile: comparison of integers of different signs: wchar_t and const int
BROKEN_armv6=		fails to compile: comparison of integers of different signs: wchar_t and const int
BROKEN_armv7=		fails to compile: comparison of integers of different signs: wchar_t and const int
BROKEN_powerpc64=	fails to compile: overmap.cpp: 'pow' is not a member of 'std'

USES=		alias compiler:c++11-lib gmake shebangfix
SHEBANG_FILES=	lang/*.sh
bash_CMD=	/bin/sh

USE_GITHUB=	yes
GH_ACCOUNT=	CleverRaven
GH_PROJECT=	Cataclysm-DDA

MAKE_ARGS=	CXX="${CXX}" LD="${CXX}" RELEASE=1

LDFLAGS+=	-lexecinfo

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	NLS DOCS LUA SOUND
OPTIONS_DEFAULT=NCURSES
OPTIONS_SINGLE=	UI
OPTIONS_SINGLE_UI=	NCURSES SDL
OPTIONS_SUB=	yes

UI_DESC=	User Interface
SOUND_DESC=	Sound support (SDL UI only)

NCURSES_USES=	ncurses
SDL_USE=	SDL=image2,ttf2
SDL_USES=	pkgconfig
SDL_MAKE_ARGS=	TILES=1 TILESTARGET=cataclysm
SDL_RUN_DEPENDS=terminus-font>0:x11-fonts/terminus-font
SDL_CPPFLAGS=	$$(sdl2-config --cflags)
SDL_LDFLAGS=	$$(sdl2-config --libs)
SDL_DESKTOP_ENTRIES="Cataclysm-DDA" "" "" "cataclysm" "" ""
NLS_USES=	gettext
NLS_LDFLAGS=	-L${LOCALBASE}/lib -lintl
NLS_MAKE_ARGS_OFF=LOCALIZE=0
NLS_CPPFLAGS=	-I${LOCALBASE}/include
LUA_USES=	lua pkgconfig
LUA_MAKE_ARGS=	LUA=1 LUA_BINARY="${LUA_CMD}"
SOUND_MASTER_SITES=	http://polehammer.com/azmodean/:sound
SOUND_DISTFILES=	${SOUND_FILES:S/$/:sound/}
SOUND_EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
SOUND_USE=		SDL=mixer2
SOUND_MAKE_ARGS=	SOUND=1
SOUND_IMPLIES=		SDL

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
		'/CXXFLAGS/s|-O[0-3s]|| ; \
		 /LDFLAGS/s|-s$$|| ; \
		 s|$$(shell ncursesw5-config --cflags)|| ; \
		 s|$$(shell ncursesw5-config --libs)|-lncursesw -ltinfow| ; \
		 s|\($$(CXX)\) \($$(DEFINES)\)|\1 $$(CPPFLAGS) \2| ; \
		 s|\([[:blank:]]\)\($$(DATA_PREFIX)\)|\1$$(DESTDIR)\2| ; \
		 s|\([[:blank:]]\)\($$(BIN_PREFIX)\)|\1$$(DESTDIR)\2| ; \
		 s|--mode=|-m | ; \
		 s|--no-preserve=ownership|| ; \
		 s|-t || ; \
		 s|\([[:blank:]]\)\($$(LOCALE_DIR)\)|\1$$(DESTDIR)\2| ; \
		 s|\(=\)\($$(LOCALE_DIR)\)|\1$$(DESTDIR)\2|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|/usr/local/share/fonts|${LOCALBASE}/share/fonts|' \
		${WRKSRC}/src/sdltiles.cpp

post-patch-NLS-off:
	 @${REINPLACE_CMD} -e \
		'/LOCALE_DIR/s|^|#|' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cataclysm
# replace bundled windows version of terminus font with X-compatible one
	${RM} ${STAGEDIR}${DATADIR}/font/terminus.fon
	${LN} -sf ${PREFIX}/share/fonts/terminus/ter-u14n.pcf.gz \
		${STAGEDIR}${DATADIR}/font/terminus.fon

post-install-SOUND-on:
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} sound ${STAGEDIR}${DATADIR}
	cd ${DISTDIR} && ${INSTALL_DATA} ${SOUND_FILES} \
		${STAGEDIR}${DATADIR}/sound

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.post.mk>
