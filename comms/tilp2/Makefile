# New ports collection makefile for:	tilp2
# Date created:		11 October 2006
# Whom:			Tijl Coosemans <tijl@ulyssis.org>
#
# $FreeBSD$
#

PORTNAME=	tilp2
PORTVERSION=	1.10
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tilp

MAINTAINER=	tijl@ulyssis.org
COMMENT=	TI Linking Program

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS=	ticables2.1:${PORTSDIR}/comms/libticables2 \
		tifiles2.5:${PORTSDIR}/devel/libtifiles2 \
		ticalcs2.7:${PORTSDIR}/comms/libticalcs2 \
		ticonv.3:${PORTSDIR}/converters/libticonv

USE_AUTOTOOLS=	libtool:15
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 libglade2

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB=	NLS=""
.else
CONFIGURE_ARGS=	--disable-nls
PLIST_SUB=	NLS="@comment "
.endif

CONFIGURE_ARGS+=	--without-kde
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -UGTK_DISABLE_DEPRECATED" \
		LDFLAGS="-L${LOCALBASE}/lib -export-dynamic"

MAN1=	tilp.1

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|-D.*_DISABLE_DEPRECATED||g'
	@${REINPLACE_CMD} -e 's|#define .*_DISABLE_DEPRECATED||g' \
		${WRKSRC}/src/device.c ${WRKSRC}/src/toolbar.c

.include <bsd.port.mk>
