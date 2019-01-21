# $FreeBSD$

PORTNAME=	gxplugins
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Set of LV2 plugins from the guitarix project

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2

USES=		compiler:c++11-lang gettext-runtime gmake gnome localbase pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	brummer10
GH_PROJECT=	GxPlugins.lv2
USE_GNOME=	cairo
USE_XORG=	x11
USE_BINUTILS=	yes # linking needs some GNU features, fails on 12 without this, see https://github.com/brummer10/GxPlugins.lv2/issues/9

MAKE_ENV=	PATH=${LOCALBASE}/bin:/usr/bin:/bin # 'ld' needs to be first in the path on 12, -B{path} isn't sufficient for some reason
LDFLAGS+=	-B${LOCALBASE}/bin # Use ld provided by USE_BINUTILS for GNU features, otherwise GNU ld isn't called

.for x in	GxAxisFace.lv2:43b9c8a GxBoobTube.lv2:4a5dd48 GxBottleRocket.lv2:0be3709 GxCreamMachine.lv2:bad5307 GxDOP250.lv2:0b7cadd  \
		GxFz1b.lv2:52ecd61 GxFz1s.lv2:7bb67aa GxGuvnor.lv2:9b16717 GxHeathkit.lv2:d88647e GxHotBox.lv2:3df0a12  \
		GxHyperion.lv2:0436d91 GxKnightFuzz.lv2:0cd6814 GxLiquidDrive.lv2:e12a9d9 GxMicroAmp.lv2:611bd7d GxQuack.lv2:2668d1e  \
		GxSD1.lv2:456418c GxSD2Lead.lv2:4f219a1 GxSVT.lv2:437ca62 GxSaturator.lv2:792f414 GxSlowGear.lv2:145fef7  \
		GxSunFace.lv2:3676397 GxSuperFuzz.lv2:eda8506 GxSuppaToneBender.lv2:e806945 GxToneMachine.lv2:413f833 GxTubeDistortion.lv2:4e12a26  \
		GxUVox720k.lv2:7fb222e GxVBassPreAmp.lv2:95bc7fb GxValveCaster.lv2:c29392b GxVintageFuzzMaster.lv2:dd3cb30 GxVmk2.lv2:1ef6805  \
		GxVoodoFuzz.lv2:b6750b9
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
