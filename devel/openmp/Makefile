# $FreeBSD$

PORTNAME=	openmp
DISTVERSION=	9.0.0
DISTVERSIONSUFFIX=	.src
CATEGORIES=	devel
MASTER_SITES=	http://llvm.org/releases/${DISTVERSION}/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Open Multi-Processing runtime for LLVM/Clang

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Part of base system since FreeBSD 11.3/12.1
EXPIRATION_DATE=	2020-02-01
ONLY_FOR_ARCHS=	amd64 i386 powerpc64

USES=		cmake compiler:c++11-lib perl5 tar:xz
USE_PERL5=	build
USE_LDCONFIG=	yes
TEST_TARGET=	libomp-micro-tests
PLIST_FILES=	include/omp.h \
		include/ompt.h \
		include/omp-tools.h \
		lib/libgomp.so \
		lib/libiomp5.so \
		lib/libomp.so \
		lib/libomptarget.so

.include <bsd.port.mk>
