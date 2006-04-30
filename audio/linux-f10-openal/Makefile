# New ports collection makefile for:	linux-openal
# Date created:				25 Nov 2005
# Whom:					jylefort@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	openal
DISTVERSION=	0.0.9-0.3.20060226cvs.fc3
CATEGORIES=	audio linux
MASTER_SITE_SUBDIR=	../extras/${LINUX_DIST_VER}/${LINUX_RPM_ARCH}/

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
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	3
MASTER_SITE_SRC_SUBDIR=	../extras/${LINUX_DIST_VER}/SRPMS
INSTALLS_SHLIB=	yes
AUTOMATIC_PLIST=yes
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
