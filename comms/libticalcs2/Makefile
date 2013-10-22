# $FreeBSD$

PORTNAME=	libticalcs2
PORTVERSION=	1.1.8
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	SF/tilp/tilp2-linux/tilp2-1.17

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	TI calculator library

LICENSE=	GPLv2

LIB_DEPENDS=	libticables2.so:${PORTSDIR}/comms/libticables2	\
		libticonv.so:${PORTSDIR}/converters/libticonv	\
		libtifiles2.so:${PORTSDIR}/devel/libtifiles2

USE_BZIP2=	yes
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USES=		gmake pathfix pkgconfig

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's/Requires/&.private/' ${WRKSRC}/ticalcs2.pc.in

.include <bsd.port.mk>
