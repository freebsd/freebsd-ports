# New ports collection makefile for:	linux_glx
# Date created:         27 November 1999
# Whom:                 Marc E E van Woerkom  <van.woerkom@netcologne.de>
#
# $FreeBSD$
#

PORTNAME=	glx
PORTVERSION=	991127
PORTREVISION=	2
CATEGORIES=	graphics linux
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	3d/glx/linux
PKGNAMEPREFIX=	linux_
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Libraries to make use of glx-aware Linux apps

BUILD_DEPENDS=	${LINUX_BASE_PORT}

USE_BZIP2=	yes
NO_BUILD=	yes

USE_LINUX=	yes
USE_LINUX_PREFIX=yes

WRKSRC=		${WRKDIR}/linux_glx

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} != xfree86-3
IGNORE=		"Requires XFree86 3.3.* - will not work with XFree86 4.*"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libGL.so ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/libGLU.so ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/libglut.so ${PREFIX}/lib
post-install:
	@${LINUXBASE}/sbin/ldconfig

.include <bsd.port.post.mk>
