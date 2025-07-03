PORTNAME=	jumpy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.2
PORTREVISION=	7
CATEGORIES=	games wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Tactical 2D shooter in fishy pixels style
WWW=		https://fishfolk.org/games/jumpy/

LICENSE=	CC-BY-NC-4.0 MIT
LICENSE_COMB=	multi
LICENSE_FILE_MIT=	${WRKSRC}/licenses/LICENSE-MIT
LICENSE_DISTFILES_CC-BY-NC-4.0=	${DISTNAME}${EXTRACT_SUFX}

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libudev.so:devel/libudev-devd
RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins \
		${LOCALBASE}/lib/libvulkan.so:graphics/vulkan-loader

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	fishfolk
WITHOUT_LTO=	yes # XXX bug 277333 # bevy_dylib
PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

.if ${MACHINE_ARCH} == i386 || "${MACHINE_ARCH:Marmv?}" != ""
# https://github.com/rust-lang/rust/issues/85598
CARGO_ENV+=	CARGO_PROFILE_RELEASE_LTO=false
# https://github.com/briansmith/ring/issues/1793#issuecomment-1793243725
RUSTFLAGS+=	-C target-feature=+sse2
.endif

post-patch:
# Search assets under PREFIX instead of current directory
	@${REINPLACE_CMD} 's,assets",${DATADIR}/&,' \
		${WRKSRC}/src/main.rs \
		${WRKSRC_crate_bevy_asset}/src/lib.rs

post-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "assets" ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
