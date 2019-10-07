# $FreeBSD$

PORTNAME=	wf-config
DISTVERSION=	0.3
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Library for managing configuration files, written for wayfire

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libevdev.so:devel/libevdev \
		libwlroots.so:x11-toolkits/wlroots

USES=		compiler:c++11-lib meson pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	WayfireWM

.include <bsd.port.mk>
