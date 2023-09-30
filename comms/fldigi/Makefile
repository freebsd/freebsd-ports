PORTNAME=	fldigi
DISTVERSION=	4.2.03
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/fldigi/${PORTNAME} \
		http://www.w1hkj.com/files/fldigi/

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Digital decoder for psk, cw, psk31, olivia
WWW=		http://www.w1hkj.com

LICENSE=	GPLv3

BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
		docbook-xsl>=1.0:textproc/docbook-xsl \
		xsltproc:textproc/libxslt
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libfltk.so:x11-toolkits/fltk \
		libfontconfig.so:x11-fonts/fontconfig \
		libpng.so:graphics/png \
		libportaudio.so:audio/portaudio \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile \
		libudev.so:devel/libudev-devd

USES=		autoreconf compiler:c++11-lib desktop-file-utils gmake jpeg \
		perl5 pkgconfig shebangfix xorg

USE_CXXSTD=	gnu++0x
GNU_CONFIGURE=	yes
USE_XORG=	x11 xcursor xext xfixes xft xinerama xrender
CONFIGURE_ENV=	EXTRA_LIBS="-lexecinfo" \
		FLTK_CONFIG="${LOCALBASE}/bin/fltk-config"

OPTIONS_DEFINE=	DOCS FLARQ HAMLIB NLS OSS PULSEAUDIO

NATIVE_OPT_DESC=	Enable Native Optimizations
FLARQ_DESC=		Compile flarq
OSS_DESC=		Support OSS
PULSEAUDIO_DESC=	PulseAudio support
HAMLIB_DESC=		Support rig control via hamlib

OPTIONS_DEFAULT=	FLARQ HAMLIB OSS
OPTIONS_SUB=		yes

NATIVE_OPT_CONFIGURE_ON=	--enable-optimizations=native
NATIVE_OPT_CONFIGURE_OFF=	--enable-optimizations=none
FLARQ_CONFIGURE_ENABLE=		flarq
OSS_CONFIGURE_ENABLE=		oss
PULSEAUDIO_CONFIGURE_WITH=	pulseaudio
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
HAMLIB_CONFIGURE_WITH=		hamlib
HAMLIB_LIB_DEPENDS=		libhamlib.so:comms/hamlib
NLS_CONFIGURE_ENABLE=		nls
NLS_USES=			gettext

# Always need asciidoc for man pages
CONFIGURE_ARGS+=	--with-asciidoc
# Always need soundfile
CONFIGURE_ARGS+=	--with-sndfile

post-configure:
# force rebuild of man pages
	${RM} ${WRKSRC}/doc/*.1

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/guide.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
