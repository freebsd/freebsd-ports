PORTNAME=	gram
DISTVERSION=	3.3.0
CATEGORIES=	editors
MASTER_SITES=	https://codeberg.org/GramEditor/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/:main
PKGNAMESUFFIX=	-text-editor
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:main

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fork of the Zed code editor without AI or telemetry
WWW=		https://codeberg.org/GramEditor/gram \
		https://gram-editor.com/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE-GPL

BROKEN_aarch64=	compilation fails: cannot find value `KINFO_FILE_SIZE` in crate `libc`, see https://github.com/rust-lang/libc/issues/5535
BROKEN_i386=	compilation fails: error[E0308]: mismatched types ... expected `u32`, found `u64`

BUILD_DEPENDS=	protoc:devel/protobuf
LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libssh2.so:security/libssh2 \
		libzstd.so:archivers/zstd \
		libxkbcommon.so:x11/libxkbcommon \
		libxkbcommon-x11.so:x11/libxkbcommon

USES=		cargo desktop-file-utils ssl xorg
USE_XORG=	xcb

CARGO_ENV=	LIBGIT2_NO_VENDOR=1 \
		LIBSSH2_SYS_USE_PKG_CONFIG=1 \
		OPENSSL_NO_VENDOR=1
CARGO_INSTALL_PATH=	crates/gram

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/app.liten.Gram.desktop \
		share/icons/hicolor/scalable/apps/app.liten.Gram.svg

post-install:
	# install .desktop file and svg icon
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/applications
	@${SED} -e 's/\$$APP_NAME/Gram/g' \
		-e 's/\$$APP_CLI/gram/g' \
		-e 's/\$$APP_ARGS/%F/g' \
		-e 's/\$$DO_STARTUP_NOTIFY/true/g' \
		-e 's/\$$APP_ICON/app.liten.Gram/g' \
		${WRKSRC}/crates/gram/resources/gram.desktop.in \
		> ${STAGEDIR}${PREFIX}/share/applications/app.liten.Gram.desktop
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	@${INSTALL_DATA} ${WRKSRC}/crates/gram/resources/app.liten.Gram.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps

.include <bsd.port.mk>
