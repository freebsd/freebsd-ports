# Created by: Herbert J. Skuhra <h.skuhra@gmail.com>
# $FreeBSD$

PORTNAME=	mixmos
PORTVERSION=	0.2.0
PORTREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_TUCOWS}

MAINTAINER=	h.skuhra@gmail.com
COMMENT=	A GTK2 audio mixer

USES=		pkgconfig
NO_STAGE=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		mixmos.1

.include <bsd.port.mk>
