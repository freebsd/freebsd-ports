# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_geoip
CATEGORIES=	ftp
PKGNAMEPREFIX=	proftpd-

MAINTAINER=	mm@FreeBSD.org
COMMENT=	GeoIP ProFTPD module

LICENSE=	GPLv2

LIB_DEPENDS=	libGeoIP.so:net/GeoIP

DEPRECATED=     Uses legacy GeoIP 1 format which no longer works; switch to GeoIP 2 where possible
EXPIRATION_DATE=2019-02-15

DESCR=		${.CURDIR}/pkg-descr

MASTERDIR=	${.CURDIR}/../../ftp/proftpd

INCLUDEDIRS=	${LOCALBASE}/include
LIBDIRS=	${LOCALBASE}/lib

_BUILDING_PROFTPD_MODULE=	${PORTNAME}

.include "${MASTERDIR}/Makefile"
