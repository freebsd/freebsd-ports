PORTNAME=	veloren
PORTVERSION=	s20260115
CATEGORIES=	games wayland
PKGNAMESUFFIX=	-weekly

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Multiplayer voxel RPG written in Rust (weekly snapshot)
WWW=		https://veloren.net/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=	https://github.com/bytecodealliance/wasmtime/issues/5499
ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	unsupported platform by https://github.com/wasmerio/wasmer

LIB_DEPENDS=	libzstd.so:archivers/zstd \
		libasound.so:audio/alsa-lib \
		libudev.so:devel/libudev-devd \
		libshaderc_shared.so:graphics/shaderc \
		libxkbcommon-x11.so:x11/libxkbcommon
RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins \
		${LOCALBASE}/lib/libvulkan.so:graphics/vulkan-loader

USES=		cargo xorg
USE_XORG=	xcb
USE_GITLAB=	yes
GL_TAGNAME=	v0.17.0-1569-g5378d5cf29 # git describe --match='v[0-9]*' weekly
GL_DATE=	$$(${AWK} '/TIMESTAMP/ { print $$3 }' ${DISTINFO_FILE})
CARGO_ENV=	VELOREN_GIT_VERSION=${GL_TAGNAME:C,(.*)-.*-g(.{8}).*,\1/\2,}/${GL_DATE} \
		VELOREN_USERDATA_STRATEGY=system \
		SHADERC_LIB_DIR="${LOCALBASE}/lib"
PLIST_FILES=	bin/${PORTNAME}-server-cli \
		bin/${PORTNAME}-voxygen \
		share/applications/net.veloren.veloren.desktop \
		share/metainfo/net.veloren.veloren.metainfo.xml \
		share/pixmaps/net.veloren.veloren.png
PORTDATA=	*

CONFLICTS_INSTALL=	${PORTNAME}

# Fixes error "Instruction does not dominate all uses!"
WITHOUT_LTO=	yes # XXX bug 277333

# https://gitlab.com/veloren/veloren/issues/264
CARGO_ENV+=		RUSTC_BOOTSTRAP=1
# XXX https://github.com/rust-lang/cargo/issues/4101
CARGO_INSTALL_PATH=	server-cli voxygen

post-patch:
# Respect PREFIX != /usr/local for system assets
	@${REINPLACE_CMD} -e 's,/usr/share,${DATADIR:H},' \
		${WRKSRC}/common/assets/src/lib.rs

do-install:
# XXX [workspace.dependencies] breaks rebuild in subdirs
.for f in ${CARGO_INSTALL_PATH}
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/*/${PORTNAME}-$f \
		${STAGEDIR}${PREFIX}/bin
.endfor

post-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} assets ${STAGEDIR}${DATADIR})
	${RLN} ${STAGEDIR}${DATADIR}/assets/voxygen/*.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${RLN} ${STAGEDIR}${DATADIR}/assets/voxygen/*.png \
		${STAGEDIR}${PREFIX}/share/pixmaps
	${MKDIR} ${STAGEDIR}${PREFIX}/share/metainfo
	${RLN} ${STAGEDIR}${DATADIR}/assets/voxygen/*.metainfo.xml \
		${STAGEDIR}${PREFIX}/share/metainfo

.include <bsd.port.mk>
