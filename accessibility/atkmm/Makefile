# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/accessibility/atkmm/Makefile 19571 2014-04-25 18:12:46Z kwm $

PORTNAME=	atkmm
PORTVERSION=	2.22.7
CATEGORIES=	accessibility gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ wrapper for ATK API library

USES=		gmake pathfix pkgconfig tar:xz
USE_GNOME=	atk glibmm
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-documentation

.include <bsd.port.mk>
