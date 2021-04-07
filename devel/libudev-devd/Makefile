PORTNAME=	libudev-devd
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	x11@FreeBSD.org
COMMENT=	libudev-compatible interface for devd

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto

USE_GITHUB=	yes
GH_ACCOUNT=	FreeBSDDesktop

USES=		compiler:c11 localbase meson
USE_LDCONFIG=	yes

CFLAGS+=	-Wno-error

PLIST_FILES=	include/libudev.h \
		lib/libudev.so \
		lib/libudev.so.0 \
		lib/libudev.so.0.0.0 \
		libdata/pkgconfig/libudev.pc

.include <bsd.port.mk>
