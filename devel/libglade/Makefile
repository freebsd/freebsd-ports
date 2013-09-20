# Created by: Ade Lovett <ade@lovett.com>
# $FreeBSD$

PORTNAME=	libglade
PORTVERSION=	0.17
PORTREVISION=	13
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME glade library

USES=		perl5
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix gnomehier gnomedb
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-bonobo --enable-gnomedb
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

NO_STAGE=	yes
.include <bsd.port.mk>
