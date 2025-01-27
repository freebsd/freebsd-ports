PORTNAME=	libvex
DISTVERSION=	g20230201
PORTREVISION=	2
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

CFLAGS+=	-DVGA_${ARCH:S/i386/x86/:S/aarch64/arm/:S/powerpc64le/ppc64le/:S/powerpc64/ppc64/:S/powerpc/ppc32/:S/mips/mips64/}

MAKE_ARGS=	EXTRA_CFLAGS="${CFLAGS}"

PORTSCOUT=	ignore:1 # LibVEX is a part of Valgrind and isn't individually versioned

do-install:
	cd ${WRKSRC}/pub && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/libvex
	${INSTALL_DATA} ${WRKSRC}/libvex.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
