# New ports collection makefile for:	linux_glx
# Date created:         27 November 1999
# Whom:                 Marc E E van Woerkom  <van.woerkom@netcologne.de>
#
# $FreeBSD$
#

PORTNAME=	glx
PORTVERSION=	991127
CATEGORIES=	graphics linux
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	3d/glx/linux
PKGNAMEPREFIX=	linux_
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	3d@freebsd.org

BUILD_DEPENDS= 	/compat/linux/sbin/ldconfig:${PORTSDIR}/emulators/linux_base	

USE_BZIP2=	yes
NO_BUILD=	yes

PREFIX=		/compat/linux
NO_MTREE=	yes

WRKSRC=		${WRKDIR}/linux_glx
# switch off stripping during INSTALL_PROGRAM
STRIP=

# NEVER EVER use plain INSTALL_PROGRAM on Linux binaries,
# as they get stripped!
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libGL.so ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/libGLU.so ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/libglut.so ${PREFIX}/lib
post-install:
	@ ${PREFIX}/sbin/ldconfig

.include <bsd.port.mk>
