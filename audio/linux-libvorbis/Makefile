# New ports collection makefile for:	linux-libvorbis
# Date created:				25 Nov 2005
# Whom:					jylefort@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libvorbis
DISTVERSION=	1.1.0-2
PORTREVISION=	2
CATEGORIES=	audio linux

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Audio compression codec library (Linux version)

CONFLICTS=	linux-f8-libvorbis-[0-9]* linux-f10-libvorbis-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	libogg
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
AUTOMATIC_PLIST=yes
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
