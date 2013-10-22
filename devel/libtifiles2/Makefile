# $FreeBSD$

PORTNAME=	libtifiles2
PORTVERSION=	1.1.6
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/tilp/tilp2-linux/tilp2-1.17

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	TI calculator file types library

LICENSE=	GPLv2

LIB_DEPENDS=	libticonv.so:${PORTSDIR}/converters/libticonv

USE_BZIP2=	yes
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USES=		gmake pathfix pkgconfig

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ARCHIVE_CFLAGS=" " ARCHIVE_LIBS="-larchive"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's/libarchive/glib-2.0,ticonv/' \
		-e '/Requires:/d' ${WRKSRC}/tifiles2.pc.in

.include <bsd.port.mk>
