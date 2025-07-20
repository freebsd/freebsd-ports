PORTNAME=	hyprsunset
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
PORTREVISION=	4
CATEGORIES=	accessibility wayland

MAINTAINER=	tagattie@FreeBSD.org
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
GH_TUPLE=	hyprwm:hyprland-protocols:v0.6.2:hyprland_protocols/subprojects/hyprland-protocols
PLIST_FILES=	bin/${PORTNAME} \
		lib/systemd/user/${PORTNAME}.service

.include <bsd.port.mk>
