# Created by: adamw
# $FreeBSD$

PORTNAME=	lz4
PORTVERSION=	1.8.2
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	archivers
PKGNAMEPREFIX=	lib

MAINTAINER=	martin@waschbuesch.de
COMMENT=	LZ4 compression library, lossless and very fast

LICENSE=	BSD2CLAUSE GPLv2
LICENSE_COMB=	multi

USES=		gmake pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes
MAKE_ARGS=	PREFIX="${PREFIX}" LIBDIR="${PREFIX}/lib" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		MANDIR="${MAN1PREFIX}/man"

.include <bsd.port.mk>
