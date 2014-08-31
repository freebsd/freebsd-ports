# Created by: Vladimir Kondratiev <wulf@cicgroup.ru>
# $FreeBSD$

PORTNAME=	cataclysm-dda
PORTVERSION=	0.9
CATEGORIES=	games

MAINTAINER=	wulf@cicgroup.ru
COMMENT=	Fork/variant of Cataclysm Roguelike by Whales

LICENSE=	CCPL.BY-SA.30
LICENSE_NAME=	Creative Commons Attribution-ShareAlike 3.0 Unported License
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		gmake shebangfix
SHEBANG_FILES=	lang/*.sh
bash_CMD=	/bin/sh

USE_GITHUB=	yes
GH_ACCOUNT=	CleverRaven
GH_PROJECT=	Cataclysm-DDA
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	ebd2393
MAKE_ARGS+=	RELEASE=1
CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	NLS DOCS
OPTIONS_DEFAULT=NCURSES
OPTIONS_SINGLE=	UI
OPTIONS_SINGLE_UI=	NCURSES SDL

UI_DESC=	User Interface

OPTIONS_SUB=	yes
SUB_FILES=	cataclysm
REINPLACE_ARGS=	-i ''

NCURSES_USES=	ncurses
SDL_USE=	SDL=sdl,ttf,image
SDL_MAKE_ARGS=	TILES=1 TILESTARGET=cataclysm
NLS_USES=	gettext
NLS_LDFLAGS=	-lintl
NLS_MAKE_ARGS=	L10N=localization

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MNLS}
MAKE_ARGS+=	LOCALIZE=0
.endif

post-extract:
	${RM} ${WRKSRC}/data/.gitignore

post-patch:
	${REINPLACE_CMD} -e 's|"lang/mo"|"${PREFIX}/share/locale"|' ${WRKSRC}/main.cpp
	cd ${WRKSRC} && ${REINPLACE_CMD} -e 's|gfx|${DATADIR}/&|' options.cpp \
		sdltiles.cpp cata_tiles.cpp gfx/*/tileset.txt
	cd ${WRKSRC} && ${REINPLACE_CMD} -e 's|data/json|${DATADIR}/&|' \
		game.cpp init.cpp map.cpp sdltiles.cpp
	cd ${WRKSRC} && ${REINPLACE_CMD} -e 's|data/raw|${DATADIR}/&|' \
		input.cpp iuse_software_sokoban.cpp
	${REINPLACE_CMD} -e 's|data/font["/]|${DATADIR}/&| ; \
		s|data/FONTDATA|${DATADIR}/&|' ${WRKSRC}/sdltiles.cpp
	${REINPLACE_CMD} -e 's|data/motd|${DATADIR}/&| ; \
		s|data/credits|${DATADIR}/&|' ${WRKSRC}/main_menu.cpp
	${REINPLACE_CMD} -e '/^CXX *=/d ; /^LD *=/s/g++/$$(CXX)/ ; \
		/OTHERS += -O3/d ; s/\(-lncurses\)\(w*\)/\1\2 -ltinfo\2/ ; \
		/^WARNINGS *=/d' ${WRKSRC}/Makefile

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/cataclysm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/cataclysm ${STAGEDIR}${PREFIX}/libexec
.for dir in data gfx
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${STAGEDIR}${DATADIR}
.endfor
.if ${PORT_OPTIONS:MNLS}
	cd ${WRKSRC}/lang/mo && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/locale
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${FIND} ${WRKSRC} \( -name "*.md" -or -name "*.txt" \) \
		-exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/ \;

.include <bsd.port.mk>
