# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/audio/pulseaudio/Makefile 18611 2013-06-30 16:33:55Z marcus $
#
# !!!NOTE!!! Any PORTVERSION update to this port must be accompanied by
# PORTREVISION bumps of depending ports.

PORTNAME=	pulseaudio
PORTVERSION=	4.0
CATEGORIES=	audio
MASTER_SITES=	http://freedesktop.org/software/pulseaudio/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Sound server for UNIX

# keep the json version otherwise it will match json-glib
LIB_DEPENDS=	libsamplerate.so:${PORTSDIR}/audio/libsamplerate \
		libsndfile.so:${PORTSDIR}/audio/libsndfile \
		libspeexdsp.so:${PORTSDIR}/audio/speex \
		libfftw3.so:${PORTSDIR}/math/fftw3 \
		libfftw3f.so:${PORTSDIR}/math/fftw3-float \
		liborc-0.4.so:${PORTSDIR}/devel/orc \
		libjson.so:${PORTSDIR}/devel/json-c \
		libdbus-1.so:${PORTSDIR}/devel/dbus \
		libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libck-connector.so:${PORTSDIR}/sysutils/consolekit

USE_XZ=		yes
USE_GNOME=	glib20 intltool gnomehier
USE_XORG=	x11 sm xtst ice
USE_LDCONFIG=	yes
USES=		gettext gmake libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libltdl
MAKE_JOBS_UNSAFE=yes
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		OPENSSL_CFLAGS="-I/usr/include" \
		OPENSSL_LIBS="-lcrypto -lssl" \
		LIBS="-lm -lintl" \
		ac_cv_header_linux_input_h=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--localstatedir=/var \
		--with-database=simple \
		--without-caps \
		--disable-udev \
		--disable-gtk3 \
		--disable-neon-opt \
		--disable-lirc # untested

#FIXME --with-database=auto|tdb|gdbm|simple

USERS=		pulse
GROUPS=		pulse pulse-access pulse-rt

OPTIONS_DEFINE=	JACK AVAHI GCONF ALSA SIMD
OPTIONS_DEFAULT=AVAHI GCONF SIMD

PULSE_VERSION=	${PORTVERSION}
PLIST_SUB=	PULSE_VERSION=${PULSE_VERSION}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	libjack.so:${PORTSDIR}/audio/jack
PLIST_SUB+=	JACK=""
.else
PLIST_SUB+=	JACK="@comment "
CONFIGURE_ARGS+=--disable-jack
.endif

.if ${PORT_OPTIONS:MAVAHI}
LIB_DEPENDS+=	libavahi-client.so:${PORTSDIR}/net/avahi-app
PLIST_SUB+=	AVAHI=""
.else
CONFIGURE_ARGS+=--disable-avahi
PLIST_SUB+=	AVAHI="@comment "
.endif

.if ${PORT_OPTIONS:MGCONF}
USE_GNOME+=	gconf2
PLIST_SUB+=	GCONF=""
.else
CONFIGURE_ARGS+=--disable-gconf
PLIST_SUB+=	GCONF="@comment "
.endif

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	libasound.so:${PORTSDIR}/audio/alsa-lib
PLIST_SUB+=	ALSA=""
.else
CONFIGURE_ARGS+=--disable-alsa
PLIST_SUB+=	ALSA="@comment "
.endif

.if ${PORT_OPTIONS:MSIMD}
LIB_DEPENDS+=	liborc-0.4.so:${PORTSDIR}/devel/orc
CONFIGURE_ARGS+=--enable-orc
.else
CONFIGURE_ARGS+=--disable-orc
.endif

.include <bsd.port.pre.mk>

# OSVERSION wasn't bumped after the MFC. So we need to use the next bump.
.if ((${OSVERSION} >= 800000) && (${OSVERSION} < 802504)) || \
	((${OSVERSION} >= 900000) && (${OSVERSION} < 900037))
EXTRA_PATCHES+=	${FILESDIR}/extra-src_modules_oss_module-oss.c
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/daemon/default.pa.in
	@${REINPLACE_CMD} -e 's|-Wmissing-include-dirs||g' \
		${WRKSRC}/configure

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/pulse
.for ii in default.pa daemon.conf client.conf system.pa
	${INSTALL_DATA} ${WRKSRC}/src/${ii} \
		${STAGEDIR}${PREFIX}/etc/pulse/${ii}-dist
.endfor

.include <bsd.port.post.mk>
