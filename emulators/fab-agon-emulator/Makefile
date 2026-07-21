PORTNAME=	fab-agon-emulator
DISTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	emulators

MAINTAINER=	alexey@pentode.fi
COMMENT=	Emulator of the AgonLight computer
WWW=		https://github.com/tomm/fab-agon-emulator

LICENSE=	GPLv3

USES+=		cargo gmake python compiler:c++17-lang sdl
USE_GCC=	yes
USE_SDL+=	sdl3

LIB_DEPENDS+=   libstdc++.so:lang/gcc${GCC_DEFAULT}
LIB_DEPENDS+=   libSDL3.so:devel/sdl3

USE_GITHUB=	yes
GH_ACCOUNT=	tomm
GH_TUPLE=	tomm:userspace-vdp-gl:ecb8aabffe97d66d6c6eb30a8a08e09932dbe2e4:userspacegl/src/vdp/userspace-vdp-gl \
		tomm:popup-mos:6b056597d560fbf5802db7c97172d0aaee62da4f:popup_mos/sdcard \
		tomm:agon-vdp:7bcf28e0a2376e32328a6a5554d0df852b75c80e:vdp_console8/src/vdp/vdp-console8 \
		tomm:agon-vdp:883d0f1e300cecaac1a5fe72dc9e5c44b4184167:vdp_quark/src/vdp/vdp-quark \
		S0urceror:AgonElectronHAL:69d51197334658411d82c44bd8abd6fc2ff88c9d:electronhal/src/vdp/AgonElectronHAL

do-build:
	cd ${WRKSRC} && ${SETENVI} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} vdp
	cd ${WRKSRC} && ${SETENVI} ${MAKE_ENV} ${CARGO_ENV} ${CARGO_CARGO_RUN} build \
		--manifest-path agon-cli-emulator/Cargo.toml \
		--verbose \
		--verbose \
		${CARGO_BUILD_ARGS}
	cd ${WRKSRC} && ${SETENVI} ${MAKE_ENV} ${CARGO_ENV} ${CARGO_CARGO_RUN} build \
		--manifest-path Cargo.toml \
		--verbose \
		--verbose \
		${CARGO_BUILD_ARGS}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/fab-agon-emulator
	${INSTALL_DATA} ${WRKSRC}/firmware/vdp_*.so ${STAGEDIR}${PREFIX}/share/fab-agon-emulator/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/share/fab-agon-emulator/vdp_*.so
	${INSTALL_DATA} ${WRKSRC}/firmware/mos_*.bin ${STAGEDIR}${PREFIX}/share/fab-agon-emulator/
	${INSTALL_DATA} ${WRKSRC}/firmware/mos_*.map ${STAGEDIR}${PREFIX}/share/fab-agon-emulator/
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/release/fab-agon-emulator ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/release/agon-cli-emulator ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/dist_scripts/io.github.tomm.fab_agon_emulator.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps
	${INSTALL_DATA} ${WRKSRC}/dist_scripts/io.github.tomm.fab_agon_emulator.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_DATA} ${WRKSRC}/dist_scripts/io.github.tomm.fab_agon_emulator.metainfo.xml ${STAGEDIR}${PREFIX}/share/metainfo/

.include "Makefile.crates"

.include <bsd.port.mk>
