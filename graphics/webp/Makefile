# New ports collection makefile for:	webp
# Date created:		1 October 2010
# Whom:			johans
#
# $FreeBSD$
#

PORTNAME=	webp
DISTVERSION=	0.1.2-rc1
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	lib${PORTNAME}-${DISTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Google WebP image format conversion tool

LIB_DEPENDS=	vpx.0:${PORTSDIR}/multimedia/libvpx \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/lib${PORTNAME}-${PORTVERSION:R}

USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

MAN1=		cwebp.1 dwebp.1

.include <bsd.port.mk>
