# New ports collection makefile for:	libmemcache
# Date created:		November 29, 2004
# Whom:			Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmemcache
PORTVERSION=	1.1.0
CATEGORIES=	databases
MASTER_SITES=	http://people.FreeBSD.org/~seanc/ports/libmemcache/

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	The C library for accessing a memcache cluster

NO_FILTER_SHLIBS=	yes
BUILD_DEPENDS+=	pmk:${PORTSDIR}/devel/pmk

USE_BZIP2=	yes

OPTIONS=	DEBUG	"Build with debugging turned on" off

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
PMKARGS=	-e debug
.endif

do-configure:
	cd ${WRKSRC}; ${LOCALBASE}/bin/pmk ${PMKARGS}

.include <bsd.port.post.mk>
