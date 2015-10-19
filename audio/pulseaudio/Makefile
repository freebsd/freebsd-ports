# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#
# !!!NOTE!!! Any PORTVERSION update to this port must be accompanied by
# PORTREVISION bumps of depending ports.

PORTNAME=	pulseaudio
PORTVERSION=	6.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://freedesktop.org/software/pulseaudio/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Sound server for UNIX

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LGPL

LIB_DEPENDS=	libsndfile.so:${PORTSDIR}/audio/libsndfile \
		libspeexdsp.so:${PORTSDIR}/audio/speexdsp \
		libfftw3.so:${PORTSDIR}/math/fftw3 \
		libfftw3f.so:${PORTSDIR}/math/fftw3-float \
		liborc-0.4.so:${PORTSDIR}/devel/orc \
		libjson-c.so:${PORTSDIR}/devel/json-c \
		libdbus-1.so:${PORTSDIR}/devel/dbus \
		libltdl.so:${PORTSDIR}/devel/libltdl \
		libck-connector.so:${PORTSDIR}/sysutils/consolekit

USE_GNOME=	glib20 intltool
USE_XORG=	x11 sm xtst ice
USE_LDCONFIG=	yes
USES=		cpe execinfo gettext gmake libtool pathfix pkgconfig \
		shebangfix tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PTHREAD_LIBS="-lpthread" \
		OPENSSL_CFLAGS="-I/usr/include" \
		OPENSSL_LIBS="-lcrypto -lssl" \
		LIBS="-lm -lintl" \
		ac_cv_header_linux_input_h=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

SHEBANG_FILES=	shell-completion/bash/pulseaudio
bash_CMD=	${SETENV} bash
SUB_FILES=	pkg-message

CONFIGURE_ARGS=	--localstatedir=/var \
		--with-database=simple \
		--without-caps \
		--disable-udev \
		--disable-gtk3 \
		--disable-systemd \
		--disable-neon-opt \
		--disable-xen \
		--disable-lirc # untested

#FIXME --with-database=auto|tdb|gdbm|simple

USERS=		pulse
GROUPS=		pulse pulse-access pulse-rt

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	JACK AVAHI GCONF ALSA SIMD BASH ZSH
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
ZSH_CONFIGURE_OFF=	--without-zsh-completion-dir

PULSE_VERSION=	${PORTVERSION}
PLIST_SUB=	PULSE_VERSION=${PULSE_VERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/daemon/default.pa.in
	@${REINPLACE_CMD} -e 's|-Wmissing-include-dirs||g' \
		-e 's|/lib/dbus/machine-id|/db/dbus/machine-id|g' \
		${WRKSRC}/configure

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/pulse
.for ii in default.pa daemon.conf client.conf system.pa
	${INSTALL_DATA} ${WRKSRC}/src/${ii} \
		${STAGEDIR}${PREFIX}/etc/pulse/${ii}.sample
.endfor
post-install-BASH-off:
	@${RM} -rf ${STAGEDIR}${PREFIX}/etc/bash_completion.d

.include <bsd.port.mk>
