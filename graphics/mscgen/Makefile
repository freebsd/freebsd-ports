# Created by: Romain Tartiere <romain@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mscgen
PORTVERSION=	0.20
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://www.mcternan.me.uk/mscgen/software/ \
		http://romain.blogreen.org/distfiles/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Message Sequence Chart Renderer

OPTIONS_DEFINE=	FREETYPE PNG
OPTIONS_DEFAULT=FREETYPE PNG

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFREETYPE}
CONFIGURE_ARGS+=--with-freetype
LIB_DEPENDS+=	libfreetype.so:print/freetype2
.else
CONFIGURE_ARGS+=--without-freetype
.endif

.if ${PORT_OPTIONS:MPNG}
CONFIGURE_ARGS+=--with-png
LIB_DEPENDS+=	libgd.so:graphics/gd
.else
CONFIGURE_ARGS+=--without-png
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes

MAN1=		mscgen.1

.include <bsd.port.mk>
