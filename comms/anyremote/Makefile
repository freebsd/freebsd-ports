# Created by: Alex Samorukov <samm@os2.kiev.ua>
# $FreeBSD$

PORTNAME=	anyremote
PORTVERSION=	6.3.1
CATEGORIES=	comms
MASTER_SITES=	SF

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	Remote control service over Bluetooth, infrared, or TCP/IP networking

LICENSE=	GPLv2

USES=		iconv pkgconfig
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}

OPTIONS_DEFINE=	DOCS DBUS X11
OPTIONS_DEFAULT=	DBUS X11

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDBUS}
CONFIGURE_ARGS+=--disable-dbus
.else
LIB_DEPENDS+=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
.endif

.if ! ${PORT_OPTIONS:MX11}
CONFIGURE_ARGS+=--disable-xtest
.else
USE_XORG=	x11 xtst
.endif

MAKE_ARGS+=	LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		anyremote.1
MANCOMPRESSED=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|(datadir)/man/man1|(mandir)/man1|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|xtext|xtest|g' ${WRKSRC}/configure
.if ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/doc\/${PORTNAME}/d' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
