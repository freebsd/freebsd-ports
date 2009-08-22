# New ports collection makefile for:	XaoS
# Date created:				24 February 1996
# Whom:					Joseph Koshy <koshy@india.hp.com>
#
# $FreeBSD$
#

PORTNAME=	xaos
PORTVERSION=	3.4
PORTREVISION=	1
CATEGORIES=	graphics math
MASTER_SITES=	SF/${PORTNAME}/XaoS/${PORTVERSION}
DISTNAME=	XaoS-${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	A real-time fractal browser for X11 and ASCII terminals

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_XORG=	x11 xau xdmcp xext
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:262

OPTIONS=	PTHREAD "Enable SMP support (experimental)" off \
		NLS "Native Language Support" on

CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${PREFIX}/lib -L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-aa-driver=no --with-dga-driver=no \
		--with-ggi-driver=no --with-svga-driver=no \
		--with-sffe=no

MAN6=		xaos.6
INFO=		xaos

PLIST_SUB+=	XAOSDIR="share/XaoS"

DESKTOP_ENTRIES="XaoS" "Fractal zoomer" "" "xaos" "" false

.include <bsd.port.pre.mk>

.if defined(WITH_PTHREAD)
CONFIGURE_ARGS+=	--with-pthread=yes
CONFIGURE_ENV+=		LIBS="${PTHREAD_LIBS}" \
			CFLAGS="${PTHREAD_CFLAGS} ${CFLAGS}"
.else
CONFIGURE_ARGS+=	--with-pthread=no
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.post.mk>
