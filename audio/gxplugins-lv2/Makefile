# $FreeBSD$

PORTNAME=	gxplugins
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Set of LV2 plugins from the guitarix project

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gettext-runtime gmake localbase pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	brummer10
GH_PROJECT=	GxPlugins.lv2
USE_GNOME=	gtk20 glib20 gdkpixbuf2 atk cairo pango

.for x in	GxBottleRocket.lv2:21c9948 GxGuvnor.lv2:9ae6f47 GxHotBox.lv2:c841718 GxHyperion.lv2:af82eb8 GxQuack.lv2:a502805 GxSD1.lv2:22f8a40  \
		GxSD2Lead.lv2:7a4a20b GxSVT.lv2:8f2e1ef GxSaturator.lv2:6eb8870 GxSlowGear.lv2:759bc93 GxSuperFuzz.lv2:9406f2e GxSuppaToneBender.lv2:25efb3a \
		GxToneMachine.lv2:a53ea0f GxUVox720k.lv2:ac18d3a GxVBassPreAmp.lv2:85a9011 GxVintageFuzzMaster.lv2:4bb15cb GxVmk2.lv2:08ace4f GxVoodoFuzz.lv2:1557baf
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
