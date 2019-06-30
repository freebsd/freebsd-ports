# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libclc
DISTVERSION=	0.3.0.20180518
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Required library functions for OpenCL C programming language

LICENSE=	BSD3CLAUSE MIT
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

BUILD_DEPENDS=	llvm${LLVM_DEFAULT}>=4.0:devel/llvm${LLVM_DEFAULT} \
		libedit>=0:devel/libedit

USE_GITHUB=	yes
GH_ACCOUNT=	llvm-mirror
GH_TAGNAME=	a2118d5

# ninja based build is broken since commit 598792bc (16 sep 2016)
USES=		gmake python:2.7,build gmake
USE_LDCONFIG=	yes
MAKE_ENV=	MAKE=${GMAKE} DESTDIR=${STAGEDIR}
ALL_TARGET=

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/python|${PYTHON_CMD}|g' \
		-e 's|"python |"${PYTHON_VERSION} |g' \
		${WRKSRC}/build/ninja_syntax.py \
		${WRKSRC}/configure.py

do-configure:
	@cd ${WRKSRC} && ${PYTHON_CMD} configure.py ${CONFIGURE_ARGS} -g make \
		--with-llvm-config=${LOCALBASE}/bin/llvm-config${LLVM_DEFAULT} \
		--pkgconfigdir=${PREFIX}/libdata/pkgconfig \
		--prefix=${PREFIX}

.include <bsd.port.mk>
