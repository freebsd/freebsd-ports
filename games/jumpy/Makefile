PORTNAME=	jumpy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.4
CATEGORIES=	games wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Tactical 2D shooter in fishy pixels style
WWW=		https://fishfolk.org/games/jumpy/

LICENSE=	CC-BY-NC-4.0 MIT
LICENSE_COMB=	multi
LICENSE_FILE_MIT=	${WRKSRC}/licenses/LICENSE-MIT

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libudev.so:devel/libudev-devd
RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins \
		${LOCALBASE}/lib/libvulkan.so:graphics/vulkan-loader

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	fishfolk
LTO_UNSAFE=	yes # bevy_dylib fails with -C panic=abort
PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

.if ${MACHINE_ARCH} == i386
# https://github.com/rust-lang/rust/issues/85598
CARGO_ENV+=	CARGO_PROFILE_RELEASE_LTO=false
.endif

post-patch:
# Search assets under PREFIX instead of current directory
	@${REINPLACE_CMD} 's,assets",${DATADIR}/&,' \
		${WRKSRC}/src/main.rs \
		${WRKSRC_crate_bevy_asset}/src/lib.rs

post-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "assets" ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
