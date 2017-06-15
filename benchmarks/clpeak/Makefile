# Created by: Johannes Dieterich <dieterich@ogolem.org>
# $FreeBSD$

PORTNAME=	clpeak
PORTVERSION=	1.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	benchmarks

MAINTAINER=	dieterich@ogolem.org
COMMENT=	Benchmarking tool to measure peak capabilities of opencl devices

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	opencl>=0:devel/opencl
LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd
RUN_DEPENDS=	opencl>=0:devel/opencl

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON_amd64=	only builds and is supported on amd64

USE_GITHUB=	yes
GH_ACCOUNT=	krrishnarraj
GH_PROJECT=	clpeak

USE_LDCONFIG=	yes
USE_GL=		gl
USES=		cmake

CXXFLAGS+=	-std=c++11

PLIST_FILES=	bin/clpeak

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/clpeak ${STAGEDIR}${PREFIX}/bin/clpeak

.include <bsd.port.mk>
