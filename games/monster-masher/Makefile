# Created by: Koop Mast <einekoai@chello.nl>
# $FreeBSD$

PORTNAME=	monster
PORTVERSION=	1.8.1
PORTREVISION=	4
CATEGORIES=	games gnome
MASTER_SITES=	http://people.iola.dk/olau/monster-masher/source/
PKGNAMESUFFIX=	-masher
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Gnomemm puzzle game where you have to clean the caves of monsters

LIB_DEPENDS=	libgnomecanvasmm-2.6.so:graphics/libgnomecanvasmm26 \
		libgconfmm-2.6.so:devel/gconfmm26 \
		libglademm-2.4.so:devel/libglademm24

USES=		pathfix gettext gmake pkgconfig tar:bzip2
USE_GNOME=	gnomeprefix intlhack libgnome esound
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lesd

GCONF_SCHEMAS=	monster-masher.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/src/pixbuf-drawing.hpp

.include <bsd.port.mk>
