# $FreeBSD$

PORTNAME=	wayland-protocols
PORTVERSION=	1.7
CATEGORIES=	graphics wayland
MASTER_SITES=	https://wayland.freedesktop.org/releases/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Wayland protocols

BUILD_DEPENDS=	wayland-scanner:graphics/wayland

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz pathfix
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${datadir}/pkgconfig|$${prefix}/libdata/pkgconfig|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
