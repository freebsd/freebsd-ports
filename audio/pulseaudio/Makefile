# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/audio/pulseaudio/Makefile 19813 2014-08-15 19:44:33Z gusi $
#
# !!!NOTE!!! Any PORTVERSION update to this port must be accompanied by
# PORTREVISION bumps of depending ports.

PORTNAME=	pulseaudio
PORTVERSION=	5.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://freedesktop.org/software/pulseaudio/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Sound server for UNIX

LIB_DEPENDS=	libsamplerate.so:${PORTSDIR}/audio/libsamplerate \
		libsndfile.so:${PORTSDIR}/audio/libsndfile \
		libspeexdsp.so:${PORTSDIR}/audio/speex \
		libfftw3.so:${PORTSDIR}/math/fftw3 \
		libfftw3f.so:${PORTSDIR}/math/fftw3-float \
		liborc-0.4.so:${PORTSDIR}/devel/orc \
		libjson.so:${PORTSDIR}/devel/json-c \
		libdbus-1.so:${PORTSDIR}/devel/dbus \
		libck-connector.so:${PORTSDIR}/sysutils/consolekit

USE_GNOME=	glib20 gnomehier intltool
USE_XORG=	x11 sm xtst ice
USE_LDCONFIG=	yes
USES=		execinfo gettext gmake libtool pathfix \
		pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libltdl
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

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	JACK AVAHI GCONF ALSA SIMD
OPTIONS_DEFAULT=AVAHI SIMD
JACK_CONFIGURE_ENABLE=	jack
JACK_LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack
AVAHI_CONFIGURE_ENABLE=	avahi
AVAHI_LIB_DEPENDS=	libavahi-client.so:${PORTSDIR}/net/avahi-app
GCONF_CONFIGURE_ENABLE=	gconf
GCONF_USE=	GNOME=gconf2
ALSA_CONFIGURE_ENABLE=	alsa
ALSA_LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib
SIMD_CONFIGURE_ENABLE=	orc
SIMD_LIB_DEPENDS=	liborc-0.4.so:${PORTSDIR}/devel/orc

PULSE_VERSION=	${PORTVERSION}
PLIST_SUB=	PULSE_VERSION=${PULSE_VERSION}

.include <bsd.port.pre.mk>

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
