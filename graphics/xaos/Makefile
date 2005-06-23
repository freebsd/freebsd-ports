# New ports collection makefile for:	XaoS
# Date created:				24 February 1996
# Whom:					Joseph Koshy <koshy@india.hp.com>
#
# $FreeBSD$
#

PORTNAME=	xaos
PORTVERSION=	3.1.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xaos
DISTNAME=	XaoS-${PORTVERSION}

MAINTAINER=	jkoshy@freebsd.org
COMMENT=	A real-time fractal browser for X11 and ASCII terminals

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_XLIB=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes

OPTIONS=	SVGALIB "Enable svgalib support" off \
		AALIB "Enable aalib support" off \
		PTHREAD "Enable experimental threads support" off

CONFIGURE_ENV=	LDFLAGS="-L${PREFIX}/lib -L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-dga-driver=no

CFLAGS=		-DHAVE_SYS_PARAM_H \
		-I${LOCALBASE}/include \
		-I${PREFIX}/include \
		-pipe -O6 -fstrength-reduce -ffast-math -fomit-frame-pointer\
		-fforce-mem -fforce-addr -funroll-loops

MAN6=		xaos.6
INFO=		xaos

PLIST_SUB+=	XAOSDIR="share/XaoS"

.include <bsd.port.pre.mk>

.if defined(WITH_SVGALIB)
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
CONFIGURE_ARGS+=	--with-svga-driver=yes
.else
CONFIGURE_ARGS+=	--with-svga-driver=no
.endif

.if defined(WITH_AALIB)
LIB_DEPENDS+=	aa.1:${PORTSDIR}/graphics/aalib
CONFIGURE_ARGS+=	--with-aa-driver=yes
.else
CONFIGURE_ARGS+=	--with-aa-driver=no
.endif

.if defined(WITH_PTHREAD)
CONFIGURE_ARGS+=	--with-pthread=yes
CONFIGURE_ENV+=		LIBS="${PTHREAD_LIBS}" \
			CFLAGS="${PTHREAD_CFLAGS} ${CFLAGS}"
.else
CONFIGURE_ARGS+=	--with-pthread=no
.endif

# GCC 3.4.2 alleges prototype mismatches with __attribute__((regparm))
.if ${OSVERSION} >= 502125
CFLAGS+=	-DNOREGISTERS
.endif

.if ${ARCH} != "i386" && ${ARCH} != "amd64" && ${OSVERSION} >= 502102
BROKEN=		"Does not compile on FreeBSD >=5.x on !i386 and !amd64"
.endif

post-install:
	${STRIP_CMD} ${PREFIX}/bin/xaos

.include <bsd.port.post.mk>
