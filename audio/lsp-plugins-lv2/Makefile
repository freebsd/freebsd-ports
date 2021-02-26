# $FreeBSD$

PORTNAME=	lsp-plugins
DISTVERSION=	1.1.29
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of free LV2 plugins

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=	amd64 armv7 i386 powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	assembly only for these architectures
BROKEN_i386=	error: inline assembly requires more registers than available

BUILD_DEPENDS=	llvm${LLVM_VERSION}>0:devel/llvm${LLVM_VERSION} \
		lv2>0:audio/lv2
LIB_DEPENDS=	libsndfile.so:audio/libsndfile

USES=		gmake gl gnome iconv:wchar_t pkgconfig xorg # compiler:c11
USE_GITHUB=	yes
GH_ACCOUNT=	sadko4u
USE_GNOME=	cairo
USE_XORG=	x11
USE_GL=		gl

BINARY_ALIAS=	g++=${CXX} c++=${CXX}
MAKE_ARGS=	BUILD_MODULES='lv2' ETC_PATH=${PREFIX}/etc VERSION=${DISTVERSION}

# clang-8, 9, 10 crash: fatal error: error in backend: Cannot select: 0x805afb270: v4f32 = fp_extend 0x805afbc98
LLVM_VERSION=	11
CPP=		clang-cpp${LLVM_VERSION}
CC=		clang${LLVM_VERSION}
CXX=		clang++${LLVM_VERSION}

OPTIONS_DEFINE=		JACK
OPTIONS_DEFAULT=	JACK
OPTIONS_SUB=		yes

JACK_MAKE_ARGS=		BUILD_MODULES+='jack'
JACK_LIB_DEPENDS=	libjack.so:audio/jack

post-patch:
# FreeBSD does not have exp10(3), use pow(3) instead
	@${GREP} -lR "exp10(" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|exp10(|pow(10.,|'
	@${GREP} -lR "<alloca\.h>" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|<alloca\.h>|<stdlib.h>|'

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/lsp-plugins.lv2/lsp-*.so

post-install-JACK-on:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lsp-* ${STAGEDIR}${PREFIX}/lib/lsp-plugins/lsp-*.so

.include <bsd.port.mk>
