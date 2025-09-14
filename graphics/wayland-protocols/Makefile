PORTNAME=	wayland-protocols
PORTVERSION=	1.45
CATEGORIES=	graphics
MASTER_SITES=	https://gitlab.freedesktop.org/wayland/${PORTNAME}/-/releases/${DISTVERSION}/downloads/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Wayland protocols
WWW=		https://wayland.freedesktop.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	wayland-scanner:graphics/wayland

USES=		meson pkgconfig tar:xz
MESON_ARGS=	-Dtests=false
NO_ARCH=	yes

.include <bsd.port.mk>
