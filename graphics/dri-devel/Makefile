# Ports collection makefile for:	dri-devel
# Date created:				Wed Aug 21 14:47:34 PDT 2002
# Whom:					Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dri
PORTVERSION=	6.5.20060624
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~anholt/dri/
MASTER_SITE_SUBDIR=	anholt
DISTFILES=	Mesa-20060624.tar.bz2

MAINTAINER=	anholt@FreeBSD.org
COMMENT=	DRI OpenGL drivers snapshot

BUILD_DEPENDS=	makedepend:${X_IMAKE_PORT}
LIB_DEPENDS=	drm.2:${PORTSDIR}/graphics/libdrm

BROKEN=		install fails

CONFLICTS=	xfree86-dri-[0-9]* dri-6.2_* dri-6.4_*

WRKSRC=		${WRKDIR}/Mesa
USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
LATEST_LINK=	${PORTNAME}-devel
MAKE_ENV+=	FBSDCC="${CC}" FBSDCXX="${CXX}" \
		FBSDCFLAGS="${CFLAGS}" FBSDCXXFLAGS="${CXXFLAGS}" \
		PTHREAD_LIBS=${PTHREAD_LIBS}

ONLY_FOR_ARCHS=	i386 alpha amd64

DRIMODDIR=	${PREFIX}/lib/modules/dri

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
USE_GCC=        3.4
.endif

.if ${X_WINDOW_SYSTEM:L} != xorg
IGNORE=	requires libGL from X.Org.
.endif

pre-patch:
	${REINPLACE_CMD} \
		-e 's|/usr/X11R6|${X11BASE}|g' \
		-e 's|/usr/local|${LOCALBASE}|g' \
		-e 's|gcc|${CC}|g' \
		-e 's|g++|${CXX}|g' \
		-e 's|CFLAGS = |CFLAGS = ${CFLAGS} |g' \
		-e 's|OPT_FLAGS = .*|OPT_FLAGS = ${CFLAGS}|g' \
		-e 's|-pthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configs/freebsd-dri

do-install:
	${MKDIR} ${DRIMODDIR}
.if ${ARCH} == i386
	${INSTALL_PROGRAM} ${WRKSRC}/lib/i810_dri.so ${DRIMODDIR}
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
