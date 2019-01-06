# Created by: db
# $FreeBSD$

PORTNAME=	tlf
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.hs-mittweida.de/tb/ \
		LOCAL/shurd

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio curses based logging program

LICENSE=	GPLv2

RUN_DEPENDS=	rec:audio/sox \
		wget:ftp/wget

USES=		ncurses pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PANEL_LIB=-lpanel
USE_GNOME=	glib20
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib

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
