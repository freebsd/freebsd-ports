# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/seed3/Makefile 18610 2013-06-30 16:33:05Z marcus $
# NOTE: It may be necessary to update ${FILESDIR}/Seed.js on each release.
# To do that, just replace imports.searchPaths with "." and ".." elements.

PORTNAME=	seed
PORTVERSION=	3.2.0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject JavaScriptCore bridge

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-js-common.pc:${PORTSDIR}/devel/gnome-js-common
LIB_DEPENDS=	libffi.so:${PORTSDIR}/devel/libffi \
		libwebkitgtk-3.0.so:${PORTSDIR}/www/webkit-gtk3 \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libmpfr.so:${PORTSDIR}/math/mpfr

USE_XZ=		yes
GNU_CONFIGURE=	yes
USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	gtk30 intltool libxml2 introspection
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USE_SQLITE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--enable-gtk-doc=no --with-webkit=3.0
DATADIR=	share/seed-gtk3

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|== x|= x|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-ldl||g' \
		${WRKSRC}/libseed/Makefile.in
	@${REINPLACE_CMD} -e 's|reference||g' ${WRKSRC}/doc/Makefile.in
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's| install-seeddocDATA||g ; s|doc$$||g' \
		${WRKSRC}/Makefile.in
.endif

pre-build:
	cd ${WRKSRC}/extensions && ${SETENV} ${MAKE_ENV} ${GMAKE} \
	    	${MAKE_FLAGS} Makefile ${MAKE_ARGS} all
	${CP} ${WRKSRC}/extensions/Seed.js ${WRKSRC}/extensions/Seed.js.sav
	${CP} ${FILESDIR}/Seed.js ${WRKSRC}/extensions/Seed.js

post-build:
	${CP} ${WRKSRC}/extensions/Seed.js.sav ${WRKSRC}/extensions/Seed.js

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/seed-gtk3/libseed_*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libseed-gtk3.so.0

.include <bsd.port.mk>
