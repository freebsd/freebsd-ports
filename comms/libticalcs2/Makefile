# $FreeBSD$

PORTNAME=	libticalcs2
PORTVERSION=	1.1.8
CATEGORIES=	comms
MASTER_SITES=	SF/tilp/tilp2-linux/tilp2-1.17

MAINTAINER=	tijl@coosemans.org
COMMENT=	TI calculator library

LICENSE=	GPLv2

LIB_DEPENDS=	ticables2:${PORTSDIR}/comms/libticables2	\
		ticonv:${PORTSDIR}/converters/libticonv		\
		tifiles2:${PORTSDIR}/devel/libtifiles2

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USE_PKGCONFIG=	build
USES=		pathfix

OPTIONS_DEFINE=	NLS

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
