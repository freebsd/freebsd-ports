# New ports collection makefile for:	XaoS
# Date created:				24 February 1996
# Whom:					Joseph Koshy <koshy@india.hp.com>
#
# $FreeBSD$
#

PORTNAME=	xaos
PORTVERSION=	3.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_XCONTRIB} \
		ftp://ftp.ta.jcu.cz/pub/linux/hubicka/XaoS/3.0/ \
		http://www.paru.cas.cz/~hubicka/XaoS/dist/
MASTER_SITE_SUBDIR=	graphics
DISTNAME=	XaoS-${PORTVERSION}

MAINTAINER=	jkoshy@freebsd.org

LIB_DEPENDS=	png.4:${PORTSDIR}/graphics/png
.if defined(WITH_SVGALIB)
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
.endif

USE_XLIB=	yes

# This port will benefit from all-stops-out optimization of the code

GNU_CONFIGURE=	yes
CONFIGURE_ENV=  LDFLAGS=-L${LOCALBASE}/lib
.if !defined(WITH_SVGALIB)
CONFIGURE_ARGS=	--with-svga-driver=no
.endif

CFLAGS=		-DHAVE_SYS_PARAM_H \
		-I${PREFIX}/include \
		-pipe -O6 -fstrength-reduce -ffast-math -fomit-frame-pointer\
		-fforce-mem -fforce-addr -funroll-loops
MAN6=		xaos.6

post-install:
	strip ${PREFIX}/bin/xaos
	install-info ${PREFIX}/info/xaos.info ${PREFIX}/info/dir

.include <bsd.port.mk>
