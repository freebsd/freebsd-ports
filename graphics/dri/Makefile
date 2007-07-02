# New ports collection makefile for:    dri
# Date created:		8 Nov 2003
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	dri
PORTVERSION=	7.0
PORTEPOCH=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=mesa3d
DISTNAME=	MesaLib-${PORTVERSION}

MAINTAINER=	anholt@FreeBSD.org
COMMENT=	OpenGL hardware acceleration drivers for the DRI

LIB_DEPENDS=	drm:${PORTSDIR}/graphics/libdrm \
		expat.6:${PORTSDIR}/textproc/expat2
BUILD_DEPENDS=	makedepend:${PORTSDIR}/devel/makedepend

CONFLICTS=	xfree86-dri-* dri-6.2.2005* dri-6.5.2006*

WRKSRC=		${WRKDIR}/Mesa-${PORTVERSION}
USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_ENV+=	FBSDCC="${CC}" FBSDCXX="${CXX}" \
		FBSDCFLAGS="${CFLAGS}" FBSDCXXFLAGS="${CXXFLAGS}" \
		PTHREAD_LIBS=${PTHREAD_LIBS}
USE_GCC=	3.4+

DRIMODDIR=	${PREFIX}/lib/dri

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} != xorg
IGNORE=	requires libGL from X.Org
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

.if ${OSVERSION} < 500000
pre-patch:
	@${REINPLACE_CMD} -e 's|stdint.h|sys/types.h|g' \
		${WRKSRC}/src/mesa/drivers/dri/mga/mga_xmesa.c \
		${WRKSRC}/src/mesa/drivers/dri/mga/mgacontext.h
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^CC =/d' -e '/^CXX =/d' \
		-e 's|/usr/local|$$(LOCALBASE)|g' \
		-e 's|/usr/X11R6|$$(X11BASE)|g' \
		-e 's|-lpthread|$$(PTHREAD_LIBS)|g' \
		-e 's|^\(SRC_DIRS =\).*|\1 mesa|' \
			${WRKSRC}/configs/freebsd-dri
.if ${OSVERSION} < 700013
	@${REINPLACE_CMD} -e 's|-DHAVE_POSIX_MEMALIGN||' \
			${WRKSRC}/configs/freebsd-dri
.endif

.if ${ARCH} == i386
PLIST_SUB+=	I386=""
PLIST_SUB+=	I386_AMD64=""
ALL_TARGET=	freebsd-dri-x86
.elif ${ARCH} == amd64
PLIST_SUB+=	I386="@comment "
PLIST_SUB+=	I386_AMD64=""
ALL_TARGET=	freebsd-dri-amd64
.else
PLIST_SUB+=	I386="@comment "
PLIST_SUB+=	I386_AMD64="@comment "
ALL_TARGET=	freebsd-dri
.endif
.include <bsd.port.post.mk>
