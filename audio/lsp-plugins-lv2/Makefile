# $FreeBSD$

PORTNAME=	lsp-plugins
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	1.1.10
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of free LV2 plugins

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=	amd64 armv7 i386 powerpc64
ONLY_FOR_ARCHS_REASON=	assembly only for these architectures

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libsndfile.so:audio/libsndfile

USES=		compiler:c11 gmake gl gnome iconv:wchar_t pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	sadko4u
USE_GCC=	any # clang breaks: https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=232911
USE_GNOME=	cairo
USE_XORG=	x11
USE_GL=		gl

BINARY_ALIAS=	g++=${CXX}
MAKE_ARGS=	BUILD_MODULES='lv2'

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

.include <bsd.port.mk>
