# New ports collection makefile for:	linux-x-plane-net-installer
# Date created:				07 Dec 2005
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	linux-x-plane-net-installer
PORTVERSION=	1.07
CATEGORIES=	games linux
MASTER_SITES=	http://dev.x-plane.com/installer/${PORTVERSION}/
DISTFILES=	X-Plane-Net-Install.gz

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	The X-Plane network installer

RUN_DEPENDS=	${LINUXBASE}/lib/libgcc/libgcc_s.so.1:${PORTSDIR}/lang/linux-libgcc \
		${LINUXBASE}/usr/lib/libopenal.so.1:${PORTSDIR}/audio/linux-openal \
		${LINUXBASE}/usr/X11R6/lib/libGLU.so.1.3:${PORTSDIR}/graphics/linux_dri

USE_X_PREFIX=	yes
USE_LINUX=	yes
NO_BUILD=	yes
RESTRICTED=	"Redistribution prohibited"
ONLY_FOR_ARCHS=	i386 amd64

PLIST_FILES=	bin/X-Plane-Net-Install

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} != xfree86-3
.if defined(WITH_NVIDIA_GL)
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver
.else
RUN_DEPENDS+=	${LINUXBASE}/usr/X11R6/lib/libGL.so.1:${PORTSDIR}/graphics/linux_dri
.endif
.else
RUN_DEPENDS+=	${LINUXBASE}/lib/libGL.so.1:${PORTSDIR}/graphics/linux_glx
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	@${GUNZIP_CMD} -c ${DISTDIR}/${DISTFILES} > ${WRKSRC}/X-Plane-Net-Install

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/X-Plane-Net-Install ${PREFIX}/bin

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
