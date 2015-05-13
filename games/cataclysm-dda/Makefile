# Created by: Vladimir Kondratiev <wulf@cicgroup.ru>
# $FreeBSD$

PORTNAME=	cataclysm-dda
PORTVERSION=	0.B
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	GH http://azmodean.polehammer.com/:sound
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fork/variant of Cataclysm Roguelike by Whales

LICENSE=	CCPL.BY-SA.30
LICENSE_NAME=	Creative Commons Attribution-ShareAlike 3.0 Unported License
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		gmake shebangfix compiler:c++11-lib execinfo
SHEBANG_FILES=	lang/*.sh
bash_CMD=	/bin/sh

USE_GITHUB=	yes
GH_ACCOUNT=	CleverRaven
GH_PROJECT=	Cataclysm-DDA
MAKE_ARGS+=	PREFIX=${PREFIX} RELEASE=1 USE_HOME_DIR=1
CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-Wl,-rpath=${_GCC_RUNTIME} -L${LOCALBASE}/lib -lexecinfo


MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	NLS DOCS LUA SOUND
OPTIONS_DEFAULT=NLS DOCS NCURSES
OPTIONS_SINGLE=	UI
OPTIONS_SINGLE_UI=	NCURSES SDL

UI_DESC=	User Interface
SOUND_DESC=	Sound support (SDL UI only)

OPTIONS_SUB=	yes
REINPLACE_ARGS=	-i ''

NCURSES_USES=	ncurses
SDL_USE=	SDL=sdl2,ttf2,image2
SDL_USES=	pkgconfig
SDL_MAKE_ARGS=	TILES=1 TILESTARGET=cataclysm
SDL_FETCH_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/x11-fonts/terminus-font:patch
SDL_BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf
NLS_USES=	gettext
NLS_LDFLAGS=	-lintl
NLS_MAKE_ARGS=	LOCALIZE=1
LUA_USES=	lua:51 pkgconfig
LUA_MAKE_ARGS=	LUA=1

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang && ${COMPILER_VERSION} >= 36
CXXFLAGS+=	-Wno-inconsistent-missing-override
.endif

.if ${PORT_OPTIONS:MSOUND}
.if ${PORT_OPTIONS:MSDL}
MAKE_ARGS+=	SOUND=1
USE_SDL+=	mixer2
SOUND_FILES=	cataclysmthemeREV6.ogg Dark_Days_Ahead_demo_2.ogg
DISTFILES+=	${SOUND_FILES:S|$|:sound|}
.else
IGNORE=		Sound is not supported with ncurses UI.
.endif
.endif

post-patch:
	${REINPLACE_CMD} -e '/^ *CXX *=/d ; /^ *LD *=/s/g++/$$(CXX)/ ; \
		/^ *CXXFLAGS *+*=/s/-O[s0-3]//; /^ *LOCALIZE *=/d ; \
		s/\(-lncurses\)\(w*\)/\1\2 -ltinfo\2/ ; \
		s/=$$(PREFIX)\//=$$(DESTDIR)$$(PREFIX)\// ; \
		/install/s/--mode=/-m / ; s/ -t\( $$(DATA_PREFIX)\)/\1/ ; \
		/cp -R/s/--no-preserve=ownership// ; \
		/^ *LUA_BINARY *=/s/lua/${LUA_CMD}/' ${WRKSRC}/Makefile
.if ! ${PORT_OPTIONS:MNLS}
	${REINPLACE_CMD} -e '/LOCALE_DIR/s/^/#/' ${WRKSRC}/Makefile
.endif
.if ${PORT_OPTIONS:MNCURSES} && ${NCURSESBASE} == /usr
	${REINPLACE_CMD} -e 's/$$(shell ncursesw5-config --libs)/-lncursesw/ ; \
		/$$(shell ncursesw5-config --cflags)/d' ${WRKSRC}/Makefile
.endif
.if ${PORT_OPTIONS:MSDL}
	${REINPLACE_CMD} -e '/"file":/s|gfx|${DATADIR}/&|' \
		${WRKSRC}/gfx/*/tile_config.json
	# replace bundled windows version of terminus font with X-compatible one
	${CAT} `cd ${PORTSDIR}/x11-fonts/terminus-font; make -V WRKSRC`/ter-u14n.bdf \
		| bdftopcf | ${GZIP_CMD} > ${WRKSRC}/data/font/terminus.fon
.endif

post-install:
.if ${PORT_OPTIONS:MSOUND}
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} sound ${STAGEDIR}${DATADIR}
	cd ${DISTDIR} && \
		${INSTALL_DATA} ${SOUND_FILES} ${STAGEDIR}${DATADIR}/sound
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${FIND} ${WRKSRC} \( -name "*.md" -or -name "*.txt" \) \
		-exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/ \;

.include <bsd.port.post.mk>
