# $FreeBSD$

PORTNAME=	fldigi
PORTVERSION=	4.0.18
PORTREVISION=	2
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Digital decoder for psk, cw, psk31, olivia

LICENSE=	GPLv3

BUILD_DEPENDS=	asciidoc:textproc/asciidoc\
		docbook-xsl>=1.0:textproc/docbook-xsl\
		xsltproc:textproc/libxslt
LIB_DEPENDS=	libboost_system.so:devel/boost-libs\
		libpng.so:graphics/png \
		libfltk.so:x11-toolkits/fltk \
		libfontconfig.so:x11-fonts/fontconfig \
		libportaudio.so:audio/portaudio \
		libsndfile.so:audio/libsndfile \
		libsamplerate.so:audio/libsamplerate

USES=		autoreconf compiler:c++11-lib jpeg gmake perl5 pkgconfig shebangfix
USE_CXXSTD=	gnu++0x
GNU_CONFIGURE=	yes
USE_XORG=	x11 xft xext xfixes xcursor xinerama
CONFIGURE_ENV=	FLTK_CONFIG="${LOCALBASE}/bin/fltk-config" \
		    EXTRA_LIBS="-lexecinfo"

OPTIONS_DEFINE=	NATIVE_OPT FLARQ PULSEAUDIO HAMLIB NLS DOCS

NATIVE_OPT_DESC=	Enable Native Optimizations
FLARQ_DESC=		Compile flarq
PULSEAUDIO_DESC=	PulseAudio support
HAMLIB_DESC=		Support rig control via hamlib

OPTIONS_DEFAULT=	FLARQ HAMLIB
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
CONFIGURE_ARGS+=--with-asciidoc
# Upstream as of 4.0.5 always uses portaudio and sndfile now
# Which makes fldigi configure options portaudio & oss useless
CONFIGURE_ARGS+=--with-portaudio --disable-oss

post-configure:
# force rebuild of man pages
	${RM} ${WRKSRC}/doc/*.1

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/guide.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
