# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/accessibility/atkmm/Makefile 19865 2014-09-14 12:34:28Z kwm $

PORTNAME=	atkmm
PORTVERSION=	2.22.7
CATEGORIES=	accessibility gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ wrapper for ATK API library

USES=		gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	atk glibmm
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--disable-documentation

.include <bsd.port.mk>
