PORTNAME=	wrapland
DISTVERSIONPREFIX=	v
DISTVERSION=	0.601.0
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Qt/C++ library wrapping libwayland
WWW=		https://github.com/winft/wrapland

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		microsoft-gsl>0:devel/microsoft-gsl \
		wayland-protocols>=1.27:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland
RUN_DEPENDS=	microsoft-gsl>0:devel/microsoft-gsl

USES=		cmake:testing gl kde:6 pkgconfig qt:6
USE_GITHUB=	yes
USE_GL=		egl
USE_KDE=	ecm:build
USE_LDCONFIG=	yes
USE_QT=		base
GH_ACCOUNT=	winft
LDFLAGS+=	-Wl,--as-needed # GL, xkbcommon
PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.mk>
