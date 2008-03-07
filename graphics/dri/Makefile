# New ports collection makefile for:    dri
# Date created:		8 Nov 2003
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	dri
PORTVERSION=	${MESAVERSION}
PORTEPOCH=	2
CATEGORIES=	graphics

COMMENT=	OpenGL hardware acceleration drivers for the DRI

LIB_DEPENDS=	drm:${PORTSDIR}/graphics/libdrm \
		expat.6:${PORTSDIR}/textproc/expat2
BUILD_DEPENDS=	makedepend:${PORTSDIR}/devel/makedepend

CONFLICTS=	xfree86-dri-* dri-6.2.2005* dri-6.5.2006*

MAKE_ENV+=	FBSDCC="${CC}" FBSDCXX="${CXX}" \
		FBSDCFLAGS="${CFLAGS}" FBSDCXXFLAGS="${CXXFLAGS}" \
		PTHREAD_LIBS=${PTHREAD_LIBS}
USE_GCC=	3.4+

USE_XORG=	x11

DRIMODDIR=	${PREFIX}/lib/dri
SRCDIR=		mesa

.if !defined(ARCH)
ARCH!=	uname -p
.endif

do-install:
	${MKDIR} ${DRIMODDIR}
.if ${ARCH} == i386
	${INSTALL_PROGRAM} ${WRKSRC}/lib/i810_dri.so ${DRIMODDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/lib/i915_dri.so ${DRIMODDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/lib/i965_dri.so ${DRIMODDIR}
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

.include "${.CURDIR}/../../graphics/libGL/bsd.mesalib.mk"

.include <bsd.port.mk>
