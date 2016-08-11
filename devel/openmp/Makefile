# $FreeBSD$

PORTNAME=	openmp
PORTVERSION=	3.8.0
PORTREVISION=	2
DISTVERSIONSUFFIX=	.src
CATEGORIES=	devel
MASTER_SITES=	http://llvm.org/releases/${PORTVERSION}/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Support for the OpenMP language

LICENSE=	MIT

USES=	tar:xz cmake perl5 compiler:c11
USE_PERL5=	build
USE_LDCONFIG=	yes
CMAKE_ARGS=	-DLIBOMP_LIBFLAGS:STRING="-Wl,-soname,libomp.so.0"
ONLY_FOR_ARCHS=	amd64 # i386
PLIST_FILES=	include/omp.h \
		lib/libgomp.so \
		lib/libiomp5.so \
		lib/libomp.so.0 \
		lib/libomp.so

post-install:
	${MV} ${STAGEDIR}${PREFIX}/lib/libomp.so ${STAGEDIR}${PREFIX}/lib/libomp.so.0
	${LN} -sf libomp.so.0 ${STAGEDIR}${PREFIX}/lib/libomp.so

.include <bsd.port.mk>
