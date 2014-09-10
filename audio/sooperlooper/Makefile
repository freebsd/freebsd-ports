# Created by: mathias.picker@gmx.de
# $FreeBSD$

PORTNAME=	sooperlooper
PORTVERSION=	1.7.2
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://essej.net/sooperlooper/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Live audio looping sampler

LICENSE=	GPLv2

BUILD_DEPENDS=	ladspa>0:${PORTSDIR}/audio/ladspa
LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack \
		liblo.so:${PORTSDIR}/audio/liblo \
		libsamplerate.so:${PORTSDIR}/audio/libsamplerate \
		libsigc-2.0.so:${PORTSDIR}/devel/libsigc++20 \
		libsndfile.so:${PORTSDIR}/audio/libsndfile \
		librubberband.so:${PORTSDIR}/audio/rubberband \
		libvamp-sdk.so:${PORTSDIR}/audio/vamp-plugin-sdk \
		libfftw3.so:${PORTSDIR}/math/fftw3
RUN_DEPENDS=	ladspa>0:${PORTSDIR}/audio/ladspa

USES=		compiler:c++0x gmake ncurses pkgconfig
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CFLAGS+=	-Wno-error=write-strings
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		ALSA WXGTK
OPTIONS_DEFAULT=	WXGTK
OPTIONS_SUB=		yes

ALSA_LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib
ALSA_CONFIGURE_ENV_OFF=	ac_cv_header_alsa_asoundlib_h=no
WXGTK_USE=		WX=3.0
WXGTK_CONFIGURE_ON=	--with-wxconfig-path=${WX_CONFIG}
WXGTK_CONFIGURE_OFF=	--without-gui

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWXGTK}
WX_UNICODE=	yes
DESKTOP_ENTRIES="SooperLooper" "" "${DATADIR}/sl_logo.xpm" "slgui" \
		"AudioVideo;Audio;Player;GTK;" ""
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "configure" | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$OPT_FLAGS|$$CXXFLAGS| ; \
		 /^CXXFLAGS/s|-g|$$CXXFLAGS| ; \
		 s|-fo-merge-constants|| ; \
		 s|-lpthread|-pthread|'

post-install:
.if ${PORT_OPTIONS:MWXGTK}
	(cd ${WRKSRC}/src/gui/pixmaps && ${INSTALL_DATA} sl_logo.xpm \
		${STAGEDIR}${DATADIR})
.endif

.include <bsd.port.mk>
