PORTNAME=	OpenLoco
DISTVERSIONPREFIX=	v
DISTVERSION=	26.07.1
CATEGORIES=	games

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Open source re-implementation of Chris Sawyer's Locomotion
WWW=		https://openloco.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/sfl:devel/sfl-library \
		${LOCALBASE}/lib/cmake/GTest/GTestConfig.cmake:devel/googletest
LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libpng16.so:graphics/png \
		libSDL3.so:devel/sdl3 \
		libtbb.so:devel/onetbb \
		libyaml-cpp.so:devel/yaml-cpp

USES=		cmake localbase:ldflags openal pkgconfig
USE_GITHUB=	yes
GH_TUPLE=	OpenLoco:OpenGraphics:v0.1.9:graphics

# for std::execution::par
CXXFLAGS+=	-fexperimental-library

CMAKE_ARGS+=	-DPROJECT_VERSION=${DISTVERSIONFULL} \
		-DCMAKE_INSTALL_BINDIR=${DATADIR}

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
# ld: error: cannot preempt symbol: alcCreateContext
# See also https://github.com/johalun/lwjgl3-port/issues/7
LLD_UNSAFE=	yes
CMAKE_ARGS+=	-DENABLE_IPO=NO
.else
CMAKE_ARGS+=	-DENABLE_IPO=YES
.endif

post-extract:
	${MKDIR} ${CONFIGURE_WRKSRC}/_deps
	(cd ${WRKSRC_graphics} && ${RM} -r .github .gitignore LICENSE README.md)
	${FIND} ${WRKSRC_graphics} -name .gitkeep -delete
	${MV} ${WRKSRC_graphics} ${CONFIGURE_WRKSRC}/_deps/openloco_objects-src

post-stage:
	${RLN} ${STAGEDIR}${DATADIR}/OpenLoco ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.post.mk>
