PORTNAME=	lsp-plugins
DISTVERSION=	1.2.5
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://github.com/sadko4u/lsp-plugins/releases/download/${DISTVERSION}/
PKGNAMESUFFIX=	-lv2
DISTFILES=	${PORTNAME}-src-${DISTVERSION}.tar.gz

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of free LV2 plugins
WWW=		https://lsp-plug.in/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	aarch64 amd64 armv7 i386 powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	assembly only for these architectures

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libsndfile.so:audio/libsndfile

USES=		gmake gl gnome iconv:wchar_t pkgconfig xorg # compiler:c11
USE_GNOME=	cairo
USE_XORG=	x11 xrandr
USE_GL=		gl

BINARY_ALIAS=	g++=${CXX} c++=${CXX}
MAKE_ARGS=	BUILD_MODULES='lv2' ETC_PATH=${PREFIX}/etc VERSION=${DISTVERSION}

WRKSRC=		${WRKDIR}/${PORTNAME}

MAKE_ARGS=	FEATURES+='lv2'

OPTIONS_DEFINE=		JACK VST2
OPTIONS_DEFAULT=	JACK VST2
OPTIONS_SUB=		yes

JACK_DESC=		Build Jack plugins
JACK_MAKE_ARGS=		FEATURES+='jack'
JACK_LIB_DEPENDS=	libjack.so:audio/jack

VST2_DESC=		Build VST2 plugins
VST2_MAKE_ARGS=		FEATURES+='vst2'

post-patch:
# FreeBSD does not have exp10(3), use pow(3) instead
	@${GREP} -lR "exp10(" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|exp10(|pow(10.,|'
	@${GREP} -lR "<alloca\.h>" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|<alloca\.h>|<stdlib.h>|'

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} config ${MAKE_ARGS}

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/lib/lv2/lsp-plugins.lv2/lsp-*.so \
		${STAGEDIR}${PREFIX}/lib/liblsp-r3d-glx-lib-*.so

post-install-JACK-on:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/lsp-* \
		${STAGEDIR}${PREFIX}/lib/lsp-plugins/liblsp-plugins-jack-${PORTVERSION}.so

post-install-VST2-on:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/vst/lsp-plugins/*.so

.include <bsd.port.mk>
