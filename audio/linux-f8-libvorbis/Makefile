# New ports collection makefile for:	linux-libvorbis
# Date created:				25 Nov 2005
# Whom:					jylefort@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libvorbis
DISTVERSION=	1.1.0-1
CATEGORIES=	audio linux
MASTER_SITE_SUBDIR=	3/${LINUX_ARCH}/os/Fedora/RPMS/

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	Audio compression codec library (Linux version)

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libogg.so.0:${PORTSDIR}/audio/linux-libogg

ONLY_FOR_ARCHS=	i386 amd64
INSTALLS_LINUX_SHLIB=	yes

.include "${.CURDIR}/../../audio/linux-openal/bsd.linux.mk"
