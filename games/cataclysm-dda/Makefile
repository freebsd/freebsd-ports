PORTNAME=	cataclysm-dda
PORTVERSION=	0.H			# Preserve PORTVERSION so uppercase is respected
DISTVERSIONSUFFIX=	-g08f04fd	# Using TAG instead of upstream 0.H-RELEASE
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	games

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	1ab7d1793b3a34779e4616b8c0c7fab37a6da3be.patch:-p1 # Fix build with clang 19 \
		https://github.com/CleverRaven/Cataclysm-DDA/issues/77355

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Roguelike set in a post-apocalyptic world
WWW=		https://cataclysmdda.org

LICENSE=	CC-BY-SA-3.0
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

FLAVORS=	curses tiles
FLAVOR?=	curses
FLAVORS_SUB=	yes

tiles_PKGNAMESUFFIX=		-tiles
tiles_LIB_DEPENDS=		libFLAC.so:audio/flac
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
NLS_CMAKE_OFF=	-DLOCALIZE=OFF
PORTDOCS=	*

.if ${FLAVOR} == tiles

USES+=		pkgconfig sdl
USE_SDL=	image2 mixer2 ttf2
CMAKE_ON+=	SOUND TILES

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

.include <bsd.port.mk>
