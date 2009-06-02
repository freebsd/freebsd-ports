# New ports collection makefile for: linux-jpeg
# Date created:         9 April 2000
# Whom:                 sada@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	jpeg
PORTVERSION=	6b.34
PORTREVISION=	2
CATEGORIES=	graphics linux
DISTNAME=	libjpeg-6b-34

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	RPM of the JPEG lib

CONFLICTS=	linux-f8-jpeg-[0-9]* linux-f10-jpeg-[0-9]*

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	i386 amd64

BRANDELF_DIRS=	usr/bin

.include <bsd.port.mk>
