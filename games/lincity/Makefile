# Created by: Julian Assange
# $FreeBSD$

PORTNAME=	lincity
PORTVERSION=	1.13.1
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Lincity%20Development%20Source/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rich city simulation game for X

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

USES=		gmake
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN6=		lincity.6

OPTIONS_DEFINE=	SVGALIB NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSVGALIB}
LIB_DEPENDS+=	vga:${PORTSDIR}/graphics/svgalib
CONFIGURE_ARGS+=	--without-x
PLIST_SUB=	PROG="bin/lincity"
.else
USE_XORG=	sm xext
CONFIGURE_ARGS+=	--without-svga
PLIST_SUB=	PROG="bin/xlincity"
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|g' ${WRKSRC}/readpng.c

.include <bsd.port.mk>
