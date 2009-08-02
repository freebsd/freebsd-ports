# New ports collection makefile for:	libvisual
# Date created:		23 oktober 2004
# Whom:			Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

# WARNING: when updating this port check if the ports that use libvisual
# can work with it. Backwards compatibility is known to be broken in the past.

PORTNAME=	libvisual
PORTVERSION=	0.2.0
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Abstraction library that sits between apps and visual plugin

USE_GNOME=	gnomehack pkgconfig
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" || ${ARCH} == "amd64"
CFLAGS+=	-mmmx
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Wno-unused-variable||g' \
		-e 's|-O3|${CFLAGS}|g' \
		${WRKSRC}/libvisual/Makefile.in

.include <bsd.port.post.mk>
