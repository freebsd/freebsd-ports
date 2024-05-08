PORTNAME=	amsynth
DISTVERSION=	1.13.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://github.com/amsynth/amsynth/releases/download/release-${DISTVERSION}/

PATCH_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/commit/
PATCHFILES=	6fb79100a6254220e5adc69a1428572539ecc377.patch:-p1 # Stop using namespace std; https://github.com/amsynth/amsynth/issues/233

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Analog modelling software synth
WWW=		https://amsynth.github.io/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	dssi>0:audio/dssi \
		lv2>0:audio/lv2
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libjack.so:audio/jack \
		liblash.so:audio/lash \
		liblo.so:audio/liblo
RUN_DEPENDS=	dssi>0:audio/dssi

USES=		compiler:c++11-lang gettext-tools gmake gnome libtool localbase \
		pkgconfig xorg
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 intltool pango
USE_XORG=	x11
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

OPTIONS_DEFINE=		MANPAGES NLS
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

MANPAGES_BUILD_DEPENDS=		pandoc:textproc/hs-pandoc
MANPAGES_CONFIGURE_WITH=	pandoc

NLS_CONFIGURE_ENABLE=	nls

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/dssi/*.so \
		${STAGEDIR}${PREFIX}/lib/dssi/amsynth_dssi/amsynth_dssi_gtk \
		${STAGEDIR}${PREFIX}/lib/vst/amsynth_vst.so \
		${STAGEDIR}${PREFIX}/lib/lv2/amsynth.lv2/*.so

.include <bsd.port.mk>
