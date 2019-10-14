# Created by: Alex Samorukov <samm@freebsd.org>
# $FreeBSD$

PORTNAME=	anyremote
PORTVERSION=	6.7.2
CATEGORIES=	comms
MASTER_SITES=	SF

MAINTAINER=	samm@freebsd.org
COMMENT=	Remote control service over Bluetooth, infrared, or TCP/IP networking

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libavahi-client.so:net/avahi-app

USES=		alias iconv pkgconfig python shebangfix gnome xorg
USE_GNOME=	glib20
SHEBANG_FILES=	cfg-data/Utils/all-in-1.py
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}

OPTIONS_DEFINE=	DOCS DBUS X11
OPTIONS_DEFAULT=	DBUS X11

DBUS_CONFIGURE_ENABLE=dbus
DBUS_LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib

X11_CONFIGURE_ENABLE=xtest
X11_USE=	XORG=x11,xtst

MAKE_ARGS+=	LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|(datadir)/man/man1|(mandir)/man1|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|xtext|xtest|g' ${WRKSRC}/configure
post-patch-DOCS-on:
	@${REINPLACE_CMD} -e '/doc\/${PORTNAME}/d' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
