# $FreeBSD$

PORTNAME=	gxplugins
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7
PORTREVISION=	1
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

MAKE_ENV=	PATH=${LOCALBASE}/bin:/usr/bin:/bin # 'ld' needs to be first in the path on 12, -B{path} isn't sufficient for some reason
LDFLAGS+=	-B${LOCALBASE}/bin # Use ld provided by USE_BINUTILS for GNU features, otherwise GNU ld isn't called

.for x in	GxAxisFace.lv2:9faf769 GxBaJaTubeDriver.lv2:c219ce5 GxBlueAmp.lv2:7c8fb11 GxBoobTube.lv2:4a5dd48 GxBottleRocket.lv2:98d41d4 \
		GxClubDrive.lv2:2ecd909 GxCreamMachine.lv2:bad5307 GxDOP250.lv2:67a86cc GxEpic.lv2:f72db5b GxEternity.lv2:7b3b6e8 \
		GxFz1b.lv2:78fbf20 GxFz1s.lv2:f10812b GxGuvnor.lv2:9e410d8 GxHeathkit.lv2:e4edcb8 GxHotBox.lv2:09d0a85 \
		GxHyperion.lv2:dd86308 GxKnightFuzz.lv2:f719843 GxLiquidDrive.lv2:99061a0 GxLuna.lv2:b6b13f7 GxMicroAmp.lv2:ff4073c \
		GxPlexi.lv2:ba115d5 GxQuack.lv2:05e53d6 GxSD1.lv2:9c8d6a4 GxSD2Lead.lv2:ad987d0 GxSVT.lv2:7c7880c \
		GxSaturator.lv2:52bf9e3 GxShakaTube.lv2:7682324 GxSloopyBlue.lv2:fa4e3f4 GxSlowGear.lv2:5471bd4 GxSunFace.lv2:b2fc690 \
		GxSuperFuzz.lv2:b8103b5 GxSupersonic.lv2:a116614 GxSuppaToneBender.lv2:0fd3051 GxTimRay.lv2:efda591 GxToneMachine.lv2:efa8681 \
		GxTubeDistortion.lv2:a1a789f GxUVox720k.lv2:a7ad702 GxUltraCab.lv2:8e5fa23 GxVBassPreAmp.lv2:d7f2f6a GxValveCaster.lv2:c29392b \
		GxVintageFuzzMaster.lv2:8bec199 GxVmk2.lv2:c5bd4a7 GxVoodoFuzz.lv2:7356f5a
GH_TUPLE+=	brummer10:${x}:${x:C/\..*//}/${x:C/:.*//}
.endfor

post-patch:
	# SIMD level is wrongly determined during build, not during run: https://github.com/brummer10/GxPlugins.lv2/issues/8
	@${REINPLACE_CMD} -E ' \
		s|shell cat /proc/cpuinfo|shell echo ""|; \
		s| -fstrength-reduce||; \
		s| -O2||; s| -Wl,-z,nodelete||; \
		s|INSTALL_DIR = .*|INSTALL_DIR = ${PREFIX}/lib/lv2|' \
		${WRKSRC}/*/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/*/*.so

.include <bsd.port.mk>
