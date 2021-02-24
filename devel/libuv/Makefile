# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	libuv
DISTVERSIONPREFIX=	v
DISTVERSION=	1.41.0
CATEGORIES=	devel
MASTER_SITES=	https://dist.libuv.org/dist/v${DISTVERSION}/

MAINTAINER=	bhughes@FreeBSD.org
COMMENT=	Multi-platform support library with a focus on asynchronous I/O

LICENSE=	NODE
LICENSE_NAME=	NODE
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		autoreconf libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

# Will not run as root, reference:
# https://github.com/libuv/libuv/commit/af45b6ba2f2c506ae18dd24481e24db17b8269e7
TEST_TARGET=	check

pre-configure:
	${ECHO_CMD} "m4_define([UV_EXTRA_AUTOMAKE_FLAGS], [ serial-tests])" \
		> ${WRKSRC}/m4/libuv-extra-automake-flags.m4

.include <bsd.port.mk>
