PORTNAME=	libvex
DISTVERSION=	g20230201
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for dynamic binary instrumentation and translation
WWW=		https://github.com/pmem/valgrind

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.GPL

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	pmem
GH_PROJECT=	valgrind
GH_TAGNAME=	c0abd81

WRKSRC_SUBDIR=	VEX

MAKEFILE=	Makefile-gcc

MAKE_ARGS=	EXTRA_CFLAGS="${CFLAGS}"

do-install:
	cd ${WRKSRC}/pub && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/libvex
	${INSTALL_DATA} ${WRKSRC}/libvex.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
