# New ports collection makefile for:	seed
# Date created:				19 July 2009
# Whom:					Alexander Logvinov <avl@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/seed/Makefile,v 1.19 2010/05/08 17:04:45 marcus Exp $
#
# NOTE: It may be necessary to update ${FILESDIR}/Seed.js on each release.
# To do that, just replace imports.searchPaths with "." and ".." elements.
#

PORTNAME=	seed
PORTVERSION=	2.30.0
PORTREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject JavaScriptCore bridge

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-js-common.pc:${PORTSDIR}/devel/gnome-js-common
LIB_DEPENDS=	ffi.5:${PORTSDIR}/devel/libffi \
		webkit-1.0.13:${PORTSDIR}/www/webkit-gtk2 \
		girepository-1.0.0:${PORTSDIR}/devel/gobject-introspection \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		mpfr.4:${PORTSDIR}/math/mpfr

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehack gtk20 intltool libxml2
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=--enable-gtk-doc=no

MAN1=		seed.1

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|== x|= x|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|reference||g' ${WRKSRC}/doc/Makefile.in
#	@${FIND} ${WRKSRC}/examples -name Makefile.in -type f | ${XARGS} ${REINPLACE_CMD} -e \
#		's|$$(datadir)/doc/seed/examples|${EXAMPLESDIR}|g'
#.if defined(NOPORTEXAMPLES)
#	@${REINPLACE_CMD} -e 's|examples||g' \
#		${WRKSRC}/Makefile.in
#.endif
.if defined(NOPORTDOCS)
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

.include <bsd.port.post.mk>
