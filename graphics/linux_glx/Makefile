# New ports collection makefile for:	linux_glx
# Version required:     CVS
# Date created:         27 November 1999
# Whom:                 Marc E E van Woerkom  <van.woerkom@netcologne.de>
#
# $FreeBSD$
#

DISTNAME=	linux_glx-991127
CATEGORIES=	graphics linux
MASTER_SITES=	http://people.FreeBSD.org/~3d/distfiles/glx/linux/

MAINTAINER=	3d@freebsd.org

BUILD_DEPENDS= 	/compat/linux/sbin/ldconfig:${PORTSDIR}/emulators/linux_base	

USE_BZIP2=	yes
NO_BUILD=	yes

PREFIX=		/compat/linux

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
