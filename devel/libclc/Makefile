# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libclc
DISTVERSION=	0.1.0.20150710
CATEGORIES=	devel

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Required library functions for OpenCL C programming language

BUILD_DEPENDS=	clang${LLVMVER}:${PORTSDIR}/lang/clang${LLVMVER} \
		libedit>=0:${PORTSDIR}/devel/libedit

USE_GITHUB=	yes
GH_ACCOUNT=	llvm-mirror
GH_TAGNAME=	eed524f2a9

GNU_CONFIGURE=	yes
USES=		gmake python:2,build ninja
USE_LDCONFIG=	yes
MAKE_ENV=	MAKE=${GMAKE} DESTDIR=${STAGEDIR}

LLVMVER=	36

ALL_TARGET=

BROKEN_FreeBSD_9=	missing <system_error> header

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/python|${PYTHON_CMD}|g' \
		-e 's|"python |"${PYTHON_VERSION} |g' \
		${WRKSRC}/build/ninja_syntax.py \
		${WRKSRC}/configure.py

do-configure:
	@cd ${WRKSRC} && ${PYTHON_CMD} configure.py ${CONFIGURE_ARGS} -g ninja \
		--with-llvm-config=${LOCALBASE}/bin/llvm-config${LLVMVER} \
		--pkgconfigdir=${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
