PORTNAME=	hyprwayland-scanner
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Hyprland implementation of wayland-scanner
WWW=		https://github.com/hyprwm/hyprwayland-scanner

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpugixml.so:textproc/pugixml

USES=		cmake compiler:c++11-lib pathfix pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	hyprwm
PLIST_FILES=	bin/${PORTNAME} \
		libdata/pkgconfig/${PORTNAME}.pc

.include <bsd.port.mk>
