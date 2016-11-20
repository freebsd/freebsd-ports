# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#
# !!!NOTE!!! Any PORTVERSION update to this port must be accompanied by
# PORTREVISION bumps of depending ports.

PORTNAME=	pulseaudio
PORTVERSION=	9.0
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://freedesktop.org/software/pulseaudio/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Sound server for UNIX

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LGPL

LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libjson-c.so:devel/json-c \
		libdbus-1.so:devel/dbus \
		libltdl.so:devel/libltdl \
		libck-connector.so:sysutils/consolekit

USE_GNOME=	glib20 intltool
USE_XORG=	ice sm x11 xcb xtst
USE_LDCONFIG=	yes
USES=		compiler:c11 cpe execinfo gettext gmake gnome iconv libtool \
		pathfix pkgconfig shebangfix ssl tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PTHREAD_LIBS="-lpthread" \
		OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto -lssl" \
		LIBS="-lm -lintl" \
		ac_cv_header_linux_input_h=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

SHEBANG_FILES=	shell-completion/bash/pulseaudio
bash_CMD=	${SETENV} bash
SUB_FILES=	pkg-message

CONFIGURE_ARGS=	--localstatedir=/var \
		--without-caps \
		--disable-udev \
		--disable-gtk3 \
		--disable-systemd-daemon \
		--disable-systemd-journal \
		--disable-systemd-login \
		--disable-neon-opt \
		--disable-xen \
		--disable-lirc # untested

USERS=		pulse
GROUPS=		pulse pulse-access pulse-rt

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	AVAHI GCONF SIMD
OPTIONS_DEFAULT=AVAHI SIMD SIMPLE SOXR SPEEX
AVAHI_CONFIGURE_ENABLE=	avahi
AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app
GCONF_CONFIGURE_ENABLE=	gconf
GCONF_USE=	GNOME=gconf2
SIMD_CONFIGURE_ENABLE=	orc
SIMD_LIB_DEPENDS=	liborc-0.4.so:devel/orc

OPTIONS_GROUP=	AUDIO COMPLETIONS
OPTIONS_GROUP_AUDIO=	ALSA JACK SOXR SPEEX
OPTIONS_GROUP_COMPLETIONS=	BASH ZSH
AUDIO_DESC=	Audio support
COMPLETIONS_DESC=	Programmable completions
ALSA_CONFIGURE_ENABLE=	alsa
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
JACK_CONFIGURE_ENABLE=	jack
JACK_LIB_DEPENDS=	libjack.so:audio/jack
SOXR_DESC=	SoX resampler support
SOXR_CONFIGURE_WITH=	soxr
SOXR_LIB_DEPENDS=	libsoxr.so:audio/libsoxr
SPEEX_DESC=	Speex resampler and AEC support
SPEEX_CONFIGURE_WITH=	speex
SPEEX_LIB_DEPENDS=	libspeexdsp.so:audio/speexdsp
ZSH_CONFIGURE_OFF=	--without-zsh-completion-dir

OPTIONS_SINGLE=	DATABASE
OPTIONS_SINGLE_DATABASE=	TDB GDBM SIMPLE
DATABASE_DESC=	Database support
GDBM_DESC=	GNU database manager support
GDBM_CONFIGURE_ON=	--with-database=gdbm
GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm
SIMPLE_DESC=	Simple database support
SIMPLE_CONFIGURE_ON=	--with-database=simple
TDB_DESC=	Trivial database support
TDB_CONFIGURE_ON=	--with-database=tdb
TDB_LIB_DEPENDS=	libtdb.so:databases/tdb

PULSE_VERSION=	${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PLIST_SUB=	PULSE_VERSION=${PULSE_VERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${LOCALBASE}/share|g' \
		${WRKSRC}/src/daemon/default.pa.in
	@${REINPLACE_CMD} -e 's|-Wmissing-include-dirs||g' \
		-e 's|/lib/dbus/machine-id|/db/dbus/machine-id|g' \
		${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/pulse
.for ii in default.pa daemon.conf client.conf system.pa
	${INSTALL_DATA} ${WRKSRC}/src/${ii} \
		${STAGEDIR}${PREFIX}/etc/pulse/${ii}.sample
.endfor

post-install-BASH-off:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/bash-completion

.include <bsd.port.mk>
