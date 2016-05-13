# $FreeBSD$

PORTNAME=	openmp
PORTVERSION=	3.8.0
DISTVERSIONSUFFIX=	.src
CATEGORIES=	devel
MASTER_SITES=	http://llvm.org/releases/${PORTVERSION}/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Support for the OpenMP language

LICENSE=	MIT

USES=	tar:xz cmake
USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	i386 amd64
PLIST_FILES=	include/omp.h \
		lib/libgomp.so \
		lib/libiomp5.so \
		lib/libomp.so

.include <bsd.port.mk>
