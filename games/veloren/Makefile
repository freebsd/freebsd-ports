PORTNAME=	veloren
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14.0
PORTREVISION=	1
CATEGORIES=	games wayland
.if !make(makesum)
MASTER_SITES=	LOCAL/jbeich
.endif

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Multiplayer voxel RPG written in Rust
WWW=		https://veloren.net/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
# https://gitlab.com/veloren/veloren/-/issues/1006
ONLY_FOR_ARCHS_REASON=	unsupported platform by https://github.com/wasmerio/wasmer

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libudev.so:devel/libudev-devd \
		libshaderc_shared.so:graphics/shaderc
RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins \
		${LOCALBASE}/lib/libvulkan.so:graphics/vulkan-loader

USES=		cargo xorg
USE_XORG=	xcb
USE_GITLAB=	yes
GL_COMMIT=	185dccc1cc1498d810de907b26699c85bfd1bac0
CARGO_ENV=	VELOREN_USERDATA_STRATEGY=system SHADERC_LIB_DIR="${LOCALBASE}/lib"
PLIST_FILES=	bin/${PORTNAME}-server-cli \
		bin/${PORTNAME}-voxygen \
		share/applications/net.veloren.veloren.desktop \
		share/pixmaps/net.veloren.veloren.png
PORTDATA=	*

# Fixes error "Instruction does not dominate all uses!"
LTO_UNSAFE=	yes

# https://gitlab.com/veloren/veloren/issues/264
CARGO_ENV+=		RUSTC_BOOTSTRAP=1
# XXX https://github.com/rust-lang/cargo/issues/4101
CARGO_INSTALL_PATH=	server-cli voxygen

post-patch:
# .git/ directory is missing, so don't abort if git binary is also missing
	@${REINPLACE_CMD} -e 's/"git"/"${TRUE}"/' \
		${WRKSRC}/common/build.rs
# Extract (snapshot) version from the port instead of empty file
	@${REINPLACE_CMD} -e '/GIT_HASH/s/=.*/= "${GL_COMMIT:C/(.{8}).*/\1/}";/' \
		-e "/GIT_DATE.*static/s/=.*/= \"$$(date -r $$(${AWK} '/TIMESTAMP/ { print $$3 }' \
			${DISTINFO_FILE}) +'%Y-%m-%d-%H:%M')\";/" \
		${WRKSRC}/common/src/util/mod.rs
# Respect PREFIX != /usr/local for system assets
	@${REINPLACE_CMD} -e 's,/usr/share,${DATADIR:H},' \
		${WRKSRC}/common/assets/src/lib.rs

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	(cd ${WRKSRC} && ${COPYTREE_SHARE} assets ${STAGEDIR}${DATADIR})
	${RLN} ${STAGEDIR}${DATADIR}/assets/voxygen/*.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${RLN} ${STAGEDIR}${DATADIR}/assets/voxygen/*.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
