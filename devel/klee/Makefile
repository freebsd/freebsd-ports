# $FreeBSD$

PORTNAME=	klee
PORTVERSION=	169327.138
CATEGORIES=	devel
MASTER_SITES=	http://cdn.bitbucket.org/arrowdodger/klee/downloads/

MAINTAINER=	6yearold@gmail.com
COMMENT=	Symbolic virtual machine for LLVM bitcode

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-11-18

BUILD_DEPENDS=	llvm-ar:${PORTSDIR}/devel/llvm \
		ccc-analyzer:${PORTSDIR}/lang/clang \
		${LOCALBASE}/lib/libstp.a:${PORTSDIR}/math/stp
RUN_DEPENDS=	llvm-ar:${PORTSDIR}/devel/llvm \
		ccc-analyzer:${PORTSDIR}/lang/clang

BROKEN=		fails to build

OPTIONS_DEFINE=	DEBUG

USES=		cmake:outsource
CMAKE_ARGS=	-DCMAKE_MODULE_PATH=${WRKSRC}/cmake/llvm-3.1-modules \
		-DKLEE_PATH_TO_LLVM_BUILD=${LOCALBASE}

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
WITH_DEBUG=	yes
.endif

.include <bsd.port.mk>
