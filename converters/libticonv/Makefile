# New ports collection makefile for:	libticonv
# Date created:		5 October 2006
# Whom:			Tijl Coosemans <tijl@ulyssis.org>
#
# $FreeBSD$
#

PORTNAME=	libticonv
PORTVERSION=	1.0.1
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtktiemu
DISTNAME=	${PORTNAME}-20070207

MAINTAINER=	tijl@ulyssis.org
COMMENT=	TI calculator character set library

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_AUTOTOOLS=	libtool:15
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehack pkgconfig
USE_LDCONFIG=	yes
USE_ICONV=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"\
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
