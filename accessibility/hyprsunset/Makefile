PORTNAME=	hyprsunset
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.1
CATEGORIES=	accessibility wayland

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Blue light filter on Hyprland
WWW=		https://github.com/hyprwm/hyprsunset

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_13=	fails to build: /usr/local/include/date/date.h:6636:15: error: no member named 'read' in namespace 'date::detail'; did you mean '::read'?

BUILD_DEPENDS=	hyprwayland-scanner>=0.4.0:devel/hyprwayland-scanner \
		hyprland-protocols>=0.4.0:graphics/hyprland-protocols \
		wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libhyprlang.so:devel/hyprlang \
		libhyprutils.so:devel/hyprutils \
		libwayland-client.so:graphics/wayland

USES=		cmake compiler:c++11-lib localbase:ldflags pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	hyprwm

PLIST_FILES=	bin/${PORTNAME} \
		lib/systemd/user/${PORTNAME}.service

# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=282377
.if exists(/usr/lib/libc++.so)
LIB_DEPENDS+=	libdate-tz.so:devel/date
USES+=		localbase:ldflags
.endif

.include <bsd.port.mk>
