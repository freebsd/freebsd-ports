PORTNAME=	ldc
PORTVERSION=	1.41.0
DISTVERSIONSUFFIX=	-src
CATEGORIES=	lang
MASTER_SITES=	https://github.com/ldc-developers/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		ldc2-${PORTVERSION}-freebsd-x86_64.tar.xz

MAINTAINER=	acm@FreeBSD.org
COMMENT=	LLVM-based D compiler
WWW=		https://wiki.dlang.org/LDC

LICENSE=	BSD3CLAUSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	The bootstrap compiler is provided only for x86_64

BUILD_DEPENDS=	${LOCALBASE}/llvm19/lib/libLLVM-19.so:devel/llvm19 # required for bootstrap
LIB_DEPENDS=	libconfig.so:devel/libconfig

USES=		llvm:lib,run,min=15,max=20 ninja cmake:insource pkgconfig

USE_LDCONFIG=	yes

CFLAGS+=	-fPIC

CMAKE_ARGS+=	-DLDC_INSTALL_PREFIX="${PREFIX}" \
		-DD_COMPILER="${WRKDIR}/ldc2-${PORTVERSION}-freebsd-x86_64/bin/ldmd2" \
		-DLLVM_CONFIG=${LOCALBASE}/bin/${LLVM_CONFIG} \
		-DBUILD_SHARED_LIBS="BOTH" \
		-DBUILD_LTO_LIBS=ON

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ldc-build-runtime
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ldc-profdata
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ldc-prune-cache
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ldc2
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ldmd2

.include <bsd.port.mk>
