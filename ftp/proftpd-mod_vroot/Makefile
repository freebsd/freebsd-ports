# Created by: Joseph Benden <joe@thrallingpenguin.com>
# $FreeBSD$

PORTNAME=	mod_vroot
DISTVERSION=	0.9.5
PORTREVISION=	1
CATEGORIES=	ftp
PKGNAMEPREFIX=	proftpd-

MAINTAINER=	joe@thrallingpenguin.com
COMMENT=	Virtual Chroot ProFTPD module

LICENSE=	GPLv2

DESCR=		${.CURDIR}/pkg-descr

MASTERDIR=	${.CURDIR}/../../ftp/proftpd

_PROFTPD_MODULE_DISTFILES=	proftpd-mod_vroot-${DISTVERSION}${EXTRACT_SUFX}:vroot
_PROFTPD_MODULE_EXTRACT_ONLY=	proftpd-mod_vroot-${DISTVERSION}${EXTRACT_SUFX}
_PROFTPD_MODULE_MASTER_SITES=	https://codeload.github.com/Castaglia/proftpd-mod_vroot/tar.gz/v${DISTVERSION}?dummy=/:vroot

INCLUDEDIRS=	${LOCALBASE}/include
LIBDIRS=	${LOCALBASE}/lib

_BUILDING_PROFTPD_MODULE=	${PORTNAME}

post-extract:
	@${MV} ${WRKDIR}/proftpd-mod_vroot-${DISTVERSION} ${WRKSRC}/contrib/mod_vroot

.include "${MASTERDIR}/Makefile"
