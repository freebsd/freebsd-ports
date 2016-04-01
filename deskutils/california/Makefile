# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	california
PORTVERSION=	0.4.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Calendar client for GNOME 3

IGNORE=		Not compatible with evolution-data-server 3.16.0

BUILD_DEPENDS=	itstool:textproc/itstool \
		xdg-open:devel/xdg-utils
LIB_DEPENDS=	libwebkitgtk-3.0.so:www/webkit-gtk3 \
		libsoup-2.4.so:devel/libsoup \
		libgee-0.8.so:devel/libgee \
		libgdata.so:devel/libgdata \
		libgoa-1.0.so:net/gnome-online-accounts
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		desktop-file-utils gettext gmake libtool pathfix \
		pkgconfig tar:xz
USE_GNOME=	evolutiondataserver3 glib20 gnomedocutils gnomeprefix \
		gtk30 intlhack introspection
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--disable-unity
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
GLIB_SCHEMAS=	org.yorba.california.gschema.xml

post-patch:
		@${REINPLACE_CMD} -e 's|californiadocdir = $${prefix}|californiadocdir = $${prefix}/share|g' \
			${WRKSRC}/Makefile.in

.include <bsd.port.mk>
