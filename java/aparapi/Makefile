PORTNAME=	aparapi
PORTVERSION=	1.0.0
PORTREVISION=	2
DISTVERSIONSUFFIX=	-SNAPSHOT
CATEGORIES=	java lang

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source API for expressing data parallel workflows in Java
WWW=		https://github.com/aparapi/aparapi

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

BUILD_DEPENDS=	opencl>=0:devel/opencl
LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd
RUN_DEPENDS=	opencl>=0:devel/opencl

USES=		dos2unix java:ant,run
USE_GITHUB=	yes
JAVA_VERSION=	8 11 17

ONLY_FOR_ARCHS=	amd64 powerpc64 powerpc64le

ALL_TARGET=	dist

do-install:
		(cd ${WRKSRC}/dist_freebsd && ${INSTALL_DATA} aparapi.jar ${STAGEDIR}${JAVAJARDIR})
		(cd ${WRKSRC}/dist_freebsd && ${INSTALL_LIB} libaparapi.so ${STAGEDIR}${PREFIX}/lib)

.include <bsd.port.mk>
