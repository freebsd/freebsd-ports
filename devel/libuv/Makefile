# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	libuv
PORTVERSION=	1.20.3
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
#MASTER_SITES=	http://dist.libuv.org/dist/v${PORTVERSION}/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Multi-platform support library with a focus on asynchronous I/O

LICENSE=	NODE
LICENSE_NAME=	NODE
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

TEST_DEPENDS=	gyp:devel/py-gyp \
		gmake:devel/gmake

USE_GITHUB=	yes

USES=		autoreconf libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

pre-configure:
	${ECHO_CMD} "m4_define([UV_EXTRA_AUTOMAKE_FLAGS], [ serial-tests])" \
		> ${WRKSRC}/m4/libuv-extra-automake-flags.m4

do-test:
	(cd ${WRKSRC} && ./gyp_uv.py -f make &&	\
	${SETENV} ${MAKE_ENV} ${GMAKE} -C out && \
	./out/Debug/run-tests)

.include <bsd.port.mk>
