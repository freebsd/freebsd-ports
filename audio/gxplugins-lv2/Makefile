# $FreeBSD$

PORTNAME=	gxplugins
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3-7
DISTVERSIONSUFFIX=	-g8e39e29
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Set of LV2 plugins from the guitarix project

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gmake localbase gettext-runtime pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	brummer10
GH_PROJECT=	GxPlugins.lv2
USE_GNOME=	gtk20 glib20 gdkpixbuf2 atk cairo pango

.for x in	GxBottleRocket.lv2:8a6174b GxGuvnor.lv2:26c94e9 GxHotBox.lv2:3dcbffa GxHyperion.lv2:aae0e12 GxQuack.lv2:84fef2e GxSD1.lv2:01f1f33  \
		GxSD2Lead.lv2:4efa042 GxSVT.lv2:91cd53e GxSaturator.lv2:9d25353 GxSlowGear.lv2:ba7c689 GxSuperFuzz.lv2:8ef00b8 GxSuppaToneBender.lv2:07692d1 \
		GxToneMachine.lv2:bb32739 GxUVox720k.lv2:1af7313 GxVBassPreAmp.lv2:b9cedb5 GxVintageFuzzMaster.lv2:e7a6a6e GxVmk2.lv2:5f61c3d GxVoodoFuzz.lv2:2d63148
GH_TUPLE+=	brummer10:${x}:${x:C/\..*//}/${x:C/:.*//}
.endfor

post-patch:
	# SIMD level is wrongly determined during build: https://github.com/brummer10/GxPlugins.lv2/issues/8
	@${REINPLACE_CMD} -E ' \
		s|shell cat /proc/cpuinfo|shell echo ""|; \
		s| -fstrength-reduce||; \
		s| -O2||; s| -Wl,-z,nodelete||; \
		s| [a-z/]+\.h||g; \
		s|INSTALL_DIR = .*|INSTALL_DIR = ${PREFIX}/lib/lv2|' \
		${WRKSRC}/*/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/*/*.so

.include <bsd.port.mk>
