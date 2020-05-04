# Created by: Romain Tartiere <romain@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mscgen
PORTVERSION=	0.20
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://www.mcternan.me.uk/mscgen/software/ \
		http://romain.blogreen.org/distfiles/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Message Sequence Chart Renderer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libtiff.so:graphics/tiff \
		libwebp.so:graphics/webp

USES=		jpeg

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=			FREETYPE PNG
OPTIONS_DEFAULT=		FREETYPE PNG

FREETYPE_CONFIGURE_WITH=	freetype
FREETYPE_LIB_DEPENDS=		libfreetype.so:print/freetype2

PNG_CONFIGURE_WITH=		png
PNG_LIB_DEPENDS=		libgd.so:graphics/gd \
				libpng16.so:graphics/png

.include <bsd.port.mk>
