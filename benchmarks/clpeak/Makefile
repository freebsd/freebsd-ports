# Created by: Johannes Dieterich <dieterich@ogolem.org>
# $FreeBSD$

PORTNAME=	clpeak
DISTVERSION=	1.1.0
CATEGORIES=	benchmarks

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	db42d30028ba.patch:-p1 # https://github.com/krrishnarraj/clpeak/issues/73

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

.if !empty(PATCHFILES:Mdb42d30028ba*)
pre-patch:
	@${REINPLACE_CMD} -e '/GIT_TAG/s/master/opencl21/' \
		${WRKSRC}/cmake/BuildCLHpp.cmake
.endif

post-patch:
	@${REINPLACE_CMD} '/install.*LICENSE/d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
