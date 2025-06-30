PORTNAME=	gnotime
DISTVERSION=	g20231022
PORTREVISION=	4
CATEGORIES=	deskutils gnome

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Time tracker for  GTK 3/WebkitGTK
WWW=		https://github.com/GnoTime/gnotime

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	autoconf-archive>=0:devel/autoconf-archive \
		scrollkeeper-config:textproc/rarian
LIB_DEPENDS=	libqof.so:databases/qof \
		libgc-threaded.so:devel/boehm-gc-threaded \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libsoup-2.4.so:devel/libsoup \
		libguile-2.2.so:lang/guile2 \
		libharfbuzz.so:print/harfbuzz \
		libwebkit2gtk-4.0.so:www/webkit2-gtk@40

USES=		autoreconf desktop-file-utils gettext gmake gnome libtool pathfix pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	GnoTime
GH_PROJECT=	gnotime
GH_TAGNAME=	ee0ddbcb8945fc6b11a49b107b738e3c934357a1
USE_XORG=	sm ice xscrnsaver x11
USE_GNOME=	cairo gconf2 gdkpixbuf glib20 gtk30 libxml2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
INSTALL_TARGET=	install-strip
INSTALLS_OMF=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

GCONF_SCHEMAS=	gnotime.schemas

#post-patch:
#	@${REINPLACE_CMD} -e \
#		'/^install-data-am/s|install-data-local||' \
#		${WRKSRC}/gconf/Makefile.in
#	@${REINPLACE_CMD} -e \
#		'/^AM_CFLAGS =/s|-g||' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
