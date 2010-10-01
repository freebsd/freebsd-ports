# New ports collection makefile for:	webp
# Date created:		1 October 2010
# Whom:			johans
#
# $FreeBSD$
#

PORTNAME=	webp
PORTVERSION=	0.0.1
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-leptonica-${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Google WebP image format conversion tool

LIB_DEPENDS=	vpx.0:${PORTSDIR}/multimedia/libvpx \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_WRKSRC=	${WRKSRC}/leptonlib-1.066
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/webpconv

pre-patch:
		@${REINPLACE_CMD} -e '/^CFLAGS =/s:$$: -I/usr/local/include:' \
			${CONFIGURE_WRKSRC}/src/makefile
		@${REINPLACE_CMD} -e '/^INCLUDES =/s:$$: -I/usr/local/include:'\
			-e '/^LDFLAGS /s:$$: -L/usr/local/lib:' \
			-e 's:-o webpconv:& $$(LDFLAGS):' \
			${WRKSRC}/libwebp/makefile

do-build:
		${GMAKE} -C ${CONFIGURE_WRKSRC}/src
		${GMAKE} -C ${WRKSRC}/libwebp

do-install:
		@${INSTALL_PROGRAM} ${WRKSRC}/libwebp/webpconv ${PREFIX}/bin

.include <bsd.port.mk>
