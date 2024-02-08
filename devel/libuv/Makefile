PORTNAME=	libuv
DISTVERSIONPREFIX=	v
DISTVERSION=	1.48.0
CATEGORIES=	devel
MASTER_SITES=	https://dist.libuv.org/dist/v${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSIONFULL}-dist

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Multi-platform support library with a focus on asynchronous I/O
WWW=		https://github.com/libuv/libuv

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe libtool pathfix pkgconfig

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
INSTALL_TARGET=	install-strip

# Will not run as root, reference:
# https://github.com/libuv/libuv/commit/af45b6ba2f2c506ae18dd24481e24db17b8269e7
TEST_TARGET=	check

CONFIGURE_ARGS=	--disable-maintainer-mode

pre-configure:
	${ECHO_CMD} "m4_define([UV_EXTRA_AUTOMAKE_FLAGS], [ serial-tests])" \
		> ${WRKSRC}/m4/libuv-extra-automake-flags.m4

.include <bsd.port.mk>
