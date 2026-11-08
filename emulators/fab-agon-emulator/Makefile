PORTNAME=	fab-agon-emulator
DISTVERSION=	1.2.6
CATEGORIES=	emulators

MAINTAINER=	alexey@pentode.fi
COMMENT=	Emulator of the Agon Light computer
WWW=		https://github.com/tomm/fab-agon-emulator

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libstdc++.so:lang/gcc${GCC_DEFAULT}

USES=		cargo compiler:c++17-lang gmake sdl
USE_GCC=	yes
USE_SDL=	sdl3

USE_GITHUB=	yes
GH_ACCOUNT=	tomm
GH_TUPLE=	tomm:userspace-vdp-gl:075b10cb72970a27c9563d9c94ee78e3e0f45cdd:userspacegl/src/vdp/userspace-vdp-gl \
		tomm:popup-mos:6b056597d560fbf5802db7c97172d0aaee62da4f:popup_mos/sdcard \
		tomm:agon-vdp:1056ee38ec1cc68ed327bd32ee47d04b1c30597c:vdp_console8/src/vdp/vdp-console8 \
		S0urceror:AgonElectronHAL:69d51197334658411d82c44bd8abd6fc2ff88c9d:electronhal/src/vdp/AgonElectronHAL

do-build:
	${SETENVI} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC} ${MAKE_ARGS} vdp
	${CARGO_CARGO_RUN} build \
		--manifest-path agon-cli-emulator/Cargo.toml \
		--verbose \
		${CARGO_BUILD_ARGS}
	${CARGO_CARGO_RUN} build \
		--manifest-path Cargo.toml \
		--verbose \
		${CARGO_BUILD_ARGS}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/firmware/vdp_*.so ${STAGEDIR}${DATADIR}
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/vdp_*.so
	${INSTALL_DATA} ${WRKSRC}/firmware/mos_*.bin ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/firmware/mos_*.map ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/release/fab-agon-emulator \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/release/agon-cli-emulator \
		${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/dist_scripts/io.github.tomm.fab_agon_emulator.desktop \
		${STAGEDIR}${DESKTOPDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps
	${INSTALL_DATA} ${WRKSRC}/dist_scripts/io.github.tomm.fab_agon_emulator.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps
	${MKDIR} ${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_DATA} ${WRKSRC}/dist_scripts/io.github.tomm.fab_agon_emulator.metainfo.xml \
		${STAGEDIR}${PREFIX}/share/metainfo

.include "Makefile.crates"

.include <bsd.port.mk>
