# $FreeBSD$

PORTNAME=	gsequencer
DISTVERSION=	2.4.3
CATEGORIES=	audio
MASTER_SITES=	SAVANNAH/gsequencer/${DISTVERSION:R}.x

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Advanced Gtk+ sequencer

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	dssi>0:audio/dssi \
		lv2>0:audio/lv2
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libfftw3.so:math/fftw3 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libinstpatch-1.0.so:audio/libinstpatch \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile \
		libuuid.so:misc/e2fsprogs-libuuid
RUN_DEPENDS=	dssi>0:audio/dssi

USES=		desktop-file-utils gettext-runtime gmake gnome libtool localbase pkgconfig shared-mime-info xorg
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-alsa --enable-oss --enable-threads=posix --without-included-regex
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 libxml2 pango
USE_XORG=	x11
USE_GCC=	yes # the project uses gnu99 extensions, clang fails even with USE_CSTD=gnu99. Suggestions how to build with clang are welcome.
USE_CSTD=	gnu99
USE_LDCONFIG=	yes

CPPFLAGS+=	-DAGS_LICENSE_FILENAME=\\\"${LOCALBASE}/share/licenses/${PKGNAME}/${LICENSE}\\\" \
		-DAGS_LOGO_FILENAME=\\\"${DATADIR}/images/ags.png\\\" # there should be no need to supply AGS_LOGO_FILENAME here since the app knows its location
LDFLAGS+=	-luuid

INSTALL_TARGET=	install-strip
INSTALLS_ICONS=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=			JACK PULSEAUDIO

JACK_CONFIGURE_ENABLE=		jack
JACK_LIB_DEPENDS=		libjack.so:audio/jack

PULSEAUDIO_CONFIGURE_ENABLE=	pulse
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio

post-install:
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/doc-base

.include <bsd.port.mk>
