PORTNAME=	hyprsunset
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	accessibility wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Blue light filter on Hyprland
WWW=		https://github.com/hyprwm/hyprsunset

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	hyprwayland-scanner>=0.4.0:devel/hyprwayland-scanner \
		wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libhyprutils.so:devel/hyprutils \
		libwayland-client.so:graphics/wayland

USES=		cmake compiler:c++11-lib localbase:ldflags pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	hyprwm
GH_TUPLE=	hyprwm:hyprland-protocols:v0.4.0:hyprland_protocols/subprojects/hyprland-protocols
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
