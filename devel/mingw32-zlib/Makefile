# New ports collection makefile for:	mingw32-zlib
# Date created:		3 December 2011
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	zlib
PORTVERSION=	1.2.5
CATEGORIES=	devel archivers
MASTER_SITES=	http://zlib.net/
PKGNAMEPREFIX=	mingw32-

MAINTAINER=	knu@FreeBSD.org
COMMENT=	The zlib library cross-compiled for MinGW32

BUILD_DEPENDS=	${PKGNAMEPREFIX}gcc:${PORTSDIR}/devel/${PKGNAMEPREFIX}gcc

USE_BZIP2=	yes
USE_GMAKE=	yes
MAKEFILE=	win32/Makefile.gcc
MAKE_ARGS=	PREFIX=${PKGNAMEPREFIX} \
		BINARY_PATH=${PREFIX}/mingw32/bin \
		INCLUDE_PATH=${PREFIX}/mingw32/include \
		LIBRARY_PATH=${PREFIX}/mingw32/lib

.include <bsd.port.mk>
