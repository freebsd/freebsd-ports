# $FreeBSD$

PORTNAME=	tilp2
PORTVERSION=	1.17
CATEGORIES=	comms
MASTER_SITES=	SF/tilp/tilp2-linux/${DISTNAME}

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	TI Linking Program

LICENSE=	GPLv2

LIB_DEPENDS=	ticables2:${PORTSDIR}/comms/libticables2	\
		tifiles2:${PORTSDIR}/devel/libtifiles2		\
		ticalcs2:${PORTSDIR}/comms/libticalcs2		\
		ticonv:${PORTSDIR}/converters/libticonv

USES=		pkgconfig
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20

OPTIONS_DEFINE=	NLS

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-kde
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		tilp.1

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
	@${REINPLACE_CMD} -e 's,^     USE_NLS=yes$$,,' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-D.*_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's,/usr,${LOCALBASE},' ${WRKSRC}/src/bookmark.c

.include <bsd.port.mk>
