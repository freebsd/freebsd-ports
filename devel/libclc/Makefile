# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libclc
DISTVERSION=	0.2.0.20160915
CATEGORIES=	devel

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Required library functions for OpenCL C programming language

LICENSE=	MIT

BUILD_DEPENDS=	clang${LLVMVER}:devel/llvm${LLVMVER} \
		libedit>=0:devel/libedit

USE_GITHUB=	yes
GH_ACCOUNT=	llvm-mirror
GH_TAGNAME=	b091e26

USES=		gmake python:2,build ninja
USE_LDCONFIG=	yes
MAKE_ENV=	MAKE=${GMAKE} DESTDIR=${STAGEDIR}

LLVMVER=	39

ALL_TARGET=

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/python|${PYTHON_CMD}|g' \
		-e 's|"python |"${PYTHON_VERSION} |g' \
		${WRKSRC}/build/ninja_syntax.py \
		${WRKSRC}/configure.py

do-configure:
	@cd ${WRKSRC} && ${PYTHON_CMD} configure.py ${CONFIGURE_ARGS} -g ninja \
		--with-llvm-config=${LOCALBASE}/bin/llvm-config${LLVMVER} \
		--pkgconfigdir=${PREFIX}/libdata/pkgconfig \
		--prefix=${PREFIX}

.include <bsd.port.mk>
