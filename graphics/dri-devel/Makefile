# Ports collection makefile for:	dri development
# Date created:				Wed Aug 21 14:47:34 PDT 2002
# Whom:					Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dri
PORTVERSION=	20020820
CATEGORIES=	graphics x11-servers
MASTER_SITES=	http://people.freebsd.org/~anholt/dri/files/
PKGNAMESUFFIX=	-devel
DISTNAME=	dri-r200-${PORTVERSION}

MAINTAINER=	anholt@FreeBSD.org

RUN_DEPENDS=	XFree86:${PORTSDIR}/x11-servers/XFree86-4-Server

WRKSRC=		${WRKDIR}/xc

USE_BZIP2=	yes
USE_X_PREFIX=	yes
MAKE_ENV=	FBSDCFLAGS="${CFLAGS}"
INSTALLS_SHLIB=	yes

DRILIST=	i810/i810_dri.so i830/i830_dri.so \
		r128/r128_dri.so radeon/radeon_dri.so r200/r200_dri.so
#		gamma/gamma_dri.so mga/mga_dri.so tdfx/tdfx_dri.so
DDXLIST=	ati/r128_drv.o ati/radeon_drv.o \
		i810/i810_drv.o \
		mga/mga_drv.o tdfx/tdfx_drv.o
XMAKEFILE_TARGETS=	VerifyOS version.def Makefiles includes depend

do-configure:
	@${RM} -f  ${WRKSRC}/config/cf/version.def
	@${ECHO} "" > ${WRKSRC}/config/cf/version.def
	@cd ${WRKSRC} && ${MAKE} Makefile.boot
.for target in ${XMAKEFILE_TARGETS}
	@cd ${WRKSRC} && ${MAKE} -f xmakefile ${target}
.endfor

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/GL/GL/libGL.so.1.2 ${PREFIX}/lib/libGL.so.1
	${INSTALL_DATA} ${WRKSRC}/lib/GLU/libGLU.so.1.3 ${PREFIX}/lib/libGLU.so.1
	${INSTALL_DATA} ${WRKSRC}/lib/GL/mesa/src/OSmesa/libOSMesa.so.4.0 ${PREFIX}/lib/libOSMesa.so.4
.for i in ${DRILIST}
	${INSTALL_DATA} ${WRKSRC}/lib/GL/mesa/src/drv/${i} \
		${PREFIX}/lib/modules/dri
.endfor
.for i in ${DDXLIST}
	${INSTALL_DATA} ${WRKSRC}/programs/Xserver/hw/xfree86/drivers/${i} \
		${PREFIX}/lib/modules/drivers
.endfor
	${INSTALL_DATA} ${WRKSRC}/programs/Xserver/hw/xfree86/os-support/bsd/drm/libdrm.a \
		${PREFIX}/lib/modules/freebsd/
	${INSTALL_DATA} ${WRKSRC}/programs/Xserver/GL/dri/libdri.a \
		${PREFIX}/lib/modules/extensions/
	${INSTALL_DATA} ${WRKSRC}/programs/Xserver/GL/libglx.a \
		${PREFIX}/lib/modules/extensions/
	${INSTALL_DATA} ${WRKSRC}/programs/Xserver/GL/mesa/GLcore/libGLcore.a \
		${PREFIX}/lib/modules/extensions/
	${INSTALL_PROGRAM} ${WRKSRC}/programs/Xserver/XFree86 ${PREFIX}/bin
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
