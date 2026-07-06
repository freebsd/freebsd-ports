PORTNAME=	cataclysm-dda
PORTVERSION=	0.I # Preserve PORTVERSION so uppercase is respected
PORTEPOCH=	1
CATEGORIES=	games

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Roguelike set in a post-apocalyptic world
WWW=		https://cataclysmdda.org

LICENSE=	CC-BY-SA-3.0
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

FLAVORS=	curses tiles
FLAVOR?=	curses
FLAVORS_SUB=	yes

tiles_PKGNAMESUFFIX=		-tiles
tiles_LIB_DEPENDS=		libFLAC.so:audio/flac \
				libfreetype.so:print/freetype2
curses_CONFLICTS_INSTALL=	cataclysm-dda-tiles
tiles_CONFLICTS_INSTALL=	cataclysm-dda

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	CleverRaven
GH_PROJECT=	Cataclysm-DDA

CMAKE_OFF=	BACKTRACE TESTS
CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_Git

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext-tools
NLS_CMAKE_ON=	-DCMAKE_INSTALL_LOCALEDIR="${PREFIX}/share/locale"
NLS_CMAKE_OFF=	-DLOCALIZE=OFF

PORTDOCS=	*

.if ${FLAVOR} == tiles

USES+=		pkgconfig sdl
USE_SDL=	image2 mixer2 ttf2
CMAKE_ON+=	SOUND TILES
CXXFLAGS+=	-I${LOCALBASE}/include/freetype2
LDFLAGS+=	-L${LOCALBASE}/lib

.else

USES+=		ncurses
CMAKE_ARGS+=	-DCURSES_INCLUDE_PATH:STRING="${NCURSESINC}"

.endif

PORTSCOUT=	limit:^0\.[A-Z]

CXXFLAGS+=	-Wno-error=for-loop-analysis

post-patch:
	@${REINPLACE_CMD} -e 's|%%DISTVERSION%%|${DISTVERSION}|' ${WRKSRC}/src/version.cmake

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/cataclysm.6 ${STAGEDIR}${PREFIX}/share/man/man6
	${INSTALL_MAN} ${WRKSRC}/doc/cataclysm-tiles.6 ${STAGEDIR}${PREFIX}/share/man/man6

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.options.mk>

# Clang 21.1.8 introduced stricter flow analysis on 16-CURRENT (2026-04-25)
# This workaround prevents build failure in math_parser.cpp and others.
# Ref: https://github.com/llvm/llvm-project/issues/154493
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1600017
CXXFLAGS+=	-Wno-error=missing-noreturn -Wno-error=deprecated-declarations
.endif

# Avoid build failure due to strict Clang range-loop warning combined with -Werror
CXXFLAGS+=		-Wno-error=range-loop-construct

.include <bsd.port.mk>
