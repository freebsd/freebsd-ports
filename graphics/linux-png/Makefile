# New ports collection makefile for: linux-png
# Date created:		28 September 2000
# Whom:                 sanpei@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	png
PORTVERSION=	1.2.2
PORTREVISION=	0
CATEGORIES=	graphics linux
MASTER_SITES=	${RPM_MIRRORS:S/__DIR__/${UPDDIR}/g}

DEPRECATED=	http://vuxml.freebsd.org/f9e3e60b-e650-11d8-9b0a-000347a4fa7d.html (security)
EXPIRATION_DATE=November 21, 2004

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RPM of the PNG lib

CONFLICTS=	linux-png-1.0.*

# no alpha rpm is available
ONLY_FOR_ARCHS=	i386

BASEVERSION=	8.0
RPM_SET=	libpng-${PORTVERSION}-8.${MACHINE_ARCH}.rpm

.include "../../x11-toolkits/linux-gtk/Makefile"
