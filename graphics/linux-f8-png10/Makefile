# New ports collection makefile for: linux-png
# Date created:		28 September 2000
# Whom:                 sanpei@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	png
PORTVERSION=	1.0.14
PORTREVISION=	3
CATEGORIES=	graphics linux
MASTER_SITES=	${RPM_MIRRORS:S/__DIR__/${UPDDIR}/g}

DEPRECATED=     http://vuxml.freebsd.org/f9e3e60b-e650-11d8-9b0a-000347a4fa7d.html (security)
EXPIRATION_DATE=November 21, 2004

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RPM of the PNG lib

CONFLICTS=	linux-png-1.2.*
LATEST_LINK=	linux-png10

.if (${MACHINE_ARCH} == "i386")
RPM_SET=	libpng-${PORTVERSION}-0.7x.4.${MACHINE_ARCH}.rpm
.elif (${MACHINE_ARCH} == "alpha")
RPM_SET=	libpng-${PORTVERSION}-0.7x.3.${MACHINE_ARCH}.rpm
.endif

.include "../../x11-toolkits/linux-gtk/Makefile"
