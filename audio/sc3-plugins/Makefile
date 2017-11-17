# $FreeBSD$

PORTNAME=	sc3-plugins
DISTVERSION=	3.8.0
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Extension plugins for the SuperCollider3 audio synthesis server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

BUILD_DEPENDS=	${LOCALBASE}/include/SuperCollider/SCVersion.txt:audio/supercollider \
		${LOCALBASE}/include/boost/intrusive/unordered_set.hpp:devel/boost-libs \
		${LOCALBASE}/include/fftw3.h:math/fftw3
LIB_DEPENDS=	libfftw3f.so:math/fftw3-float \
		libstk.so:audio/stk

OPTIONS_DEFINE=	SUPERNOVA
OPTIONS_DEFAULT=	SUPERNOVA
SUPERNOVA_DESC=	Build plugins for supernova
OPTIONS_SUB=	yes

USES=		cmake:outsource localbase pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	supercollider
GH_TAGNAME=	5342a4a
GH_TUPLE=	timblechmann:nova-simd:3140689:n/external_libraries/nova-simd
CMAKE_ARGS+=	-DSYSTEM_STK:BOOL=ON
CMAKE_ARGS+=	-DSC_PATH:STRING=${LOCALBASE}/include/SuperCollider/ # see https://github.com/supercollider/sc3-plugins/issues/170
SUPERNOVA_CMAKE_BOOL=	SUPERNOVA

post-patch:
	@${REINPLACE_CMD} -e ' \
		s|/usr/local|${PREFIX}|' \
		${WRKSRC}/cmake_modules/*.cmake

.include <bsd.port.mk>
