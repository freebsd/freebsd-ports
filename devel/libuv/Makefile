# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	libuv
PORTVERSION=	1.9.0
CATEGORIES=	devel
MASTER_SITES=	http://dist.libuv.org/dist/v${PORTVERSION}/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Multi-platform support library with a focus on asynchronous I/O

LICENSE=	NODE
LICENSE_NAME=	NODE
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

TEST_DEPENDS=	gyp:devel/py-gyp-devel	\
		gmake:devel/gmake

USES=		autoreconf libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
PATHFIX_MAKEFILEIN=	Makefile.am
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

pre-configure:
	${ECHO_CMD} "m4_define([UV_EXTRA_AUTOMAKE_FLAGS], [ serial-tests])" \
		> ${WRKSRC}/m4/libuv-extra-automake-flags.m4

.if defined(MAINTAINER_MODE)
regression-test:
	(cd ${WRKSRC} && ./gyp_uv.py -f make &&	\
	${SETENV} ${MAKE_ENV} ${GMAKE} -C out && \
	./out/Debug/run-tests)
.endif

.include <bsd.port.mk>
