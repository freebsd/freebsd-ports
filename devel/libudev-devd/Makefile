PORTNAME=	libudev-devd
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.1
CATEGORIES=	devel

MAINTAINER=	x11@FreeBSD.org
COMMENT=	libudev-compatible interface for devd
WWW=		https://github.com/wulf7/libudev-devd

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto

USE_GITHUB=	yes
GH_ACCOUNT=	wulf7

USES=		compiler:c11 localbase meson
USE_LDCONFIG=	yes

CFLAGS+=	-Wno-error

PLIST_FILES=	include/libudev.h \
		lib/libudev.so \
		lib/libudev.so.0 \
		lib/libudev.so.0.0.0 \
		libdata/pkgconfig/libudev.pc

OPTIONS_DEFINE=	GPL

GPL_DESC=	Enable GPL-licensed code
GPL_MESON_TRUE=	enable-gpl
GPL_VARS=	LICENSE+=LGPL21+ LICENSE_COMB=multi

.include <bsd.port.mk>
