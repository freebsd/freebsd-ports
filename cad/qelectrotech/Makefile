PORTNAME=	qelectrotech
DISTVERSION=	0.100
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}-source-mirror/releases/download/${DISTVERSION}/
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

PATCH_SITES=	https://github.com/${PORTNAME}/${PORTNAME}-source-mirror/commit/
PATCHFILES=	d0cea474a6cc45b28114ba158061d42c0cfed484.patch:-p1

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Application to design electric diagrams
WWW=		https://qelectrotech.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers

USES=		cmake desktop-file-utils gl pkgconfig qt:6 \
		shared-mime-info
USE_GL=		gl
USE_QT=		base svg tools

USE_GITHUB=	nodefault
GH_TUPLE=	catchorg:Catch2:v2.13.10:catch2/_deps/catch2-src \
		google:googletest:v1.17.0:gtest/_deps/gtest-src \
		zeux:pugixml:v1.11.4:pugixml/_deps/pugixml-src \
		itay-grudev:SingleApplication:v3.2.0:SA/_deps/singleapplication-src

CMAKE_OFF=	BUILD_WITH_KF5

pre-configure:
	@${MKDIR} ${BUILD_WRKSRC}
	${MV} ${WRKSRC}/_deps ${BUILD_WRKSRC}

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/include/gmock \
		${STAGEDIR}${PREFIX}/include/gtest \
		${STAGEDIR}${PREFIX}/lib/cmake/GTest \
		${STAGEDIR}${PREFIX}/lib/cmake/pugixml
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/cmake

.include <bsd.port.mk>
