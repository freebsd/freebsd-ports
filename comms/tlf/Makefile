# Created by: db
# $FreeBSD$

PORTNAME=	tlf
PORTVERSION=	1.2.2
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.hs-mittweida.de/tb/ \
		LOCAL/db

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio curses based logging program

LICENSE=	GPLv2

LIB_DEPENDS=	libglib-2.0.so:devel/glib20

USES=		pkgconfig
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	HAMLIB
HAMLIB_DESC=	Support rig control via hamlib
OPTION_DEFAULT=	HAMLIB

HAMLIB_LIB_DEPENDS=	libhamlib.so:comms/hamlib
HAMLIB_CONFIGURE_ENABLE=hamlib

.include <bsd.port.mk>
