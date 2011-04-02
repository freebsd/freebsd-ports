# New ports collection makefile for:	webp
# Date created:		1 October 2010
# Whom:			johans
#
# $FreeBSD$
#

PORTNAME=	webp
PORTVERSION=	0.1.2
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	lib${PORTNAME}-${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Google WebP image format conversion tool

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png

USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf:env libtoolize:env automake:env
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig
CPPFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

MAN1=		cwebp.1 dwebp.1

pre-configure:
	@cd ${WRKSRC} && ${AUTORECONF} -vfi

.include <bsd.port.mk>
