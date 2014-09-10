# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/seed3/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	seed
PORTVERSION=	3.2.0
PORTREVISION=	5
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject JavaScriptCore bridge

OPTIONS_DEFINE=	DOCS

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-js-common.pc:${PORTSDIR}/devel/gnome-js-common
LIB_DEPENDS=	libffi.so:${PORTSDIR}/devel/libffi \
		libwebkitgtk-3.0.so:${PORTSDIR}/www/webkit-gtk3 \
		libgirepository-1.0.so:${PORTSDIR}/devel/gobject-introspection \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libmpfr.so:${PORTSDIR}/math/mpfr

CONFLICTS=	seed-2.[0-9]*

GNU_CONFIGURE=	yes
USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:xz
INSTALL_TARGET=	install-strip
USE_GNOME=	gtk30 intltool libxml2
USE_LDCONFIG=	yes
USE_SQLITE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--enable-gtk-doc=no --with-webkit=3.0
DATADIR=	share/seed-gtk3

post-patch:
	@${REINPLACE_CMD} -e 's|== x|= x|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-ldl||g' \
		${WRKSRC}/libseed/Makefile.in
	@${REINPLACE_CMD} -e 's|reference||g' ${WRKSRC}/doc/Makefile.in

pre-build:
	cd ${WRKSRC}/extensions && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
	    	${MAKE_FLAGS} Makefile ${MAKE_ARGS} all
	${CP} ${WRKSRC}/extensions/Seed.js ${WRKSRC}/extensions/Seed.js.sav
	${CP} ${FILESDIR}/Seed.js ${WRKSRC}/extensions/Seed.js

post-build:
	${CP} ${WRKSRC}/extensions/Seed.js.sav ${WRKSRC}/extensions/Seed.js

.include <bsd.port.mk>
