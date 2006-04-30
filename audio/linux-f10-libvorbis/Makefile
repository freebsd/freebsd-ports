# New ports collection makefile for:	linux-libvorbis
# Date created:				25 Nov 2005
# Whom:					jylefort@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libvorbis
DISTVERSION=	1.1.0-1
PORTREVISION=	2
CATEGORIES=	audio linux

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	Audio compression codec library (Linux version)

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libogg.so.0:${PORTSDIR}/audio/linux-libogg

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	3
INSTALLS_SHLIB=	yes
AUTOMATIC_PLIST=yes
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
