# Created by: Johannes Dieterich <dieterich@ogolem.org>
# $FreeBSD$

PORTNAME=	clpeak
PORTVERSION=	1.0g20170524
CATEGORIES=	benchmarks

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Benchmarking tool to measure peak capabilities of opencl devices

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	opencl>=0:devel/opencl
LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd
RUN_DEPENDS=	opencl>=0:devel/opencl

ONLY_FOR_ARCHS=	amd64

USE_GITHUB=	yes
GH_ACCOUNT=	krrishnarraj
GH_TAGNAME=	75c8746

USE_LDCONFIG=	yes
USE_GL=		gl
USES=		cmake:insource

CXXFLAGS+=	-std=c++11

PLIST_FILES=	bin/clpeak

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/clpeak ${STAGEDIR}${PREFIX}/bin/clpeak

.include <bsd.port.mk>
