# $FreeBSD$

PORTNAME=	unicorn
PORTVERSION=	0.9
CATEGORIES=	emulators

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Unicorn CPU emulator framework

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	cmocka>0:sysutils/cmocka

USE_GITHUB=	yes
GH_ACCOUNT=	unicorn-engine

USES=		gmake pkgconfig python:2.7,build
USE_GNOME=	glib20
USE_LDCONFIG=	yes
MAKE_ENV=	INSTALL_LIB="${INSTALL_LIB}" \
		UNICORN_QEMU_FLAGS=--python=${PYTHON_CMD} \
		V=1
TEST_TARGET=	test
TEST_WRKSRC=	${WRKSRC}/tests/unit

.include <bsd.port.mk>
