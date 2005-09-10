# New ports collection makefile for:	libmemcache
# Date created:		November 29, 2004
# Whom:			Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmemcache
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://people.FreeBSD.org/~seanc/ports/libmemcache/

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	The C library for accessing a memcache cluster

BUILD_DEPENDS=	pmk:${PORTSDIR}/devel/pmk

USE_BZIP2=	yes

INSTALLS_SHLIB=	yes
NO_FILTER_SHLIBS=	yes

OPTIONS=	DEBUG	"Build with debugging turned on" off

.if defined(WITH_DEBUG)
PMKARGS=	-e debug
.endif

do-configure:
	cd ${WRKSRC}; ${LOCALBASE}/bin/pmk ${PMKARGS}

post-install:
	# only files named lib*.so.[0-9] enter ld-elf.so.hints
	${LN} -sf ${PREFIX}/lib/libmemcache.so.1.2 ${PREFIX}/lib/libmemcache.so.1

.include <bsd.port.mk>
