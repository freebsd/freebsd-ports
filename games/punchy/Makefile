PORTNAME=	punchy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.4
PORTREVISION=	4
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
GH_ACCOUNT=	fishfolks
PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

post-patch:
# Search assets under PREFIX instead of current directory
	@${REINPLACE_CMD} 's,assets",../${DATADIR_REL}/&,' \
		${WRKSRC}/cargo-crates/bevy_asset-*/src/lib.rs

post-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "assets" ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
