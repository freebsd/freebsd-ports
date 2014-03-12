# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	libuv
PORTVERSION=	0.11.22
CATEGORIES=	devel
MASTER_SITES=	http://libuv.org/dist/v${PORTVERSION}/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

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
USES=		pkgconfig
USE_LDCONFIG=	yes

run-autotools:
	cd ${CONFIGURE_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./autogen.sh

.if defined(MAINTAINER_MODE)
regression-test:
	(cd ${WRKSRC} && ./gyp_uv.py -f make &&	\
	${SETENV} ${MAKE_ENV} ${GMAKE} -C out && \
	./out/Debug/run-tests)
.endif

.include <bsd.port.mk>
