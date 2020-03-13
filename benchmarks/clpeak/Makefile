# Created by: Johannes Dieterich <dieterich@ogolem.org>
# $FreeBSD$

PORTNAME=	clpeak
DISTVERSION=	1.1.0-rc2
CATEGORIES=	benchmarks

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Benchmarking tool to measure peak capabilities of opencl devices

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	opencl>=0:devel/opencl
LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	krrishnarraj
USE_LDCONFIG=	yes
PLIST_FILES=	bin/clpeak

post-patch:
	@${REINPLACE_CMD} '/install.*LICENSE/d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
