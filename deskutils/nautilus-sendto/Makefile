# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$
#    $MCom: ports/trunk/deskutils/nautilus-sendto/Makefile 19571 2014-04-25 18:12:46Z kwm $

PORTNAME=	nautilus-sendto
PORTVERSION=	3.8.0
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Convenience application to send a file via email

USE_GNOME=	intlhack introspection:build
USES=		gettext gmake pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -Wno-error=format-nonliteral
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
