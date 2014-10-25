# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	libuv
DISTVERSION=	1.0.0-rc2
CATEGORIES=	devel
MASTER_SITES=	http://libuv.org/dist/v${DISTVERSION}/
DISTNAME=	${PORTNAME}-v${DISTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Multi-platform support library with a focus on asynchronous I/O

LICENSE=	NODE
LICENSE_NAME=	NODE
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

TEST_DEPENDS=	gyp:${PORTSDIR}/devel/py-gyp-devel	\
		gmake:${PORTSDIR}/devel/gmake

USE_AUTOTOOLS=	aclocal automake autoconf libtoolize
ACLOCAL_ARGS=	-I m4
AUTOMAKE_ARGS=	-a -c -f
USES=		libtool pathfix pkgconfig
PATHFIX_MAKEFILEIN=	Makefile.am
USE_LDCONFIG=	yes

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
