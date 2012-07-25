# New ports collection makefile for:	anyremote
# Date created:		2008-11-05
# Whom:			Alex Samorukov <samm@os2.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	anyremote
PORTVERSION=	5.4.2
CATEGORIES=	comms
MASTER_SITES=	SF

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	Remote control service over Bluetooth, infrared, or TCP/IP networking

USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

LICENSE=	GPLv2

OPTIONS=	DBUS		"Build with DBUS support" on \
		X11		"Build with X11 library" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_DBUS)
CONFIGURE_ARGS+=--disable-dbus
.else
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
.endif

.if defined(WITHOUT_X11)
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
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/doc\/${PORTNAME}/d' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
