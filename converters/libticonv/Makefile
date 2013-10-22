# $FreeBSD$

PORTNAME=	libticonv
PORTVERSION=	1.1.4
PORTREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	SF/tilp/tilp2-linux/tilp2-1.17

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	TI calculator character set library

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USES=		gmake pathfix pkgconfig

post-patch:
	@${REINPLACE_CMD} -e 's/Requires/&.private/' ${WRKSRC}/ticonv.pc.in

.include <bsd.port.mk>
