# Ports collection makefile for:	dri development
# Date created:				Wed Aug 21 14:47:34 PDT 2002
# Whom:					Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dri
PORTVERSION=	20021008
PORTREVISION=	1
CATEGORIES=	graphics x11-servers
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	anholt/dri-devel
PKGNAMESUFFIX=	-devel
DISTNAME=	dri-20020826

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	anholt/dri-devel
PATCHFILES=	dri-20020826-${PORTVERSION}.diff.bz2

MAINTAINER=	anholt@FreeBSD.org

RUN_DEPENDS=	XFree86:${PORTSDIR}/x11-servers/XFree86-4-Server

WRKSRC=		${WRKDIR}/xc

USE_BZIP2=	yes
USE_X_PREFIX=	yes
MAKE_ENV=	FBSDCFLAGS="${CFLAGS}" FBSDCC="${CC}" FBSDCXX="${CXX}"
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

DRILIST=	i810/i810_dri.so i830/i830_dri.so \
		r128/r128_dri.so radeon/radeon_dri.so r200/r200_dri.so \
		gamma/gamma_dri.so mga/mga_dri.so tdfx/tdfx_dri.so
DDXLIST=	ati/r128_drv.o ati/radeon_drv.o \
		i810/i810_drv.o \
		mga/mga_drv.o tdfx/tdfx_drv.o
XMAKEFILE_TARGETS=	VerifyOS version.def Makefiles includes depend

pre-fetch::
	@${ECHO_MSG} "********************************************************"
	@${ECHO_MSG} "This port installs unstable, development-class drivers."
	@${ECHO_MSG} "It comes from snapshots of DRI CVS (http://dri.sf.net)"
	@${ECHO_MSG} "If you just want 3d, that is included with XFree86."
	@${ECHO_MSG} "********************************************************"

post-patch:
	@${REINPLACE_CMD} -e 's/DRI trunk/DRI trunk: dri-devel-${PORTVERSION}/g' \
		${WRKSRC}/config/cf/host.def

do-configure:
	@${RM} -f  ${WRKSRC}/config/cf/version.def
	@${ECHO} "" > ${WRKSRC}/config/cf/version.def
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} Makefile.boot
.for target in ${XMAKEFILE_TARGETS}
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} -f xmakefile ${target}
.endfor

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/GL/GL/libGL.so.1.2 ${PREFIX}/lib/libGL.so.1
	${INSTALL_DATA} ${WRKSRC}/lib/GLU/libGLU.so.1.3 ${PREFIX}/lib/libGLU.so.1
	${INSTALL_DATA} ${WRKSRC}/lib/GL/mesa/src/OSmesa/libOSMesa.so.4.0 \
		${PREFIX}/lib/libOSMesa.so.4
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
	${INSTALL_DATA} ${WRKSRC}/programs/Xserver/hw/xfree86/xaa/libxaa.a \
		${PREFIX}/lib/modules/extensions/
	${INSTALL_DATA} ${WRKSRC}/programs/Xserver/GL/dri/libdri.a \
		${PREFIX}/lib/modules/extensions/
	${INSTALL_DATA} ${WRKSRC}/programs/Xserver/GL/libglx.a \
		${PREFIX}/lib/modules/extensions/
	${INSTALL_DATA} ${WRKSRC}/programs/Xserver/GL/mesa/GLcore/libGLcore.a \
		${PREFIX}/lib/modules/extensions/
	${INSTALL_PROGRAM} ${WRKSRC}/programs/Xserver/XFree86 ${PREFIX}/bin
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
