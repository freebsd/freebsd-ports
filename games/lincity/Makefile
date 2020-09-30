# Created by: Julian Assange
# $FreeBSD$

PORTNAME=	lincity
PORTVERSION=	1.13.1
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Lincity%20Development%20Source/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rich city simulation game for X

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png

USES=		gmake
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS SVGALIB
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

SVGALIB_LIB_DEPENDS=	libvga.so:graphics/svgalib
SVGALIB_CONFIGURE_ON=	--without-x
SVGALIB_CONFIGURE_OFF=	--without-svga

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSVGALIB}
PLIST_SUB+=	PROG="bin/lincity"
.else
USES+=		xorg
USE_XORG=	ice sm x11 xext
PLIST_SUB+=	PROG="bin/xlincity"
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|g' ${WRKSRC}/readpng.c

.include <bsd.port.mk>
