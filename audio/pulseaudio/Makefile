#
# !!!NOTE!!! Any PORTVERSION update to this port must be accompanied by
# PORTREVISION bumps of depending ports.

PORTNAME=	pulseaudio
DISTVERSION=	17.0
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	https://freedesktop.org/software/pulseaudio/releases/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Sound server for UNIX
WWW=		https://www.freedesktop.org/wiki/Software/PulseAudio/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LGPL

BUILD_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser
LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libdbus-1.so:devel/dbus \
		libltdl.so:devel/libltdl \
		libck-connector.so:sysutils/consolekit2

USES=		compiler:c11 cpe gettext-tools gmake gnome iconv localbase:ldflags \
		meson pkgconfig python:run shebangfix ssl tar:xz

USE_GNOME=	glib20
USE_LDCONFIG=	yes

# Some symbols in the linker version script map-file are only defined when
# building the mainloop-glib shared library. Suppress errors with lld >= 17 due
# to these undefined symbols.
LDFLAGS+=	-Wl,--undefined-version

SHEBANG_FILES=	shell-completion/bash/pactl \
		src/utils/pa-info \
		src/utils/qpaeq
bash_CMD=	${SETENV} bash
SUB_FILES=	pkg-message

USERS=		pulse
GROUPS=		pulse pulse-access pulse-rt

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	AVAHI GSETTINGS SIMD TEST X11
OPTIONS_DEFAULT=AVAHI SIMD SIMPLE SOXR SPEEX WEBRTC_AEC X11
AVAHI_MESON_ENABLED=	avahi
AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app
GSETTINGS_DESC=	GSettings configuration backend support
GSETTINGS_MESON_ENABLED=	gsettings
GSETTINGS_VARS=	GLIB_SCHEMAS=org.freedesktop.pulseaudio.gschema.xml
SIMD_MESON_ENABLED=	orc
SIMD_LIB_DEPENDS=	liborc-0.4.so:devel/orc
TEST_MESON_TRUE=	tests
TEST_BUILD_DEPENDS=	check>0:devel/check
X11_MESON_ENABLED=	x11
X11_USES=	xorg
X11_USE=	XORG=ice,sm,x11,xcb,xtst

OPTIONS_GROUP=	AUDIO
OPTIONS_GROUP_AUDIO=	ALSA JACK SOXR SPEEX WEBRTC_AEC
AUDIO_DESC=	Audio support
ALSA_MESON_ENABLED=	alsa
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
JACK_MESON_ENABLED=	jack
JACK_LIB_DEPENDS=	libjack.so:audio/jack
SOXR_MESON_ENABLED=	soxr
SOXR_LIB_DEPENDS=	libsoxr.so:audio/libsoxr
SPEEX_DESC=	Speex resampler and AEC support
SPEEX_MESON_ENABLED=	speex
SPEEX_LIB_DEPENDS=	libspeexdsp.so:audio/speexdsp
WEBRTC_AEC_DESC=	WebRTC-based echo canceller
WEBRTC_AEC_LIB_DEPENDS=	libwebrtc-audio-processing-1.so:audio/webrtc-audio-processing
WEBRTC_AEC_MESON_ENABLED=	webrtc-aec

OPTIONS_SINGLE=	DATABASE
OPTIONS_SINGLE_DATABASE=	TDB GDBM SIMPLE
DATABASE_DESC=	Database support
GDBM_DESC=	GNU database manager support
GDBM_MESON_ON=	-Ddatabase=gdbm
GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm
SIMPLE_DESC=	Simple database support
SIMPLE_MESON_ON=	-Ddatabase=simple
TDB_DESC=	Trivial database support
TDB_MESON_ON=	-Ddatabase=tdb
TDB_LIB_DEPENDS=	libtdb.so:databases/tdb

MESON_ARGS=	-Db_lundef=false -Dasyncns=disabled -Dbluez5=disabled -Dbluez5-gstreamer=disabled -Ddoxygen=false -Delogind=disabled -Dgstreamer=disabled -Dgtk=disabled -Dlirc=disabled -Dsystemd=disabled -Dvalgrind=disabled

PULSE_VERSION=	${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PLIST_SUB=	PULSE_VERSION=${PULSE_VERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${LOCALBASE}/share|g' \
		${WRKSRC}/src/daemon/default.pa.in
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g' \
		-e 's|--directory|-d|g' \
		${WRKSRC}/src/utils/pa-info

post-install:
	${RM} -r ${STAGEDIR}/lib
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/pulse
.for ii in default.pa daemon.conf client.conf system.pa
	${MV} ${STAGEDIR}${PREFIX}/etc/pulse/${ii} \
		${STAGEDIR}${PREFIX}/etc/pulse/${ii}.sample
.endfor
# Delete ${STAGEDIR}${PREFIX}/libexec/pulse directory, if it's empty
	${RMDIR} ${STAGEDIR}${PREFIX}/libexec || ${TRUE}

.include <bsd.port.mk>
