# New ports collection makefile for:	libticonv
# Date created:		5 October 2006
# Whom:			Tijl Coosemans <tijl@ulyssis.org>
#
# $FreeBSD$
#

PORTNAME=	libticonv
PORTVERSION=	1.1.2
CATEGORIES=	converters
MASTER_SITES=	SF/tilp/tilp2-linux/tilp2-1.15

MAINTAINER=	tijl@coosemans.org
COMMENT=	TI calculator character set library

USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehack pkgconfig
USE_LDCONFIG=	yes
USE_ICONV=	yes

CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
