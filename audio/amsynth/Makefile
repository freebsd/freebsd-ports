# $FreeBSD$

PORTNAME=	amsynth
DISTVERSION=	1.8.0.g20171103
PORTREVISION=	3
CATEGORIES=	audio

MAINTAINER=	hello@blubee.me
COMMENT=	Analog modelling software synth

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/dssi.h:audio/dssi
RUN_DEPENDS=	dssi>0:audio/dssi
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libjack.so:audio/jack \
		liblash.so:audio/lash \
		liblo.so:audio/liblo \
		libsndfile.so:audio/libsndfile

USES=		autoreconf:build compiler:gcc-c++11-lib gettext-tools \
		gmake libtool localbase pkgconfig
USE_CXXSTD=	gnu++11
USE_GITHUB=	yes
GH_TAGNAME=	37f25f2
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 intltool pango
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

pre-configure:
	@cd ${WRKSRC} && ./autogen.sh

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/dssi/*.so \
		${STAGEDIR}${PREFIX}/lib/dssi/amsynth_dssi/amsynth_dssi_gtk \
		${STAGEDIR}${PREFIX}/lib/vst/amsynth_vst.so \
		${STAGEDIR}${PREFIX}/lib/lv2/amsynth.lv2/*.so

.include <bsd.port.mk>
