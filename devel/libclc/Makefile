# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libclc
DISTVERSION=	0.3.0.20170117
CATEGORIES=	devel

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Required library functions for OpenCL C programming language

LICENSE=	BSD3CLAUSE MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT
LICENSE_COMB=	dual

BUILD_DEPENDS=	clang${LLVMVER}:devel/llvm${LLVMVER} \
		libedit>=0:devel/libedit

USE_GITHUB=	yes
GH_ACCOUNT=	llvm-mirror
GH_TAGNAME=	2ec7d80

# ninja based build is broken since commit 598792bc (16 sep 2016)
USES=		gmake python:2.7,build gmake
USE_LDCONFIG=	yes
MAKE_ENV=	MAKE=${GMAKE} DESTDIR=${STAGEDIR}

LLVMVER=	40

ALL_TARGET=

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/python|${PYTHON_CMD}|g' \
		-e 's|"python |"${PYTHON_VERSION} |g' \
		${WRKSRC}/build/ninja_syntax.py \
		${WRKSRC}/configure.py

do-configure:
	@cd ${WRKSRC} && ${PYTHON_CMD} configure.py ${CONFIGURE_ARGS} -g make \
		--with-llvm-config=${LOCALBASE}/bin/llvm-config${LLVMVER} \
		--pkgconfigdir=${PREFIX}/libdata/pkgconfig \
		--prefix=${PREFIX}

.include <bsd.port.mk>
