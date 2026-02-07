PORTNAME=	ignition-cmake
DISTVERSION=	2.0.0
CATEGORIES=	devel
MASTER_SITES=	https://bitbucket.org/${BB_ACCOUNT}/${BB_PROJECT}/get/${BB_COMMIT}.tar.gz?dummy=/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CMake modules to be used by the Ignition projects
WWW=		https://ignitionrobotics.org/home

LICENSE=	APACHE20

USES=		cmake pkgconfig ruby

CMAKE_OFF=	BUILD_TESTING

BB_ACCOUNT=	ignitionrobotics
BB_PROJECT=	ign-cmake
BB_COMMIT=	776c2bfe1d18

WRKSRC=		${WRKDIR}/${BB_ACCOUNT}-${BB_PROJECT}-${BB_COMMIT}
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
