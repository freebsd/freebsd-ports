# Ports collection makefile for:	linux_dri
# Date created:				Thu Oct 25 18:51:06 PDT 2001
# Whom:					Eric Anholt <eta@lclark.edu>
#
# $FreeBSD$
#

PORTNAME=	linux_dri
PORTVERSION=	4.3.0
PORTREVISION=	1
CATEGORIES=	graphics linux
MASTER_SITES=	ftp://ftp.xfree86.org/pub/XFree86/${PORTVERSION}/binaries/Linux-ix86-glibc21/:x \
		http://people.freebsd.org/~anholt/dri/files/:anholt
DISTFILES=	Xbin.tgz:x \
		Xmod.tgz:x \
		linux-libglide.tar.gz:anholt \
		linux-dri-tools.tar.gz:anholt
DIST_SUBDIR=	linux_dri-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Binary Linux DRI libraries for 3D hardware acceleration of linux apps

WRKSRC=		${WRKDIR}/lib
NO_BUILD=	yes
USE_LINUX_PREFIX=	yes

ONLY_FOR_ARCHS=	i386

MODULELIST=	gamma_dri.so i810_dri.so i830_dri.so mga_dri.so r128_dri.so \
		r200_dri.so radeon_dri.so tdfx_dri.so
LDCONFIG_LINUX=	${LINUXBASE}/sbin/ldconfig
NO_FILTER_SHLIBS=	yes
STRIP=

do-install:
	${MKDIR} ${PREFIX}/usr/X11R6/lib/modules/dri
	${INSTALL_PROGRAM} ${WRKSRC}/libGL.so.1.2 ${PREFIX}/usr/X11R6/lib
	${INSTALL_PROGRAM} ${WRKSRC}/libGLU.so.1.3 ${PREFIX}/usr/X11R6/lib
.for i in ${MODULELIST}
	${INSTALL_PROGRAM} ${WRKSRC}/modules/dri/${i} \
		${PREFIX}/usr/X11R6/lib/modules/dri
.endfor
#	The libglide3 distributed with linux_base is broken and is symlinked poorly, supply our own.
	${INSTALL_PROGRAM} ${WRKDIR}/linux-libglide/libglide3-v3.so.0 ${PREFIX}/usr/X11R6/lib
	${INSTALL_PROGRAM} ${WRKDIR}/linux-libglide/libglide3-v5.so.0 ${PREFIX}/usr/X11R6/lib
	${LN} -sf libglide3-v3.so.0 ${PREFIX}/usr/X11R6/lib/libglide3-v3.so
	${LN} -sf libglide3-v5.so.0 ${PREFIX}/usr/X11R6/lib/libglide3-v5.so
	${INSTALL_PROGRAM} ${WRKDIR}/linux-dri-tools/libglut.so.3.7.0 ${PREFIX}/usr/X11R6/lib
	${INSTALL_PROGRAM} ${WRKDIR}/linux-dri-tools/gears ${PREFIX}/usr/X11R6/bin
	${INSTALL_PROGRAM} ${WRKDIR}/linux-dri-tools/glxinfo ${PREFIX}/usr/X11R6/bin

post-install:
	@${LDCONFIG_LINUX} ${PREFIX}/usr/X11R6/lib

.include <bsd.port.mk>
