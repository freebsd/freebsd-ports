PORTNAME=	sc3-plugins
DISTVERSIONPREFIX=	Version-
DISTVERSION=	3.13.0
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Extension plugins for the SuperCollider3 audio synthesis server
WWW=		https://github.com/supercollider/sc3-plugins

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

BUILD_DEPENDS=	${LOCALBASE}/include/SuperCollider/SCVersion.txt:audio/supercollider \
		${LOCALBASE}/include/boost/intrusive/unordered_set.hpp:devel/boost-libs \
		${LOCALBASE}/include/fftw3.h:math/fftw3
LIB_DEPENDS=	libfftw3f.so:math/fftw3-float \
		libstk.so:audio/stk

USES=		compiler:c++14-lang cmake localbase pkgconfig
USE_CXXSTD=	c++14 # change to C++14 to fix build, because C++14 features are used

USE_GITHUB=	yes
GH_ACCOUNT=	supercollider
GH_TUPLE=	timblechmann:nova-simd:3140689:n/external_libraries/nova-simd

CMAKE_ARGS+=	-DSYSTEM_STK:BOOL=ON
CMAKE_ARGS+=	-DSC_PATH:STRING=${LOCALBASE}/include/SuperCollider/ # see https://github.com/supercollider/sc3-plugins/issues/170
CMAKE_OFF=	CPP11 # change to C++14 to fix build, because C++14 features are used

OPTIONS_DEFINE=		SUPERNOVA
OPTIONS_DEFAULT=	SUPERNOVA
OPTIONS_SUB=		yes

SUPERNOVA_DESC=		Build plugins for supernova
SUPERNOVA_CMAKE_BOOL=	SUPERNOVA

post-patch:
	@${REINPLACE_CMD} -e ' \
		s|/usr/local|${PREFIX}|' \
		${WRKSRC}/cmake_modules/*.cmake

.include <bsd.port.mk>
