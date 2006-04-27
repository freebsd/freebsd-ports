# New ports collection makefile for:	gnash
# Date created:				12 Jan 2006
# Whom:					Dmitry Marakasov <amdmi3@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	gnash
PORTVERSION=	0.7
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ale
DISTNAME=	${PORTNAME}-20060422

MAINTAINER=	amdmi3@mail.ru
COMMENT=	GNU Flash movie player

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		ogg.5:${PORTSDIR}/audio/libogg

USE_BZIP2=	yes
USE_GL=		yes
USE_GMAKE=	yes
USE_GNOME=	gnomehier glib20 pkgconfig libxml2
USE_SDL=	sdl mixer
USE_X_PREFIX=	yes
USE_GCC=	3.4+

USE_AUTOTOOLS=	aclocal:19 autoheader:259 automake:19 autoconf:259
ACLOCAL_ARGS=	--acdir=${ACLOCAL_DIR} -I ${WRKSRC}/macros

PLUGIN_DIR=	${PREFIX}/lib/browser_plugins

CONFIGURE_ENV=	LDFLAGS="${LDFLAGS} -Wl,--rpath,${PREFIX}/lib/gnash"

CONFIGURE_ARGS=	--libdir="${PREFIX}/lib/gnash" \
		--with-plugindir=${PLUGIN_DIR}

WRKSRC=		${WRKDIR}/${PORTNAME}-20060422

OPTIONS=	PLUGIN	"Enable firefox plugin" off

.include <bsd.port.pre.mk>

.if !defined(WITH_PLUGIN)
CONFIGURE_ARGS+=	--disable-plugin
PLIST_SUB+=	PLUGIN="@comment "
.else
USE_GNOME+=	atk pango gtk20
LIB_DEPENDS+=	gtkglext-x11-1.0.2:${PORTSDIR}/x11-toolkits/gtkglext
PLIST_SUB+=	PLUGIN=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/macros/*.m4
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${X11BASE}|g' ${WRKSRC}/macros/*.m4
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/macros/*.m4
	@${REINPLACE_CMD} -e 's|^AM_LDFLAGS = \\|AM_LDFLAGS = $$(PTHREAD_LIBS) \\|' ${WRKSRC}/utilities/Makefile.am
.if !defined(WITH_PLUGIN)
	@${REINPLACE_CMD} -e '/STD_DIRS/ s|plugin||' ${WRKSRC}/Makefile.am
.endif

.include <bsd.port.post.mk>
