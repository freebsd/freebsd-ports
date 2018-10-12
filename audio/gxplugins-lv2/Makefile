# $FreeBSD$

PORTNAME=	gxplugins
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5
CATEGORIES=	audio
DIST_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Set of LV2 plugins from the guitarix project

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		compiler:c++11-lang gettext-runtime gmake gnome localbase pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	brummer10
GH_PROJECT=	GxPlugins.lv2
USE_GNOME=	gtk20 glib20 gdkpixbuf2 atk cairo pango
USE_XORG=	x11

.for x in	GxAxisFace.lv2:c370e75 GxBottleRocket.lv2:8d1a914 GxDOP250.lv2:574b709 GxFz1b.lv2:d204796 GxFz1s.lv2:973d6f7 \
		GxGuvnor.lv2:6082bcf GxHeathkit.lv2:bb73b24 GxHotBox.lv2:db17513 GxHyperion.lv2:9b91395 GxKnightFuzz.lv2:0d9518f \
		GxLiquidDrive.lv2:723f399 GxMicroAmp.lv2:3a318af GxQuack.lv2:e95e388 GxSD1.lv2:423ff27 GxSD2Lead.lv2:ab1310e \
		GxSVT.lv2:e5bf0ba GxSaturator.lv2:51a8236 GxSlowGear.lv2:c6d8dfa GxSunFace.lv2:aba2cb2 GxSuperFuzz.lv2:a9c806b \
		GxSuppaToneBender.lv2:1861386 GxToneMachine.lv2:ab2eec8 GxTubeDistortion.lv2:d57c0bc GxUVox720k.lv2:cb15f2f GxVBassPreAmp.lv2:0adee2f \
		GxVintageFuzzMaster.lv2:53c9e65 GxVmk2.lv2:8d04939 GxVoodoFuzz.lv2:53d4853
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
