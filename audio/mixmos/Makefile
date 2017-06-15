# Created by: Herbert J. Skuhra <h.skuhra@gmail.com>
# $FreeBSD$

PORTNAME=	mixmos
PORTVERSION=	0.2.0
PORTREVISION=	10
CATEGORIES=	audio
MASTER_SITES=	TUCOWS

MAINTAINER=	h.skuhra@gmail.com
COMMENT=	GTK2 audio mixer

USES=		pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
