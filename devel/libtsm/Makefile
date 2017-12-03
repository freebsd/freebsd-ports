# $FreeBSD$

PORTNAME=	libtsm
DISTVERSION=	3
CATEGORIES=	devel
MASTER_SITES=	http://freedesktop.org/software/kmscon/releases/

MAINTAINER=	angus@agibson.me
COMMENT=	Terminal-emulator state machine

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake libtool tar:xz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-debug --disable-static
CONFIGURE_ENV=	PKG_CONFIG=/dev/null # disable tests
INSTALL_TARGET=	install-strip

PLIST_FILES=	include/libtsm.h \
		lib/libtsm.so \
		lib/libtsm.so.3 \
		lib/libtsm.so.3.0.0 \
		libdata/pkgconfig/libtsm.pc

.include <bsd.port.mk>
