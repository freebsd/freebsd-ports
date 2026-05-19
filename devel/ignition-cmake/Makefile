PORTNAME=	ignition-cmake
DISTVERSIONPREFIX=	gz-cmake5_
DISTVERSION=	5.0.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CMake modules to be used by the Ignition projects
WWW=		https://gazebosim.org/home \
		https://github.com/gazebosim/gz-cmake

LICENSE=	APACHE20

USES=		cmake pkgconfig python:build,run ruby shebangfix

SHEBANG_FILES=	benchmark/run_benchmarks.py \
		codecheck/cpplint.py \
		tools/check_test_ran.py \
		tools/print_package_xml_version.py

CMAKE_OFF=	BUILD_TESTING

USE_GITHUB=	yes
GH_ACCOUNT=	gazebosim
GH_PROJECT=	gz-cmake

NO_ARCH=	yes

PLIST_SUB+=	CMAKE_IGN_VER=cmake${DISTVERSION:R:R}

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${PATCH_WRKSRC}/cmake/FindAVCODEC.cmake
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${PATCH_WRKSRC}/cmake/FindAVDEVICE.cmake
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${PATCH_WRKSRC}/cmake/FindAVFORMAT.cmake
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${PATCH_WRKSRC}/cmake/FindAVUTIL.cmake
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${PATCH_WRKSRC}/cmake/FindSWSCALE.cmake

.include <bsd.port.mk>
