# New ports collection makefile for:    dri
# Date created:		8 Nov 2003
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	dri
PORTVERSION=	6.4.1
PORTEPOCH=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=mesa3d
DISTNAME=	MesaLib-${PORTVERSION}

MAINTAINER=	anholt@FreeBSD.org
COMMENT=	OpenGL hardware acceleration drivers for the DRI

LIB_DEPENDS=	drm:${PORTSDIR}/graphics/libdrm
BUILD_DEPENDS=	makedepend:${X_IMAKE_PORT}

CONFLICTS=	xfree86-dri-* dri-6.2.2005* dri-6.5.2006*

WRKSRC=		${WRKDIR}/Mesa-${PORTVERSION}
USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_ENV+=	FBSDCC="${CC}" FBSDCXX="${CXX}" \
		FBSDCFLAGS="${CFLAGS}" FBSDCXXFLAGS="${CXXFLAGS}" \
		PTHREAD_LIBS=${PTHREAD_LIBS}
USE_GCC=	3.4+

ONLY_FOR_ARCHS=	i386 alpha amd64

DRIMODDIR=	${PREFIX}/lib/modules/dri

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} != xorg
IGNORE=	requires libGL from X.Org
.endif

do-install:
	${MKDIR} ${DRIMODDIR}
.if ${ARCH} == i386
	${INSTALL_PROGRAM} ${WRKSRC}/lib/i810_dri.so ${DRIMODDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/lib/i830_dri.so ${DRIMODDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/lib/i915_dri.so ${DRIMODDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/lib/unichrome_dri.so ${DRIMODDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/lib/tdfx_dri.so ${DRIMODDIR}
.elif ${ARCH} == amd64
	${INSTALL_PROGRAM} ${WRKSRC}/lib/i915_dri.so ${DRIMODDIR}
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/lib/mach64_dri.so ${DRIMODDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/lib/mga_dri.so ${DRIMODDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/lib/r128_dri.so ${DRIMODDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/lib/r200_dri.so ${DRIMODDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/lib/r300_dri.so ${DRIMODDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/lib/radeon_dri.so ${DRIMODDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/lib/savage_dri.so ${DRIMODDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/lib/sis_dri.so ${DRIMODDIR}

.if ${OSVERSION} < 500000
pre-patch:
	${REINPLACE_CMD} -e 's|stdint.h|sys/types.h|g' \
		${WRKSRC}/src/mesa/drivers/dri/mga/mga_xmesa.c \
		${WRKSRC}/src/mesa/drivers/dri/mga/mgacontext.h
.endif

.if ${ARCH} == i386
PLIST_SUB+=	I386=""
PLIST_SUB+=	I386_AMD64=""
ALL_TARGET=	freebsd-dri-x86
.elif ${ARCH} == amd64
PLIST_SUB+=	I386="@comment "
PLIST_SUB+=	I386_AMD64=""
ALL_TARGET=	freebsd-dri
.else
PLIST_SUB+=	I386="@comment "
PLIST_SUB+=	I386_AMD64="@comment "
ALL_TARGET=	freebsd-dri
.endif
.include <bsd.port.post.mk>
