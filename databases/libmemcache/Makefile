# Created by: Sean Chittenden <seanc@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libmemcache
DISTVERSION=	1.4.0.rc2
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://people.FreeBSD.org/~seanc/libmemcache/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The C library for accessing a memcache cluster

USES=		libtool tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DEBUG

DEBUG_CONFIGURE_ENABLE=	debug

.include <bsd.port.mk>
