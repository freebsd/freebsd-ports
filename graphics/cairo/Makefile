# New ports collection makefile for:	cairo
# Date created:		2004-10-06
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/graphics/cairo/Makefile,v 1.30 2005/10/04 04:35:57 ahze Exp $
#

PORTNAME=	cairo
PORTVERSION=	1.0.4
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/releases/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ahze

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Vector graphics library with cross-device output support

.if !defined(REFERENCE_PORT)

PORTREVISION=	1

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		png.5:${PORTSDIR}/graphics/png \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig

CONFIGURE_ARGS=	--with-html-dir=${DOCSDIR} \
		--enable-pdf \
		--enable-ps
USE_GNOME=	gnometarget gnomehack ltverhack referencehack
USE_AUTOTOOLS=	libtool:15
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} -I${X11BASE}/include" \
		LDFLAGS="${PTHREAD_LIBS}"

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

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=--disable-xlib
PLIST_SUB+=	X11="@comment "
.else
USE_XLIB=	yes
PLIST_SUB+=	X11=""
.endif

post-patch:
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|stdint.h|inttypes.h|' \
		${WRKSRC}/src/*.* \
		${WRKSRC}/pixman/src/*.*
.endif
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' \
		${WRKSRC}/test/Makefile.in

.include <bsd.port.post.mk>

.endif
