# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_geoip
DISTVERSION=	0.3
PORTREVISION=	0
CATEGORIES=	ftp
PKGNAMEPREFIX=	proftpd-

MAINTAINER=	mm@FreeBSD.org
COMMENT=	GeoIP ProFTPD module

LICENSE=	GPLv2

DESCR=		${.CURDIR}/pkg-descr

LATEST_LINK=	${PKGNAMEPREFIX}-${PORTNAME}
MASTERDIR=	${.CURDIR}/../../ftp/proftpd

LIB_DEPENDS=	GeoIP.5:${PORTSDIR}/net/GeoIP

_PROFTPD_MODULE_DISTFILES=	proftpd-mod-geoip-${DISTVERSION}${EXTRACT_SUFX}:mod_geoip
_PROFTPD_MODULE_EXTRACT_ONLY=   proftpd-mod-geoip-${DISTVERSION}${EXTRACT_SUFX}
_PROFTPD_MODULE_MASTER_SITES=   http://www.castaglia.org/proftpd/modules/:mod_geoip

INCLUDEDIRS=	${LOCALBASE}/include
LIBDIRS=	${LOCALBASE}/lib

_BUILDING_PROFTPD_MODULE=	${PORTNAME}

post-extract:
	@${CP} ${WRKDIR}/mod_geoip/mod_geoip.c ${WRKSRC}/contrib

.include "${MASTERDIR}/Makefile"
