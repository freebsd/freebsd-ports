PORTNAME=	punchy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
PORTREVISION=	27
CATEGORIES=	games wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	2.5D side-scroller beatemup, made in Bevy
WWW=		https://fishfolk.org/games/punchy/

LICENSE=	CC-BY-NC-4.0 MIT
LICENSE_COMB=	multi
LICENSE_DISTFILES_CC-BY-NC-4.0=	${DISTNAME}${EXTRACT_SUFX}

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

.if ${MACHINE_ARCH} == i386 || "${MACHINE_ARCH:Marmv?}" != ""
# https://github.com/rust-lang/rust/issues/85598
LTO_UNSAFE=	yes
CARGO_ENV+=	CARGO_PROFILE_RELEASE_LTO=false
.endif

post-patch:
# Search assets under PREFIX instead of current directory
	@${REINPLACE_CMD} 's,assets",../${DATADIR_REL}/&,' \
		${WRKSRC_crate_bevy_asset}/src/lib.rs

post-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "assets" ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
