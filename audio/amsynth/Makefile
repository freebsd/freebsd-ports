# $FreeBSD$

PORTNAME=	amsynth
DISTVERSION=	1.9.0
CATEGORIES=	audio
MASTER_SITES=	https://github.com/amsynth/amsynth/releases/download/release-${DISTVERSION}/

MAINTAINER=	tobik@FreeBSD.org
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

USES=		compiler:c++11-lang gettext-tools gmake gnome libtool localbase \
		pkgconfig tar:bzip2
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 intltool pango
INSTALLS_ICONS=	yes

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/dssi/*.so \
		${STAGEDIR}${PREFIX}/lib/dssi/amsynth_dssi/amsynth_dssi_gtk \
		${STAGEDIR}${PREFIX}/lib/vst/amsynth_vst.so \
		${STAGEDIR}${PREFIX}/lib/lv2/amsynth.lv2/*.so

.include <bsd.port.mk>
