# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-utils
PORTVERSION=	1.6.0
CATEGORIES=	deskutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE support utilities

BUILD_DEPENDS=	gtkdoc-check:${PORTSDIR}/textproc/gtk-doc \
		scrollkeeper-config:${PORTSDIR}/textproc/rarian
LIB_DEPENDS=	libgtop-2.0.so:${PORTSDIR}/devel/libgtop \
		libcanberra-gtk.so:${PORTSDIR}/audio/libcanberra

PORTSCOUT=	limitw:1,even

USES=		gettext gmake pathfix pkgconfig
USE_XZ=		yes
USE_MATE=	autogen common:build docutils intlhack ltverhack \
		panel
USE_XORG=	x11 xext
USE_GNOME=	glib20 gnomehier gtk20
USE_LDCONFIG=	yes
INSTALLS_OMF=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
CONFIGURE_ARGS=	--enable-maintainer-flags=no \
		--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PATHFIX_MAKEFILEIN=	Makefile.*

GLIB_SCHEMAS=	org.mate.dictionary.gschema.xml \
		org.mate.disk-usage-analyzer.gschema.xml \
		org.mate.screenshot.gschema.xml \
		org.mate.search-tool.gschema.xml \
		org.mate.system-log.gschema.xml

.include <bsd.port.mk>
