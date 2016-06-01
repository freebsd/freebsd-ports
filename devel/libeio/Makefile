# Created by: Sergey A. Osokin <osa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libeio
PORTVERSION=	4.18
DISTVERSIONPREFIX=	${PORTNAME}-
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Full-featured asynchronous I/O library for C

USE_GITHUB=	yes
GH_ACCOUNT=	scunningham
USES=		alias autoreconf libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

PLIST_FILES=	include/eio.h lib/libeio.a lib/libeio.so \
		lib/libeio.so.1 lib/libeio.so.1.0.0

.include <bsd.port.mk>
