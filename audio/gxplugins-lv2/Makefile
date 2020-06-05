# $FreeBSD$

PORTNAME=	gxplugins
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Set of LV2 plugins from the guitarix project

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2

USES=		compiler:c++11-lang gettext-runtime gmake gnome localbase \
		pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	brummer10
GH_PROJECT=	GxPlugins.lv2
USE_GNOME=	cairo
USE_XORG=	x11
USE_BINUTILS=	yes # linking needs some GNU features, fails on 12 without this, see https://github.com/brummer10/GxPlugins.lv2/issues/9

MAKE_ENV=	PATH=${LOCALBASE}/bin:/usr/bin:/bin CXXFLAGS="${CXXFLAGS}" # 'ld' needs to be first in the path on 12, -B{path} isn't sufficient for some reason
LDFLAGS+=	-B${LOCALBASE}/bin # Use ld provided by USE_BINUTILS for GNU features, otherwise GNU ld isn't called

GH_TUPLE=	\
		brummer10:GxBottleRocket.lv2:f03103e051415a6c1ed3b7e01e7f0267e944897d:brummer10_GxBottleRocket_lv2/GxBottleRocket.lv2 \
		brummer10:GxHotBox.lv2:33199a776a173ad2823cd3acee55522979e8f5fc:brummer10_GxHotBox_lv2/GxHotBox.lv2 \
		brummer10:GxVBassPreAmp.lv2:9c7839724c91e60cce1da6862985dce75f5a2b30:brummer10_GxVBassPreAmp_lv2/GxVBassPreAmp.lv2 \
		brummer10:GxSuppaToneBender.lv2:12cceceb44088331ab015070f48676ced0943e14:brummer10_GxSuppaToneBender_lv2/GxSuppaToneBender.lv2 \
		brummer10:GxHyperion.lv2:8f527b405368f10c9733e2df586a5ebc6e809a25:brummer10_GxHyperion_lv2/GxHyperion.lv2 \
		brummer10:GxVoodoFuzz.lv2:6a1691ec8415a591ae1543a3f3dedab2cb732ca9:brummer10_GxVoodoFuzz_lv2/GxVoodoFuzz.lv2 \
		brummer10:GxSaturator.lv2:5cab301958d4415a6c2afa5d9fb671e8f3ebfada:brummer10_GxSaturator_lv2/GxSaturator.lv2 \
		brummer10:GxVintageFuzzMaster.lv2:8eccd39dab83c2d250891e9d10ff6eae5c0ee3ed:brummer10_GxVintageFuzzMaster_lv2/GxVintageFuzzMaster.lv2 \
		brummer10:GxSuperFuzz.lv2:1b3136df227b09b827414d8d482274d8fe3bacdb:brummer10_GxSuperFuzz_lv2/GxSuperFuzz.lv2 \
		brummer10:GxVmk2.lv2:8c2fa6bc35eac425e3daa31df7c7b0ba3de716ab:brummer10_GxVmk2_lv2/GxVmk2.lv2 \
		brummer10:GxUVox720k.lv2:79fc7d58bec29eab4d0b51ec3436a0cb1634858e:brummer10_GxUVox720k_lv2/GxUVox720k.lv2 \
		brummer10:GxSlowGear.lv2:3360b4d6d488d483d0d5590eaec35aa1fbaa543f:brummer10_GxSlowGear_lv2/GxSlowGear.lv2 \
		brummer10:GxGuvnor.lv2:ac676cd28972d1db357277f521ec290e717e7401:brummer10_GxGuvnor_lv2/GxGuvnor.lv2 \
		brummer10:GxToneMachine.lv2:6a60333873ae912d485f7a160ce5b706f41a96b5:brummer10_GxToneMachine_lv2/GxToneMachine.lv2 \
		brummer10:GxSD1.lv2:d04fe9f27e0056ac26ce92efda62f8296ca3cbb9:brummer10_GxSD1_lv2/GxSD1.lv2 \
		brummer10:GxQuack.lv2:6bc2fa374cd85ab52ebf48825362edac5ddc8796:brummer10_GxQuack_lv2/GxQuack.lv2 \
		brummer10:GxSD2Lead.lv2:b0f01c7852684ccc20deb3ee9af33fbf51e8b1b9:brummer10_GxSD2Lead_lv2/GxSD2Lead.lv2 \
		brummer10:GxSVT.lv2:1229efd48e0758bdb18a5e34ae8f15119682c071:brummer10_GxSVT_lv2/GxSVT.lv2 \
		brummer10:GxHeathkit.lv2:cbc0a170172bc375617308707dbcb2249724adde:brummer10_GxHeathkit_lv2/GxHeathkit.lv2 \
		brummer10:GxKnightFuzz.lv2:b109e947b78fd1f04e0a448c31febb4ecf061541:brummer10_GxKnightFuzz_lv2/GxKnightFuzz.lv2 \
		brummer10:GxFz1b.lv2:476f439869c773429cd3686550b53b1ba6d6f39c:brummer10_GxFz1b_lv2/GxFz1b.lv2 \
		brummer10:GxFz1s.lv2:e6442fd05426b7cf11680d48e8ac12660c4e9039:brummer10_GxFz1s_lv2/GxFz1s.lv2 \
		brummer10:GxAxisFace.lv2:d38619779d8421ab066656ed3f0e153298994f5a:brummer10_GxAxisFace_lv2/GxAxisFace.lv2 \
		brummer10:GxSunFace.lv2:f86cb8f24ae3ecc66ae54013100b22d73b089780:brummer10_GxSunFace_lv2/GxSunFace.lv2 \
		brummer10:GxLiquidDrive.lv2:99457b40a6a9c0b9a8864b32f1ba51600f3c27a9:brummer10_GxLiquidDrive_lv2/GxLiquidDrive.lv2 \
		brummer10:GxDOP250.lv2:db848e7b99df3ee12905a64225eeae7492fecfa4:brummer10_GxDOP250_lv2/GxDOP250.lv2 \
		brummer10:GxTubeDistortion.lv2:eea4e256eee294ab6243d69ab0db980eebd0a005:brummer10_GxTubeDistortion_lv2/GxTubeDistortion.lv2 \
		brummer10:GxMicroAmp.lv2:3d331bd7269148317a5c4dc10c36626e4379aba7:brummer10_GxMicroAmp_lv2/GxMicroAmp.lv2 \
		brummer10:GxCreamMachine.lv2:8c1bb1510b3ddbb2b80ef2c7b4e28bc9840fb9f0:brummer10_GxCreamMachine_lv2/GxCreamMachine.lv2 \
		brummer10:GxBoobTube.lv2:6ef6d2543fc3c02ec7ffe89df59664da4d9c958a:brummer10_GxBoobTube_lv2/GxBoobTube.lv2 \
		brummer10:GxValveCaster.lv2:888133d76d8aaa9a85ebb098d16b91558fe5e281:brummer10_GxValveCaster_lv2/GxValveCaster.lv2 \
		brummer10:GxSupersonic.lv2:74f2576609626bb39935f4603eb05a449427e9ac:brummer10_GxSupersonic_lv2/GxSupersonic.lv2 \
		brummer10:GxEpic.lv2:99c124d94982fa6ef9e8134ef06e1b3686731c4b:brummer10_GxEpic_lv2/GxEpic.lv2 \
		brummer10:GxShakaTube.lv2:e3c44b796c274c8ced14ebc9a368196e17ce2dce:brummer10_GxShakaTube_lv2/GxShakaTube.lv2 \
		brummer10:GxBaJaTubeDriver.lv2:1fbb09617507e70a0483029cd68e610c945de0ae:brummer10_GxBaJaTubeDriver_lv2/GxBaJaTubeDriver.lv2 \
		brummer10:GxUltraCab.lv2:8949921989e590a1e28e33eca87ae1f16d47b239:brummer10_GxUltraCab_lv2/GxUltraCab.lv2 \
		brummer10:GxTimRay.lv2:321b287365d826c4a6703b1bcdb184666143b819:brummer10_GxTimRay_lv2/GxTimRay.lv2 \
		brummer10:GxLuna.lv2:bcb88e5cc6daf6aed21ac6601478bbe39f96460c:brummer10_GxLuna_lv2/GxLuna.lv2 \
		brummer10:GxSloopyBlue.lv2:73e71b0757a5c99816d7fa304bc4157ec871f852:brummer10_GxSloopyBlue_lv2/GxSloopyBlue.lv2 \
		brummer10:GxEternity.lv2:81a88219d41f63320c33e144f7abad9f7e408502:brummer10_GxEternity_lv2/GxEternity.lv2 \
		brummer10:GxBlueAmp.lv2:52ea6beedab9e41d95e24c640adbe4017f866b15:brummer10_GxBlueAmp_lv2/GxBlueAmp.lv2 \
		brummer10:GxPlexi.lv2:608e69da7134309af140012e32c44ccd82174e94:brummer10_GxPlexi_lv2/GxPlexi.lv2 \
		brummer10:GxClubDrive.lv2:362471cdf94b797d74e9fd684528808c0125413f:brummer10_GxClubDrive_lv2/GxClubDrive.lv2 \

post-patch:
	# SIMD level is wrongly determined during build, not during run: https://github.com/brummer10/GxPlugins.lv2/issues/8
	@${REINPLACE_CMD} -E ' \
		s|shell cat /proc/cpuinfo|shell echo ""|; \
		s| -fstrength-reduce||; \
		s| -O2||; s| -Wl,-z,nodelete||; \
		s|INSTALL_DIR = .*|INSTALL_DIR = ${PREFIX}/lib/lv2|' \
		${WRKSRC}/*/Makefile

.include <bsd.port.mk>
