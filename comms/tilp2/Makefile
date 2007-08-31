# New ports collection makefile for:	tilp2
# Date created:		11 October 2006
# Whom:			Tijl Coosemans <tijl@ulyssis.org>
#
# $FreeBSD$
#

PORTNAME=	tilp2
PORTVERSION=	1.02
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tilp

MAINTAINER=	tijl@ulyssis.org
COMMENT=	TI Linking Program

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS=	ticables2.1:${PORTSDIR}/comms/libticables2 \
		tifiles2.3:${PORTSDIR}/devel/libtifiles2 \
		ticalcs2.5:${PORTSDIR}/comms/libticalcs2 \
		ticonv.2:${PORTSDIR}/converters/libticonv

WRKSRC=		${WRKDIR}/${PORTNAME}-1.01

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

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -export-dynamic"

MAN1=	tilp-2.1

.include <bsd.port.mk>
