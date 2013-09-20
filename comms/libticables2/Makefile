# $FreeBSD$

PORTNAME=	libticables2
PORTVERSION=	1.3.4
CATEGORIES=	comms
MASTER_SITES=	SF/tilp/tilp2-linux/tilp2-1.17

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	TI calculator link cables library

LICENSE=	GPLv2

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USES=		pathfix pkgconfig

OPTIONS_DEFINE=	NLS

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBUSB_CFLAGS=" " LIBUSB_LIBS="-lusb"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
