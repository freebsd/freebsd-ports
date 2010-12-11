# New ports collection makefile for:	webp
# Date created:		1 October 2010
# Whom:			johans
#
# $FreeBSD$
#

PORTNAME=	webp
PORTVERSION=	0.0.5
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
CONFIGURE_WRKSRC=	${WRKSRC}/libwebp
CONFIGURE_ARGS+=	LDFLAGS="-L${WRKSRC}/leptonlib-1.066/lib/nodebug"
CFLAGS+=	-I${WRKSRC}/leptonlib-1.066/src -I/usr/local/include
WRKSRC=		${WRKDIR}/${PORTNAME}
INSTALL_WRKSRC=	${CONFIGURE_WRKSRC}

PLIST_FILES=	bin/webpconv

pre-configure:
.for f in missing depcomp install-sh
		@cd ${WRKSRC}/libwebp && ${LN} -sf ../leptonlib-1.066/config/$f
.endfor
		@${REINPLACE_CMD} -e '/^CFLAGS =/s:$$: -I/usr/local/include:' \
			${WRKSRC}/leptonlib-1.066/src/makefile

do-build:
		${GMAKE} -C ${WRKSRC}/leptonlib-1.066/src
		${MAKE} -C ${WRKSRC}/libwebp

.include <bsd.port.mk>
