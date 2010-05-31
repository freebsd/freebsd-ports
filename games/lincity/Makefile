# New ports collection makefile for:    lincity
# Date created:         13 Feb 1997
# Whom:                 Julian Assange
#
# $FreeBSD$
#

PORTNAME=	lincity
PORTVERSION=	1.13.1
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Lincity%20Development%20Source/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rich city simulation game for X

LIB_DEPENDS=	png:${PORTSDIR}/graphics/png

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN6=		lincity.6

pre-configure:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|g' ${WRKSRC}/readpng.c

.if defined(WITH_SVGALIB)
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
CONFIGURE_ARGS+=	--without-x
PLIST_SUB=	PROG="bin/lincity"
.else
USE_XORG=	sm xext
CONFIGURE_ARGS+=	--without-svga
PLIST_SUB=	PROG="bin/xlincity"
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
