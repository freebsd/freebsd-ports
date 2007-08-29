#-*- mode: Fundamental; tab-width: 4; -*-
# ex:ts=4
#
# bsd.mesa.mk - an attempt to refactor MesaLib ports.
#
# Created by: Florent Thoumie <flz@FreeBSD.org>
#
# !!! Here be dragons !!! (they seem to be everywhere these days)
#
# Remember to upgrade the following ports everytime you bump MESAVERSION:
#
#    - graphics/libGL
#    - graphics/libGLU
#    - graphics/libGLw
#    - graphics/dri
#
# $FreeBSD$
#

MESAVERSION=	7.0.1
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.fu-berlin.de/pub/unix/X11/graphics/Mesa/
MASTER_SITE_SUBDIR=	mesa3d
DISTFILES=	MesaLib-${PORTVERSION}${EXTRACT_SUFX}
MAINTAINER=	x11@FreeBSD.org
CONFLICTS?=	XFree86-libraries-* xorg-libraries-6.*

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

MAKE_ARGS=	SHELL=${SH}
CFLAGS+=	-DUSE_XSHM -DHZ=100

PREFIX=		${X11BASE}
FILESDIR=	${.CURDIR}/../../graphics/libGL/files
WRKSRC=		${WRKDIR}/Mesa-${PORTVERSION}
CONFDIR=	${WRKSRC}/configs

SHVER?=		1

.if !defined(ARCH)
ARCH!=		uname -p
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

pre-patch:
	@${REINPLACE_CMD} \
		-e '/^CC =/d' -e '/^CXX =/d' \
		-e 's|/usr/X11R6|${X11BASE}|g' \
		-e 's|/usr/local|${LOCALBASE}|g' \
		-e 's|-lpthread|${PTHREAD_LIBS}|g' \
		-e 's|CFLAGS = |CFLAGS = ${CFLAGS} |g' \
		-e 's|OPT_FLAGS = .*|OPT_FLAGS = ${CFLAGS}|g' \
		-e "s|SRC_DIRS = .*|SRC_DIRS = ${SRCDIR}|g" \
		-e 's|-DHAVE_POSIX_MEMALIGN||' \
		${CONFDIR}/freebsd-dri
	@${REINPLACE_CMD} \
		-e 's|^\(MKDEP_OPTIONS.*\)|\1 -- -I${X11BASE}/include|' \
		-e 's|^\(MKLIB_OPTIONS.*\)|\1 -L${X11BASE}/lib|' \
		-e 's|^DRI_DRIVER_INSTALL_DIR.*|DRI_DRIVER_INSTALL_DIR = ${X11BASE}/lib/dri|' \
		${CONFDIR}/default

.if !target(do-install)
do-install:
	${MKDIR} ${PREFIX}/include/GL/
.for i in ${HEADERS}
	${INSTALL_DATA} ${WRKSRC}/${HEADERSDIR}/${i} ${PREFIX}/include/GL/
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/lib/${PORTNAME}.so.${SHVER} ${PREFIX}/lib
	${LN} -sf ${PORTNAME}.so.${SHVER} ${PREFIX}/lib/${PORTNAME}.so
.endif
