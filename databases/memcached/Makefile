# New ports collection makefile for:	memcached
# Date created:		July 21, 2003
# Whom:			Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	memcached
PORTVERSION=	1.1.8
CATEGORIES=	databases
MASTER_SITES=	http://www.danga.com/memcached/dist/

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	High-performance distributed memory object cache system

BUILD_DEPENDS+=	${LOCALBASE}/lib/libevent.a:${PORTSDIR}/devel/libevent

PLIST_FILES=	bin/memcached
USE_AUTOMAKE=YES
WANT_AUTOCONF_VER=253
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--with-libevent=${LOCALBASE}

.include <bsd.port.mk>
