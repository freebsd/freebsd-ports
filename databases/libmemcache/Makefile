# New ports collection makefile for:	libmemcache
# Date created:		November 29, 2004
# Whom:			Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmemcache
PORTVERSION=	1.0.2
CATEGORIES=	databases
MASTER_SITES=	http://people.FreeBSD.org/~seanc/ports/libmemcache/

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	The C library for accessing a memcache cluster

NO_FILTER_SHLIBS=	yes
BUILD_DEPENDS+=	pmk:${PORTSDIR}/devel/pmk

USE_BZIP2=	yes

do-configure:
	cd ${WRKSRC}; ${LOCALBASE}/bin/pmk

.include <bsd.port.mk>
