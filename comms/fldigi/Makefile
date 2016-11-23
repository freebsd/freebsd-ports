# $FreeBSD$

PORTNAME=	fldigi
PORTVERSION=	3.23.15
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Digital decoder for psk, cw, psk31, olivia

LICENSE=	GPLv3

BUILD_DEPENDS=	asciidoc:textproc/asciidoc\
		docbook-xsl>=1.0:textproc/docbook-xsl\
		xsltproc:textproc/libxslt
LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate\
		libboost_system.so:devel/boost-libs\
		libfltk.so:x11-toolkits/fltk

USE_CXXSTD=	gnu++0x
GNU_CONFIGURE=	yes
USES=		compiler:c++11-lib execinfo gmake perl5 pkgconfig shebangfix
CONFIGURE_ENV=	FLTK_CONFIG="${LOCALBASE}/bin/fltk-config" \
		    EXTRA_LIBS="-lexecinfo"

OPTIONS_DEFINE=	NATIVE_OPT FLARQ OSS SNDFILE PORTAUDIO PULSEAUDIO HAMLIB NLS DOCS

NATIVE_OPT_DESC=	Enable Native Optimizations
FLARQ_DESC=		Compile flarq
OSS_DESC=		Support OSS
SNDFILE_DESC=		Support for libsndfile
PORTAUDIO_DESC=		PortAudio support
PULSEAUDIO_DESC=	PulseAudio support
HAMLIB_DESC=		Support rig control via hamlib

OPTIONS_DEFAULT=	FLARQ OSS HAMLIB
OPTIONS_SUB=		yes

NATIVE_OPT_CONFIGURE_ON=	--enable-optimizations=native
NATIVE_OPT_CONFIGURE_OFF=	--enable-optimizations=none
FLARQ_CONFIGURE_ENABLE=		flarq
OSS_CONFIGURE_ENABLE=		oss
SNDFILE_CONFIGURE_WITH=		sndfile
SNDFILE_LIB_DEPENDS=		libsndfile.so:audio/libsndfile
PORTAUDIO_CONFIGURE_WITH=	portaudio
PORTAUDIO_LIB_DEPENDS=		libportaudio.so:audio/portaudio
PULSEAUDIO_CONFIGURE_WITH=	pulseaudio
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
HAMLIB_CONFIGURE_WITH=		hamlib
HAMLIB_LIB_DEPENDS=		libhamlib.so:comms/hamlib
NLS_CONFIGURE_ENABLE=		nls
NLS_USES=			gettext

# Always need asciidoc for man pages
CONFIGURE_ARGS+=--with-asciidoc

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/Makefile.in

post-configure:
	@${REINPLACE_CMD} -e 's|^CPPFLAGS|#CPPFLAGS|' \
		${WRKSRC}/src/Makefile
# force rebuild of man pages
	${RM} ${WRKSRC}/doc/*.1

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/guide.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
