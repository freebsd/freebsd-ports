PORTNAME=	burr-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
CATEGORIES=	games

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Puzzle solver
WWW=		https://burrtools.sourceforge.net/

LICENSE=	GPLv2+ # COPYING is GPLv3

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs
LIB_DEPENDS=	libpng.so:graphics/png \
		libfltk.so:x11-toolkits/fltk

USES=		gl localbase:ldflags lua:51 meson pkgconfig
USE_CXXSTD=	c++14
USE_GITHUB=	yes
USE_GL=		gl glu

DESKTOP_ENTRIES=	"Burr Tools" "" "burricons" "burrtools" "Game;LogicGame;" ""

PLIST_FILES=	bin/burrTxt bin/burrTxt2 bin/burrtools \
		share/pixmaps/burricons.png
PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

# delete bundled lua 5.1
post-extract:
	${GREP} -lv 'Burr Solver' ${WRKSRC}/src/lua | ${XARGS} ${RM}

pre-configure:
	${REINPLACE_CMD} -e 's/%%PKGVERSION%%/${PKGVERSION}/' ${WRKSRC}/meson.build

post-build:
	(cd ${WRKSRC} && uudecode ${FILESDIR}/burricons.png.uu)

do-install:
	(cd ${INSTALL_WRKSRC} && ${INSTALL_PROGRAM} burrTxt burrTxt2 burrtools \
		${STAGEDIR}${PREFIX}/bin)
	${INSTALL_DATA} ${WRKSRC}/burricons.png ${STAGEDIR}${PREFIX}/share/pixmaps

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
