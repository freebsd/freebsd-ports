# $FreeBSD$

PORTNAME=	tilp2
PORTVERSION=	1.17
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	SF/tilp/tilp2-linux/${DISTNAME}

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	TI Linking Program

LICENSE=	GPLv2

LIB_DEPENDS=	libticables2.so:${PORTSDIR}/comms/libticables2	\
		libtifiles2.so:${PORTSDIR}/devel/libtifiles2	\
		libticalcs2.so:${PORTSDIR}/comms/libticalcs2	\
		libticonv.so:${PORTSDIR}/converters/libticonv

USES=		desktop-file-utils gmake pkgconfig shared-mime-info
USE_BZIP2=	yes
USE_GNOME=	gtk20

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-kde
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's,^     USE_NLS=yes$$,,' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-D.*_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's,/usr,${LOCALBASE},' ${WRKSRC}/src/bookmark.c

.include <bsd.port.mk>
