# Created by: db
# $FreeBSD$

PORTNAME=	tlf
PORTVERSION=	1.4.1
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	comms hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio curses based logging program

LICENSE=	GPLv2

LIB_DEPENDS=	libargp.so:devel/argp-standalone
RUN_DEPENDS=	rec:audio/sox \
		wget:ftp/wget

USES=		autoreconf gnome ncurses pkgconfig
USE_GITHUB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PANEL_LIB=-lpanel
USE_GNOME=	glib20
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -largp" \
		CPPFLAGS=-I${LOCALBASE}/include

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	HAMLIB FLDIGI DOCS
HAMLIB_DESC=	Support rig control via hamlib
FLDIGI_DESC=	Support fldigi XML-RPC integration
OPTIONS_DEFAULT=HAMLIB FLDIGI

HAMLIB_LIB_DEPENDS=	libhamlib.so:comms/hamlib
HAMLIB_CONFIGURE_ENABLE=hamlib
FLDIGI_LIB_DEPENDS=	libxmlrpc.so:net/xmlrpc-c
FLDIGI_CONFIGURE_ENABLE=fldigi-xmlrpc

.include <bsd.port.mk>
