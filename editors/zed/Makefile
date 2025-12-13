PORTNAME=	zed
DISTVERSIONPREFIX=	v
DISTVERSION=	0.216.1
CATEGORIES=	editors
PKGNAMESUFFIX=	-editor

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Code at the speed of thought
WWW=		https://zed.dev/

LICENSE=	AGPLv3 APACHE20 GPLv3
LICENSE_COMB=	multi
LICENSE_FILE_AGPLv3=	${WRKSRC}/LICENSE-AGPL
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSE-GPL

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	Some of dependent crates only support these architectures

BUILD_DEPENDS=	protoc:devel/protobuf
LIB_DEPENDS=	libzstd.so:archivers/zstd \
		libasound.so:audio/alsa-lib \
		libgit2.so:devel/libgit2 \
		libcurl.so:ftp/curl \
		libvulkan.so:graphics/vulkan-loader \
		libwayland-client.so:graphics/wayland \
		libfontconfig.so:x11-fonts/fontconfig \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	vulkaninfo:graphics/vulkan-tools \
		npm${NODEJS_SUFFIX}>0:www/npm${NODEJS_SUFFIX} \
		xdg-desktop-portal-gtk>0:x11/xdg-desktop-portal-gtk

USES=		cargo cmake:indirect desktop-file-utils gettext-runtime:build \
		llvm nodejs:lts,run ssl xorg

USE_GITHUB=	yes
GH_ACCOUNT=	zed-industries

USE_XORG=	x11 xcb

CARGO_BUILD_ARGS=	--package zed --package cli --package remote_server
CARGO_TEST_ARGS=	--workspace

MAKE_ENV=	APP_CLI="zedit" \
		APP_ICON="zed-editor" \
		APP_ID="dev.zed.Zed" \
		APP_NAME="Zed" \
		APP_ARGS="%U" \
		DO_STARTUP_NOTIFY="true" \
		ZED_UPDATE_EXPLANATION="Please use packages/ports to update zed." \
		RELEASE_VERSION="${DISTVERSION}"

PLIST_FILES=	bin/zedit \
		bin/zed-remote-server-stable-${DISTVERSION} \
		libexec/zed-editor \
		share/applications/dev.zed.Zed.desktop \
		share/icons/hicolor/1024x1024/apps/zed-editor.png \
		share/icons/hicolor/512x512/apps/zed-editor.png
PORTDOCS=	CONTRIBUTING.md README.md

OPTIONS_DEFINE=	DOCS

post-patch:
# https://github.com/RazrFalcon/fontdb/issues/61
	@${REINPLACE_CMD} -e 's|/etc|${LOCALBASE}&|g' \
		${WRKSRC_crate_fontdb-0.16.2}/src/lib.rs \
		${WRKSRC_crate_fontdb-0.23.0}/src/lib.rs

post-build:
	${SETENV} ${MAKE_ENV} envsubst < \
		${WRKSRC}/crates/zed/resources/zed.desktop.in > \
		${WRKSRC}/crates/zed/resources/zed.desktop

do-install:
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/release/cli \
		${STAGEDIR}${PREFIX}/bin/zedit
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/release/remote_server \
		${STAGEDIR}${PREFIX}/bin/zed-remote-server-stable-${DISTVERSION}
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/release/zed \
		${STAGEDIR}${PREFIX}/libexec/zed-editor
	${INSTALL_DATA} ${WRKSRC}/crates/zed/resources/${PORTNAME}.desktop \
		${STAGEDIR}${DESKTOPDIR}/dev.zed.Zed.desktop
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps
	${INSTALL_DATA} ${WRKSRC}/crates/zed/resources/app-icon.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps/zed-editor.png
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/1024x1024/apps
	${INSTALL_DATA} ${WRKSRC}/crates/zed/resources/app-icon@2x.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/1024x1024/apps/zed-editor.png

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
