# New ports collection makefile for: linux-png
# Date created:		28 September 2000
# Whom:                 sanpei@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	png
PORTVERSION=	1.0.14
PORTREVISION=	1
CATEGORIES=	graphics linux
MASTER_SITES=	${RPM_MIRRORS:S/__DIR__/${UPDDIR}/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RPM of the PNG lib

.if (${MACHINE_ARCH} == "i386")
RPM_SET=	libpng-${PORTVERSION}-0.7x.4.${MACHINE_ARCH}.rpm
.elif (${MACHINE_ARCH} == "alpha")
RPM_SET=	libpng-${PORTVERSION}-0.7x.3.${MACHINE_ARCH}.rpm
.endif

.include "../../x11-toolkits/linux-gtk/Makefile"
