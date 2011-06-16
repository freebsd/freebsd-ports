# New ports collection makefile for:	libtifiles2
# Date created:		11 October 2006
# Whom:			Tijl Coosemans <tijl@ulyssis.org>
#
# $FreeBSD$
#

PORTNAME=	libtifiles2
PORTVERSION=	1.1.4
CATEGORIES=	devel
MASTER_SITES=	SF/tilp/tilp2-linux/tilp2-1.15

MAINTAINER=	tijl@coosemans.org
COMMENT=	TI calculator file types library

LIB_DEPENDS=	ticonv.5:${PORTSDIR}/converters/libticonv

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
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"

.include <bsd.port.mk>
