# New ports collection makefile for:	cairo
# Date created:		2004-10-06
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cairo
PORTVERSION=	0.4.0
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/snapshots/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Vector graphics library with cross-device output support

LIB_DEPENDS=	pixman.1:${PORTSDIR}/graphics/libpixman \
		freetype.9:${PORTSDIR}/print/freetype2 \
		png.5:${PORTSDIR}/graphics/png \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig

USE_GNOME=	gnometarget gnomehack
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes

CONFIGURE_ARGS=	--with-html-dir=${DOCSDIR}

CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} -I${X11BASE}/include" \
		LDFLAGS="${PTHREAD_LIBS}"

OPTIONS+=	GLITZ "Enable Glitz OpenGL Support" Off

.include <bsd.port.pre.mk>

.if defined(WITH_GLITZ) || exists(${LOCALBASE}/lib/libglitz.a)
LIB_DEPENDS+=	glitz-glx.1:${PORTSDIR}/graphics/glitz
PLIST_SUB+=	GLITZ=""
.else
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
		${WRKSRC}/src/*.*
.endif

.include <bsd.port.post.mk>
