# New ports collection makefile for: gd
# Version required:     1.6.2
# Date created:         27 Mar 1998
# Whom:                 jeff@cetlink.net
#
# $FreeBSD$
#

DISTNAME=       gd-1.6.2
CATEGORIES=	graphics
MASTER_SITES=   http://www.boutell.com/gd/http/ \
		ftp://ftp.boutell.com/pub/boutell/gd/

MAINTAINER=     jeff@cetlink.net

LIB_DEPENDS=	png.3:${PORTSDIR}/graphics/png

FETCH_BEFORE_ARGS=	-b
USE_LIBTOOL=		yes
CONFIGURE_ENV+=		CFLAGS="${CFLAGS} -I${LOCALBASE}/include"
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/gd \
			--libdir=${PREFIX}/lib

pre-install:
	${MKDIR} ${PREFIX}/include/gd
	${MKDIR} ${PREFIX}/share/examples/gd

.include <bsd.port.mk>
