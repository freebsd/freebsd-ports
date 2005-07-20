# Ports collection makefile for:	dri-devel
# Date created:				Wed Aug 21 14:47:34 PDT 2002
# Whom:					Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dri
PORTVERSION=	6.2.20050719
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~anholt/dri/
MASTER_SITE_SUBDIR=	anholt
DISTFILES=	Mesa-20050719.tar.bz2	\
		drm-20050719.tar.bz2	\
		r300-20050719.tar.bz2

PATCH_SITES=	http://people.freebsd.org/~anholt/dri/
PATCHFILES=	patch-r300_drm.bz2

MAINTAINER=	anholt@FreeBSD.org
COMMENT=	DRI OpenGL drivers snapshot

BUILD_DEPENDS=	makedepend:${X_IMAKE_PORT}

EXTRA_DISTFILES= \
		Mesa-20050719.tar.bz2	\
		drm-20050719.tar.bz2

CONFLICTS=	xfree86-dri-[0-9]* dri-6.2_*

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

post-extract:
	(cd ${WRKSRC}/src/mesa/drivers/dri && \
		${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/r300-20050719.tar.bz2 ${EXTRACT_AFTER_ARGS} )

.if ${X_WINDOW_SYSTEM:L} != xorg
IGNORE=	requires libGL from X.Org.
.endif

do-install:
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
