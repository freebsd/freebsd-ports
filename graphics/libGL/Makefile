# New ports collection makefile for:    xorg-server
# Date created:		7 May 2004
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME?=	libGL
PORTVERSION?=	7.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.fu-berlin.de/pub/unix/X11/graphics/Mesa/
MASTER_SITE_SUBDIR=	mesa3d
DISTFILES=	MesaLib-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	x11@FreeBSD.org
COMMENT?=	OpenGL library that renders using GLX or DRI

BUILD_DEPENDS+=	makedepend:${PORTSDIR}/devel/makedepend
LIB_DEPENDS+=	drm:${PORTSDIR}/graphics/libdrm

CONFLICTS=	XFree86-libraries-* xorg-libraries-6.*

USE_XORG=	glproto xxf86vm xext xfixes xdamage
USE_GMAKE=	yes
USE_LDCONFIG=	yes
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/drm
GLHEADERS=	gl.h glext.h glx.h glxext.h

WRKSRC=		${WRKDIR}/Mesa-${PORTVERSION}
PREFIX?=	${X11BASE}
USE_BZIP2=	yes

pre-patch:
	@${REINPLACE_CMD} \
		-e 's|/usr/X11R6|${X11BASE}|g' \
		-e 's|/usr/local|${LOCALBASE}|g' \
		-e 's|gcc|${CC}|g' \
		-e 's|g++|${CXX}|g' \
		-e 's|CFLAGS = |CFLAGS = ${CFLAGS} |g' \
		-e 's|OPT_FLAGS = .*|OPT_FLAGS = ${CFLAGS}|g' \
		-e 's|-lpthread|${PTHREAD_LIBS}|g' \
		-e 's|SRC_DIRS = .*|SRC_DIRS = glx/x11|g' \
		${WRKSRC}/configs/freebsd-dri
	@${REINPLACE_CMD} \
		-e 's|^\(MKDEP_OPTIONS.*\)|\1 --|' \
		-e 's|^DRI_DRIVER_INSTALL_DIR.*|DRI_DRIVER_INSTALL_DIR = ${X11BASE}/lib/dri|' \
		${WRKSRC}/configs/default

do-install:
	${MKDIR} ${PREFIX}/include/GL
.for i in ${GLHEADERS}
	${INSTALL_DATA} ${WRKSRC}/include/GL/${i} ${PREFIX}/include/GL
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/lib/libGL.so.1 ${PREFIX}/lib
	${LN} -sf libGL.so.1 ${PREFIX}/lib/libGL.so

.include <bsd.port.pre.mk>

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
