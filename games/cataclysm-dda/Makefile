PORTNAME=	cataclysm-dda
DISTVERSION=	0.G
PORTREVISION?=	0
PORTEPOCH=	1
CATEGORIES=	games

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Roguelike set in a post-apocalyptic world
WWW=		https://cataclysmdda.org

LICENSE=	CC-BY-SA-3.0
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

FLAVORS?=	curses
FLAVOR?=	curses

USES=		alias cmake compiler:c++14-lang shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	CleverRaven
GH_PROJECT=	Cataclysm-DDA

SHEBANG_FILES=	lang/*.sh
bash_CMD=	/bin/sh

CMAKE_OFF=	BACKTRACE TESTS
CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_Git

.if ${FLAVOR} == tiles

USES+=		pkgconfig sdl
USE_SDL=	image2 mixer2 ttf2
CMAKE_ARGS+=	-DLOCALIZE=OFF \
		-DSOUND=1 \
		-DTILES=1
PLIST_SUB+=	CURSES="@comment " \
		TILES=""

.else

USES+=		ncurses
CMAKE_ARGS+=	-DCURSES_INCLUDE_PATH:STRING="${NCURSESINC}"

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext-tools
NLS_CMAKE_OFF=	-DLOCALIZE=OFF
PLIST_SUB+=	CURSES="" \
		TILES="@comment "
PORTDOCS=	*

.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%DISTVERSION%%|${DISTVERSION}|' ${WRKSRC}/src/version.cmake

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/cataclysm.6 ${STAGEDIR}${PREFIX}/share/man/man6
	${INSTALL_MAN} ${WRKSRC}/doc/cataclysm-tiles.6 ${STAGEDIR}${PREFIX}/share/man/man6

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
