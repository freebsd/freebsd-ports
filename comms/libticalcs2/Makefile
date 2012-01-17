# New ports collection makefile for:	libticalcs2
# Date created:		11 October 2006
# Whom:			Tijl Coosemans <tijl@ulyssis.org>
#
# $FreeBSD$
#

PORTNAME=	libticalcs2
PORTVERSION=	1.1.7
CATEGORIES=	comms
MASTER_SITES=	SF/tilp/tilp2-linux/tilp2-1.16

MAINTAINER=	tijl@coosemans.org
COMMENT=	TI calculator library

LICENSE=	GPLv2

LIB_DEPENDS=	ticables2.5:${PORTSDIR}/comms/libticables2 \
		ticonv.6:${PORTSDIR}/converters/libticonv \
		tifiles2.8:${PORTSDIR}/devel/libtifiles2

USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehack pkgconfig
USE_LDCONFIG=	yes

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB=	NLS=""
.else
CONFIGURE_ARGS=	--disable-nls
PLIST_SUB=	NLS="@comment "
.endif

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
