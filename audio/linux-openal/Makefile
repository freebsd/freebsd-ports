# New ports collection makefile for:	linux-openal
# Date created:				25 Nov 2005
# Whom:					jylefort@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	openal
DISTVERSION=	0.0-0.2.20040726
CATEGORIES=	audio linux
MASTER_SITE_SUBDIR=	../extras/3/${LINUX_ARCH}/

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A 3D positional spatialized sound library (Linux version)

RUN_DEPENDS=	${LINUXBASE}/lib/libasound.so.2:${PORTSDIR}/audio/linux-alsa-lib \
		${LINUXBASE}/usr/lib/libartsc.so.0:${PORTSDIR}/audio/linux-arts \
		${LINUXBASE}/usr/lib/libglib-2.0.so.0:${PORTSDIR}/devel/linux-glib2 \
		${LINUXBASE}/usr/lib/libesd.so.0:${PORTSDIR}/audio/linux-esound \
		${LINUXBASE}/usr/lib/libaudiofile.so.0:${PORTSDIR}/audio/linux-libaudiofile \
		${LINUXBASE}/usr/lib/libSDL-1.2.so.0:${PORTSDIR}/devel/linux-sdl12 \
		${LINUXBASE}/usr/lib/libvorbis.so.0:${PORTSDIR}/audio/linux-libvorbis

ONLY_FOR_ARCHS=	i386 amd64
INSTALLS_LINUX_SHLIB=	yes

.include "${.CURDIR}/../../audio/linux-openal/bsd.linux.mk"
