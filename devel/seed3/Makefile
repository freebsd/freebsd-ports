# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/seed3/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	seed
PORTVERSION=	3.2.0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject JavaScriptCore bridge

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-js-common.pc:${PORTSDIR}/devel/gnome-js-common
LIB_DEPENDS=	ffi:${PORTSDIR}/devel/libffi \
		webkitgtk-3.0:${PORTSDIR}/www/webkit-gtk3 \
		girepository-1:${PORTSDIR}/devel/gobject-introspection \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		mpfr:${PORTSDIR}/math/mpfr

CONFLICTS=	seed-2.[0-9]*

LATEST_LINK=	seed3
USE_XZ=		yes
GNU_CONFIGURE=	yes
USES=		pathfix gettext gmake pkgconfig
USE_GNOME=	gtk30 intltool libxml2
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USE_SQLITE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--enable-gtk-doc=no --with-webkit=3.0
DATADIR=	share/seed-gtk3

MAN1=		seed.1

NO_STAGE=	yes
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

.include <bsd.port.mk>
