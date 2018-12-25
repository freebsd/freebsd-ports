# $FreeBSD$

PORTNAME=	wayland-protocols
PORTVERSION=	1.16
CATEGORIES=	graphics wayland
MASTER_SITES=	https://wayland.freedesktop.org/releases/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Wayland protocols

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	wayland-scanner:graphics/wayland

USES=		tar:xz
NO_ARCH=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-noarch-pkgconfigdir='$${prefix}/libdata/pkgconfig'

.include <bsd.port.mk>
