# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/seed/Makefile,v 1.35 2013/01/29 16:33:10 kwm Exp $

PORTNAME=	seed
PORTVERSION=	2.31.91
PORTREVISION=	8
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject JavaScriptCore bridge

OPTIONS_DEFINE=	DOCS

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-js-common.pc:${PORTSDIR}/devel/gnome-js-common
LIB_DEPENDS=	libffi.so:${PORTSDIR}/devel/libffi \
		libwebkitgtk-1.0.so:${PORTSDIR}/www/webkit-gtk2 \
		libgirepository-1.0.so:${PORTSDIR}/devel/gobject-introspection \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libmpfr.so:${PORTSDIR}/math/mpfr

CONFLICTS=	seed-3.[0-9]*

GNU_CONFIGURE=	yes
USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:bzip2
USE_GNOME=	gtk20 intltool libxml2
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
USE_SQLITE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lglib-2.0 -lgthread-2.0
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-gtk-doc=no --with-webkit=1.0

post-patch:
	@${REINPLACE_CMD} -e 's|== x|= x|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-ldl||g' \
		${WRKSRC}/libseed/Makefile.in
	@${REINPLACE_CMD} -e 's|reference||g' ${WRKSRC}/doc/Makefile.in
#	@${FIND} ${WRKSRC}/examples -name Makefile.in -type f | ${XARGS} ${REINPLACE_CMD} -e \
#		's|$$(datadir)/doc/seed/examples|${EXAMPLESDIR}|g'
#.if defined(NOPORTEXAMPLES)
#	@${REINPLACE_CMD} -e 's|examples||g' \
#		${WRKSRC}/Makefile.in
#.endif

pre-build:
	cd ${WRKSRC}/extensions && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
	    	${MAKE_FLAGS} Makefile ${MAKE_ARGS} all
	${CP} ${WRKSRC}/extensions/Seed.js ${WRKSRC}/extensions/Seed.js.sav
	${CP} ${FILESDIR}/Seed.js ${WRKSRC}/extensions/Seed.js

post-build:
	${CP} ${WRKSRC}/extensions/Seed.js.sav ${WRKSRC}/extensions/Seed.js

.include <bsd.port.mk>
