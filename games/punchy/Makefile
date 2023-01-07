PORTNAME=	punchy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	games wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	2.5D side-scroller beatemup, made in Bevy
WWW=		https://fishfight.org/

LICENSE=	CC-BY-NC-4.0 MIT
LICENSE_COMB=	multi

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libudev.so:devel/libudev-devd
RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins \
		${LOCALBASE}/lib/libvulkan.so:graphics/vulkan-loader

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	fishfolk
PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

# Bundled v8
BUILD_DEPENDS+=	gn:devel/gn
USES+=		ninja:build python:build
BINARY_ALIAS+=	python=${PYTHON_CMD}
CARGO_ENV+=	V8_FROM_SOURCE=1 CLANG_BASE_PATH="/usr" GN_ARGS='${GN_ARGS}'
GN_ARGS+=	use_custom_libcxx=false

post-patch:
# Search assets under PREFIX instead of current directory
	@${REINPLACE_CMD} 's,assets",../${DATADIR_REL}/&,' \
		${WRKSRC}/cargo-crates/bevy_asset-*/src/lib.rs
# XXX Drop after FreeBSD 12.3 EOL around 2023-03-01
# https://cgit.freebsd.org/src/commit/?id=98a049f22ef3
.if !exists(/usr/bin/llvm-readelf)
	@${REINPLACE_CMD} '/readelf/s/llvm-//' \
		${WRKSRC}/cargo-crates/v8-*/build/toolchain/gcc_toolchain.gni
.endif

post-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "assets" ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
