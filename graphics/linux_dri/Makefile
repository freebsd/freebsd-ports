# Ports collection makefile for:	linux_dri
# Date created:				Thu Oct 25 18:51:06 PDT 2001
# Whom:			Eric Anholt <eanholt@gladstone.uoregon.edu>
#
# $FreeBSD$
#

PORTNAME=	dri
PORTVERSION=	4.1.0
CATEGORIES=	graphics linux
MASTER_SITES=	ftp://ftp.xfree86.org/pub/XFree86/4.1.0/binaries/Linux-ix86-glibc21/ \
		http://gladstone.uoregon.edu/~eanholt/dri/
PKGNAMEPREFIX=	linux_
DISTFILES=	Xmod.tgz Xbin.tgz linux-libglide.tar.gz \
		linux-dri-tools.tar.gz
DIST_SUBDIR=	linux-dri

MAINTAINER=	eanholt@gladstone.uoregon.edu

WRKSRC=		${WRKDIR}/lib
NO_BUILD=	yes
USE_LINUX_PREFIX=	yes

MODULELIST=	gamma_dri.so i810_dri.so mga_dri.so r128_dri.so \
		radeon_dri.so sis_dri.so tdfx_dri.so
LDCONFIG_LINUX=	${LINUXBASE}/sbin/ldconfig
STRIP=

do-install:
	@${MKDIR} ${PREFIX}/usr/X11R6/lib/modules/dri
	@${INSTALL_PROGRAM} ${WRKSRC}/libGL.so.1 ${PREFIX}/usr/X11R6/lib
	@${INSTALL_PROGRAM} ${WRKSRC}/libGLU.so.1 ${PREFIX}/usr/X11R6/lib
.for i in ${MODULELIST}
	@${INSTALL_PROGRAM} ${WRKSRC}/modules/dri/${i} \
		${PREFIX}/usr/X11R6/lib/modules/dri
.endfor
	@${INSTALL_PROGRAM} ${WRKDIR}/linux-libglide/libglide3-v3.so.0 ${PREFIX}/usr/X11R6/lib
	@${INSTALL_PROGRAM} ${WRKDIR}/linux-libglide/libglide3-v5.so.0 ${PREFIX}/usr/X11R6/lib
	@${INSTALL_PROGRAM} ${WRKDIR}/linux-dri-tools/libglut.so.3.7.0 ${PREFIX}/usr/X11R6/lib
	@${INSTALL_PROGRAM} ${WRKDIR}/linux-dri-tools/gears ${PREFIX}/usr/X11R6/bin
	@${INSTALL_PROGRAM} ${WRKDIR}/linux-dri-tools/glxinfo ${PREFIX}/usr/X11R6/bin

post-install:
	@${LDCONFIG_LINUX} ${PREFIX}/usr/X11R6/lib
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${PKGMESSAGE}

.include <bsd.port.mk>
