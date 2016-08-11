# Created by: Johannes Dieterich <dieterich@ogolem.org>
# $FreeBSD$

PORTNAME=	aparapi
PORTVERSION=	1.0.0
DISTVERSIONSUFFIX=	-SNAPSHOT
CATEGORIES=	java lang

MAINTAINER=	dieterich@ogolem.org
COMMENT=	Open source API for expressing data parallel workflows in Java

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

BUILD_DEPENDS=	opencl>=0:devel/opencl
LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd
RUN_DEPENDS=	opencl>=0:devel/opencl

ONLY_FOR_ARCHS=	amd64 i386

USE_GITHUB=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.7+
USE_ANT=	yes
ALL_TARGET=	dist

USES=		dos2unix

do-install:
		(cd ${WRKSRC}/dist_freebsd && ${INSTALL_DATA} aparapi.jar ${STAGEDIR}${JAVAJARDIR})
		(cd ${WRKSRC}/dist_freebsd && ${INSTALL_LIB} libaparapi.so ${STAGEDIR}${PREFIX}/lib)

.include <bsd.port.mk>
