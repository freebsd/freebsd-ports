# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

# WARNING: when updating this port check if the ports that use libvisual
# can work with it. Backwards compatibility is known to be broken in the past.

PORTNAME=	libvisual
PORTVERSION=	0.2.0
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Abstraction library that sits between apps and visual plugin

LICENSE=	LGPL21+

PORTSCOUT=	limit:^0\.2\.

USES=		libtool pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
CFLAGS+=	-mmmx
.endif

.include <bsd.port.post.mk>
