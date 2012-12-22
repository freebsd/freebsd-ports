# $FreeBSD$

PORTNAME=	klee
PORTVERSION=	169327.138
CATEGORIES=	devel
MASTER_SITES=	http://cdn.bitbucket.org/arrowdodger/klee/downloads/

MAINTAINER=	6yearold@gmail.com
COMMENT=	Symbolic virtual machine for LLVM bitcode

BUILD_DEPENDS=	llvm-ar:${PORTSDIR}/devel/llvm \
		ccc-analyzer:${PORTSDIR}/lang/clang \
		${LOCALBASE}/lib/libstp.a:${PORTSDIR}/math/stp
RUN_DEPENDS=	llvm-ar:${PORTSDIR}/devel/llvm \
		ccc-analyzer:${PORTSDIR}/lang/clang

OPTIONS_DEFINE=	DEBUG

USE_CMAKE=	yes
CMAKE_OUTSOURCE=yes
CMAKE_ARGS=	-DCMAKE_MODULE_PATH=${WRKSRC}/cmake/llvm-3.1-modules \
		-DKLEE_PATH_TO_LLVM_BUILD=${LOCALBASE}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
WITH_DEBUG=	yes
.endif

.include <bsd.port.mk>
