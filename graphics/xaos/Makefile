# New ports collection makefile for:	XaoS
# Date created:				24 February 1996
# Whom:					Joseph Koshy <koshy@india.hp.com>
#
# $FreeBSD$
#

PORTNAME=	xaos
PORTVERSION=	3.2.3
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

OPTIONS=	PTHREAD "Enable experimental SMP support" off

CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${PREFIX}/lib -L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-aa-driver=no --with-dga-driver=no \
		--with-ggi-driver=no --with-svga-driver=no \
		--with-included-gettext=yes \
		--with-x --with-png=yes \
		--with-mit-shm=yes

MAN6=		xaos.6
INFO=		xaos

PLIST_SUB+=	XAOSDIR="share/XaoS"

.include <bsd.port.pre.mk>

.if defined(WITH_PTHREAD)
CONFIGURE_ARGS+=	--with-pthread=yes
CONFIGURE_ENV+=		LIBS="${PTHREAD_LIBS}" \
			CFLAGS="${PTHREAD_CFLAGS} ${CFLAGS}"
.else
CONFIGURE_ARGS+=	--with-pthread=no
.endif

post-install:
	${STRIP_CMD} ${PREFIX}/bin/xaos

.include <bsd.port.post.mk>
