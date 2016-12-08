# $FreeBSD$

PORTNAME=	libticalcs2
PORTVERSION=	1.1.8
PORTREVISION=	3
CATEGORIES=	comms
MASTER_SITES=	SF/tilp/tilp2-linux/tilp2-1.17

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	TI calculator library

LICENSE=	GPLv2

LIB_DEPENDS=	libticables2.so:comms/libticables2	\
		libticonv.so:converters/libticonv	\
		libtifiles2.so:devel/libtifiles2

USE_GNOME=	glib20
USE_LDCONFIG=	yes
USES=		gmake libtool pathfix pkgconfig tar:bzip2

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
LIBS+=		`pkg-config --libs glib-2.0`

post-patch:
	@${REINPLACE_CMD} -e 's/Requires/&.private/' ${WRKSRC}/ticalcs2.pc.in

.include <bsd.port.mk>
