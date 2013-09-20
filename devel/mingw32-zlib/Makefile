# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	zlib
PORTVERSION=	1.2.7
PORTREVISION=	1
CATEGORIES=	devel archivers
MASTER_SITES=	http://zlib.net/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	libpng/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	mingw32-

MAINTAINER=	knu@FreeBSD.org
COMMENT=	The zlib library cross-compiled for MinGW32

BUILD_DEPENDS=	${PKGNAMEPREFIX}gcc:${PORTSDIR}/devel/${PKGNAMEPREFIX}gcc \
		${LOCALBASE}/mingw32/include/sys/types.h:${PORTSDIR}/devel/${PKGNAMEPREFIX}bin-msvcrt

USE_XZ=		yes
USE_GMAKE=	yes
MAKEFILE=	win32/Makefile.gcc
MAKE_ARGS=	PREFIX=${PKGNAMEPREFIX} \
		BINARY_PATH=${CROSS_BASE}/bin \
		INCLUDE_PATH=${CROSS_BASE}/include \
		LIBRARY_PATH=${CROSS_BASE}/lib
CROSS_BASE=	${PREFIX}/mingw32

NO_STAGE=	yes
.include <bsd.port.mk>
