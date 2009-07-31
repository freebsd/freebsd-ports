# New ports collection makefile for:	libglade
# Date created:				18 August 1999
# Whom:					Ade Lovett <ade@lovett.com>
#
# $FreeBSD$
#

PORTNAME=	libglade
PORTVERSION=	0.17
PORTREVISION=	10
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME glade library

USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix gnomehier gnomedb
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-bonobo --enable-gnomedb
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
