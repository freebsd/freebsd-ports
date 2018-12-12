# $FreeBSD$

PORTNAME=	pbbam
DISTVERSION=	g20180416
PORTREVISION=	3
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	PacBio BAM C++ library, with SWIG bindings

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	boost-libs>=1.60.0:devel/boost-libs
LIB_DEPENDS=	libhts.so:biology/htslib \
		libboost_regex.so:devel/boost-libs

USES=		cmake compiler:c++14-lang pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	PacificBiosciences
GH_TAGNAME=	c6b8113adb5104948879e9ff69f739121f12a09f

# Disable tests for now.  Bound to bundled googletest.
CMAKE_ARGS+=	-DHTSLIB_INCLUDE_DIRS:STRING=${LOCALBASE}/include/htslib \
		-DHTSLIB_LIBRARIES:STRING="-L${LOCALBASE}/lib -lhts" \
		-DPacBioBAM_build_tests:BOOL=OFF \
		-DPacBioBAM_build_docs:BOOL=OFF

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/* ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${BUILD_WRKSRC}/lib/* ${STAGEDIR}${PREFIX}/lib
	cd ${WRKSRC}/include && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include
	${MV} ${STAGEDIR}${PREFIX}/include/meson.build \
		${STAGEDIR}${PREFIX}/include/pbbam

.include <bsd.port.mk>
