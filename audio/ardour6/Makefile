# Created by: Michael Beer <beerml@sigma6audio.de>

PORTNAME=	ardour6
PORTVERSION=	6.9.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	LOCAL/nc/mirror/ \
		https://community.ardour.org/srctar/ \
		https://misc.neelc.org/mirror/
# The original master side points to the latest release only:
# MASTER_SITES=	https://community.ardour.org/srctar/
DISTNAME=	Ardour-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multichannel digital audio workstation

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>=1.18.0:audio/lv2 \
		itstool>2.0.0:textproc/itstool \
		${BUILD_DEPENDS_${ARCH}}
BUILD_DEPENDS_aarch64=	as:devel/binutils
LIB_DEPENDS=	libserd-0.so:devel/serd \
		libsord-0.so:devel/sord \
		libsratom-0.so:audio/sratom \
		liblilv-0.so:audio/lilv \
		libsuil-0.so:audio/suil \
		libaubio.so:audio/aubio \
		librubberband.so:audio/rubberband \
		liblo.so:audio/liblo \
		liblrdf.so:textproc/liblrdf \
		libjack.so:audio/jack \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libboost_date_time.so:devel/boost-libs \
		libvamp-hostsdk.so:audio/vamp-plugin-sdk \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile \
		libtag.so:audio/taglib \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libcurl.so:ftp/curl \
		libogg.so:audio/libogg \
		libFLAC.so:audio/flac \
		libSoundTouch.so:audio/soundtouch \
		libwebsockets.so:net/libwebsockets

USES=		compiler:c++11-lang desktop-file-utils gettext gnome \
		libarchive pkgconfig python:3.7,build readline tar:bzip2 \
		waf xorg
USE_CXXSTD=	c++11
USE_GNOME=	atk cairo cairomm gdkpixbuf2 glib20 glibmm gtk20 gtkmm24 pango
USE_LDCONFIG=	yes
USE_XORG=	x11

CONFIGURE_ARGS=	--optimize --ptformat --freedesktop --no-phone-home \
		--with-backends=jack,dummy --internal-shared-libs --no-vst3 \
		${CONFIGURE_ARGS_${ARCH}}
CONFIGURE_ARGS_amd64=	--arch='-msse -mfpmath=sse -DARCH_X86' --dist-target=x86_64
# only support for i686 or better
CONFIGURE_ARGS_i386=	--arch='-msse -mfpmath=sse -march=i686 -DARCH_X86' --dist-target=i686

LDFLAGS_powerpc=	-Wl,-z,notext

BINARY_ALIAS+=	gas=${CC}

PLIST_SUB=	ARDOURVERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's/obj\.use            = '\''libsmf libpbd'\''/obj\.use            = '\''libsmf_internal libpbd'\''/g' ${WRKSRC}/libs/evoral/wscript
	@${REINPLACE_CMD} -e 's/libsmf\.name         = '\''libsmf'\''/libsmf\.name         = '\''libsmf_internal'\''/g' ${WRKSRC}/libs/evoral/wscript
	@${REINPLACE_CMD} -e 's/libsmf\.target       = '\''smf'\''/libsmf\.target       = '\''smf_internal'\''/g' ${WRKSRC}/libs/evoral/wscript

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/appdata
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/applications
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/16x16/apps
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/22x22/apps
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps
	@${CP} ${WRKSRC}/build/gtk2_ardour/${PORTNAME}.appdata.xml \
		${STAGEDIR}${PREFIX}/share/appdata/${PORTNAME}.appdata.xml
	@${CP} ${WRKSRC}/build/gtk2_ardour/${PORTNAME}.desktop \
		${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}.desktop
	@${CP} ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/Ardour-icon_16px.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/16x16/apps/${PORTNAME}.png
	@${CP} ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/Ardour-icon_22px.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/22x22/apps/${PORTNAME}.png
	@${CP} ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/Ardour-icon_32px.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps/${PORTNAME}.png
	@${CP} ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/Ardour-icon_48px.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png
	@${CP} ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/Ardour-icon_256px.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps/${PORTNAME}.png
	@${CP} ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/Ardour-icon_512px.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps/${PORTNAME}.png
	@${FIND} ${STAGEDIR}${PREFIX}/lib/${PORTNAME} \
		-name '*.so*' -exec ${STRIP_CMD} {} +
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/sanityCheck
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/utils/${PORTNAME}-copy-mixer
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/utils/${PORTNAME}-export
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/utils/${PORTNAME}-fix_bbtppq
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/utils/${PORTNAME}-new_empty_session
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/utils/${PORTNAME}-new_session
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/ardour-exec-wrapper
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/ardour-vst-scanner
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/ardour-${PORTVERSION}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/hardour-${PORTVERSION}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/luasession
	@${LN} -sf ffmpeg ${STAGEDIR}${PREFIX}/bin/ffmpeg_harvid
	@${LN} -sf ffprobe ${STAGEDIR}${PREFIX}/bin/ffprobe_harvid

.include <bsd.port.mk>
