# New ports collection makefile for:	seed
# Date created:				19 July 2009
# Whom:					Alexander Logvinov <avl@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/seed/Makefile,v 1.8 2009/10/19 19:33:26 kwm Exp $
#

PORTNAME=	seed
PORTVERSION=	2.28.1
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
		mpfr.3:${PORTSDIR}/math/mpfr

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
	@${FIND} ${WRKSRC}/examples -name Makefile.in -type f | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$(datadir)/doc/seed/examples|${EXAMPLESDIR}|g'
.if defined(NOPORTEXAMPLES)
	@${REINPLACE_CMD} -e 's|examples||g' \
		${WRKSRC}/Makefile.in
.endif
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's| install-seeddocDATA||g ; s|doc$$||g' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
