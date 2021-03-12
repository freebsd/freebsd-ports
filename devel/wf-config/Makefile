# $FreeBSD$

PORTNAME=	wf-config
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Library for managing configuration files, written for wayfire

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>0:graphics/wayland-protocols \
		glm>0:math/glm
LIB_DEPENDS=	libevdev.so:devel/libevdev
RUN_DEPENDS=	glm>0:math/glm

USES=		compiler:c++17-lang gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
GH_ACCOUNT=	WayfireWM

.include <bsd.port.mk>
