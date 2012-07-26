# New ports collection makefile for:	tilp2
# Date created:		11 October 2006
# Whom:			Tijl Coosemans <tijl@ulyssis.org>
#
# $FreeBSD$
#

PORTNAME=	tilp2
PORTVERSION=	1.16
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	SF/tilp/tilp2-linux/${DISTNAME}

MAINTAINER=	tijl@coosemans.org
COMMENT=	TI Linking Program

LICENSE=	GPLv2

LIB_DEPENDS=	ticables2.5:${PORTSDIR}/comms/libticables2 \
		tifiles2.8:${PORTSDIR}/devel/libtifiles2 \
		ticalcs2.10:${PORTSDIR}/comms/libticalcs2 \
		ticonv.6:${PORTSDIR}/converters/libticonv

USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PKGCONFIG=	yes
USE_GNOME=	gtk20 libglade2

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB=	NLS=""
.else
CONFIGURE_ARGS=	--disable-nls
PLIST_SUB=	NLS="@comment "
.endif

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--without-kde

MAN1=	tilp.1

post-patch:
	@${REINPLACE_CMD} -e 's|-D.*_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
