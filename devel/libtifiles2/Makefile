# $FreeBSD$

PORTNAME=	libtifiles2
PORTVERSION=	1.1.6
CATEGORIES=	devel
MASTER_SITES=	SF/tilp/tilp2-linux/tilp2-1.17

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	TI calculator file types library

LICENSE=	GPLv2

LIB_DEPENDS=	ticonv:${PORTSDIR}/converters/libticonv

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USES=		pathfix pkgconfig

OPTIONS_DEFINE=	NLS

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ARCHIVE_CFLAGS=" " ARCHIVE_LIBS="-larchive"
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

post-patch:
	@${REINPLACE_CMD} 's,libarchive,,' ${WRKSRC}/tifiles2.pc.in

.include <bsd.port.mk>
