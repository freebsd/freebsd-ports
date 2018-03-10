# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	zlib
PORTVERSION=	1.2.8
PORTREVISION=	2
CATEGORIES=	devel archivers
MASTER_SITES=	http://zlib.net/ \
		SF/libpng/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	mingw32-

MAINTAINER=	knu@FreeBSD.org
COMMENT=	The zlib library cross-compiled for MinGW32

BUILD_DEPENDS=	${PKGNAMEPREFIX}gcc:devel/${PKGNAMEPREFIX}gcc \
		${LOCALBASE}/mingw32/include/sys/types.h:devel/${PKGNAMEPREFIX}bin-msvcrt

USES=		tar:xz gmake
MAKEFILE=	win32/Makefile.gcc
MAKE_ARGS=	PREFIX=${PKGNAMEPREFIX} \
		BINARY_PATH=${CROSS_BASE}/bin \
		INCLUDE_PATH=${CROSS_BASE}/include \
		LIBRARY_PATH=${CROSS_BASE}/lib
CROSS_BASE=	${PREFIX}/mingw32

.include <bsd.port.mk>
