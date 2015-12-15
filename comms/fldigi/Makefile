# $FreeBSD$

PORTNAME=	fldigi
PORTVERSION=	3.23.03
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.w1hkj.com/downloads/fldigi/\
		LOCAL/db

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Digital decoder for psk, cw, psk31, olivia

LICENSE=	GPLv3

BUILD_DEPENDS=	asciidoc:${PORTSDIR}/textproc/asciidoc\
		docbook-xsl>=1.0:${PORTSDIR}/textproc/docbook-xsl\
		xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	libsamplerate.so:${PORTSDIR}/audio/libsamplerate\
		libboost_system.so:${PORTSDIR}/devel/boost-libs\
		libfltk.so:${PORTSDIR}/x11-toolkits/fltk

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
SNDFILE_LIB_DEPENDS=		libsndfile.so:${PORTSDIR}/audio/libsndfile
PORTAUDIO_CONFIGURE_WITH=	portaudio
PORTAUDIO_LIB_DEPENDS=		libportaudio.so:${PORTSDIR}/audio/portaudio
PULSEAUDIO_CONFIGURE_WITH=	pulseaudio
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:${PORTSDIR}/audio/pulseaudio
HAMLIB_CONFIGURE_WITH=		hamlib
HAMLIB_LIB_DEPENDS=		libhamlib.so:${PORTSDIR}/comms/hamlib
NLS_CONFIGURE_ENABLE=		nls
NLS_USES=			gettext

BROKEN_sparc64=		Fails to install
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
