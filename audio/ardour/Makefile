PORTNAME=	ardour
DISTVERSION=	7.5.0
CATEGORIES=	audio
# Official source download is tailored to browsers, downloads from github are
# deliberately made empty. Put the badly named distfile into a subdirectory.
MASTER_SITES=	https://community.ardour.org/download/release/
DISTNAME=	Ardour-${DISTVERSION}
DISTFILES=	534
DIST_SUBDIR=	${DISTNAME}

MAINTAINER=	dev@submerge.ch
COMMENT=	Multichannel digital audio workstation
WWW=		https://ardour.org/

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
		libarchive pkgconfig python:build readline tar:bzip2 \
		waf xorg shared-mime-info
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

ARDOUR_MAJOR=	ardour7
DATADIR=	${PREFIX}/share/${ARDOUR_MAJOR}
ETCDIR=		${PREFIX}/etc/${ARDOUR_MAJOR}
PLIST_SUB+=	VERSION=${PORTVERSION} \
		ARDOUR_MAJOR=${ARDOUR_MAJOR}

post-patch:
	@${REINPLACE_CMD} -e 's/obj\.use            = '\''libsmf libpbd'\''/obj\.use            = '\''libsmf_internal libpbd'\''/g' ${WRKSRC}/libs/evoral/wscript
	@${REINPLACE_CMD} -e 's/libsmf\.name         = '\''libsmf'\''/libsmf\.name         = '\''libsmf_internal'\''/g' ${WRKSRC}/libs/evoral/wscript
	@${REINPLACE_CMD} -e 's/libsmf\.target       = '\''smf'\''/libsmf\.target       = '\''smf_internal'\''/g' ${WRKSRC}/libs/evoral/wscript

post-install:
	@${FIND} ${STAGEDIR}${PREFIX}/lib/${ARDOUR_MAJOR} \
		-name '*.so*' -exec ${STRIP_CMD} {} +
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${ARDOUR_MAJOR}/sanityCheck
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${ARDOUR_MAJOR}/utils/${ARDOUR_MAJOR}-copy-mixer
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${ARDOUR_MAJOR}/utils/${ARDOUR_MAJOR}-export
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${ARDOUR_MAJOR}/utils/${ARDOUR_MAJOR}-new_empty_session
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${ARDOUR_MAJOR}/utils/${ARDOUR_MAJOR}-new_session
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${ARDOUR_MAJOR}/ardour-exec-wrapper
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${ARDOUR_MAJOR}/ardour-vst-scanner
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${ARDOUR_MAJOR}/ardour-${PORTVERSION}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${ARDOUR_MAJOR}/hardour-${PORTVERSION}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${ARDOUR_MAJOR}/luasession
	@${LN} -sf ../lib/${ARDOUR_MAJOR}/utils/ardour-util.sh \
		${STAGEDIR}${PREFIX}/bin/${ARDOUR_MAJOR}-new_session
	@${LN} -sf ../lib/${ARDOUR_MAJOR}/utils/ardour-util.sh \
		${STAGEDIR}${PREFIX}/bin/${ARDOUR_MAJOR}-copy-mixer
	@${LN} -sf ../lib/${ARDOUR_MAJOR}/utils/ardour-util.sh \
		${STAGEDIR}${PREFIX}/bin/${ARDOUR_MAJOR}-export
	@${LN} -sf ../lib/${ARDOUR_MAJOR}/utils/ardour-util.sh \
		${STAGEDIR}${PREFIX}/bin/${ARDOUR_MAJOR}-new_empty_session
	@${LN} -sf ffmpeg ${STAGEDIR}${PREFIX}/bin/ffmpeg_harvid
	@${LN} -sf ffprobe ${STAGEDIR}${PREFIX}/bin/ffprobe_harvid

.include <bsd.port.mk>
