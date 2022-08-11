PORTNAME=	cataclysm-dda
DISTVERSION=	0.F
PORTREVISION?=	0
PORTEPOCH=	1
CATEGORIES=	games

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Roguelike set in a post-apocalyptic world

LICENSE=	CC-BY-SA-3.0
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		alias compiler:c++14-lang gmake shebangfix
SHEBANG_FILES=	lang/*.sh
bash_CMD=	/bin/sh

USE_GITHUB=	yes
GH_ACCOUNT=	CleverRaven
GH_PROJECT=	Cataclysm-DDA

MAKE_ARGS=	CXX="${CXX}" LD="${CXX}" RELEASE=1 WARNINGS=-w USE_XDG_DIR=1 ASTYLE=0

OPTIONS_DEFINE=		NLS DATA DOCS SOUND
OPTIONS_DEFAULT=	NLS
OPTIONS_SINGLE=		UI
OPTIONS_SINGLE_UI=	NCURSES SDL
OPTIONS_EXCLUDE:=	${OPTIONS_SINGLE_UI}
OPTIONS_SLAVE?=		DATA NCURSES
OPTIONS_SUB=		yes

SOUND_DESC=	Sound support (SDL UI only)
UI_DESC=	User Interface

NCURSES_USES=		ncurses
NCURSES_ALL_TARGET=	cataclysm
NLS_USES=		gettext gettext-runtime iconv localbase
NLS_MAKE_ARGS=		LANGUAGES=all
NLS_MAKE_ARGS_OFF=	LOCALIZE=0
NLS_ALL_TARGET=		localization
SDL_USES=		pkgconfig sdl
SDL_USE=		SDL=image2,ttf2
SDL_MAKE_ARGS=		TILES=1
SDL_ALL_TARGET=		cataclysm-tiles
SOUND_IMPLIES=		SDL
SOUND_USE=		SDL=mixer2
SOUND_MAKE_ARGS=	SOUND=1

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

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . \
		${STAGEDIR}${DOCSDIR})
.if ${PORT_OPTIONS:MNCURSES}
	${INSTALL_MAN} ${STAGEDIR}${DOCSDIR}/cataclysm.6 \
		${STAGEDIR}${MANPREFIX}/share/man/man6
.endif
.if ${PORT_OPTIONS:MSDL}
	${INSTALL_MAN} ${STAGEDIR}${DOCSDIR}/cataclysm-tiles.6 \
		${STAGEDIR}${MANPREFIX}/share/man/man6
.endif
	@${RM} ${STAGEDIR}${DOCSDIR}/cataclysm.6 ${STAGEDIR}${DOCSDIR}/cataclysm-tiles.6

post-install-NCURSES-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cataclysm

post-install-SDL-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cataclysm-tiles

.include <bsd.port.post.mk>
