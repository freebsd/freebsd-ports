# $FreeBSD$

PORTNAME=	libticables2
PORTVERSION=	1.3.4
PORTREVISION=	3
CATEGORIES=	comms
MASTER_SITES=	SF/tilp/tilp2-linux/tilp2-1.17

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	TI calculator link cables library

LICENSE=	GPLv2

USE_GNOME=	glib20
USE_LDCONFIG=	yes
USES=		gmake libtool pathfix pkgconfig tar:bzip2

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBUSB_CFLAGS=" " LIBUSB_LIBS="-lusb"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's/Requires/&.private/' ${WRKSRC}/ticables2.pc.in

.include <bsd.port.mk>
