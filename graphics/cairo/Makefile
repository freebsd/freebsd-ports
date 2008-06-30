# New ports collection makefile for:	cairo
# Date created:		2004-10-06
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-stable/graphics/cairo/Makefile,v 1.3 2008/06/16 21:35:57 mezz Exp $
#

PORTNAME=	cairo
PORTVERSION=	1.6.4
PORTREVISION?=	2
PORTEPOCH?=	1
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/releases/
#MASTER_SITES=	http://cairographics.org/snapshots/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Vector graphics library with cross-device output support

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		png.5:${PORTSDIR}/graphics/png \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \
		pixman-1.9:${PORTSDIR}/x11/pixman

CONFIGURE_ARGS=	--with-html-dir=${DOCSDIR} \
		--enable-pdf \
		--enable-ps
USE_GNOME=	gnometarget gnomehack ltverhack referencehack
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes

CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" \
		LDFLAGS="${PTHREAD_LIBS}"

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=--disable-xlib
PLIST_SUB+=	X11="@comment "
.else
USE_XORG+=	xrender
PLIST_SUB+=	X11=""
.endif

OPTIONS+=	GLITZ "Enable Glitz OpenGL Support" Off

.include <bsd.port.pre.mk>

.if defined(WITH_GLITZ)
LIB_DEPENDS+=	glitz-glx.1:${PORTSDIR}/graphics/glitz
CONFIGURE_ARGS+=	--enable-glitz
PLIST_SUB+=	GLITZ=""
.else
CONFIGURE_ARGS+=	--disable-glitz
PLIST_SUB+=	GLITZ="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' \
		${WRKSRC}/test/Makefile.in
	@${REINPLACE_CMD} -e 's|-lcairo|-lcairo ${PTHREAD_LIBS}|' \
		${WRKSRC}/src/*.pc.in
	@${REINPLACE_CMD} -e 's|src test doc|src doc|; \
		s|@CAIRO_HAS_PNG_FUNCTIONS_TRUE@am__append_1 = test||' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>

.endif
