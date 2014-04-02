# $FreeBSD$

PORTNAME=	fldigi
PORTVERSION=	3.21.81
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.w1hkj.com/downloads/fldigi/\
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	db@FreeBSD.org
COMMENT=	Digital decoder for psk, cw, psk31, olivia

LICENSE=	GPLv3

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconf \
		asciidoc:${PORTSDIR}/textproc/asciidoc\
		docbook-xsl>=1.0:${PORTSDIR}/textproc/docbook-xsl\
		xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libsamplerate.so:${PORTSDIR}/audio/libsamplerate\
		libboost_system.so:${PORTSDIR}/devel/boost-libs\
		libfltk.so:${PORTSDIR}/x11-toolkits/fltk
USE_CXXSTD=	gnu++0x

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig compiler:c++11-lib
CONFIGURE_ENV=	FLTK_CONFIG="${LOCALBASE}/bin/fltk-config" \
		    EXTRA_LIBS="-lexecinfo"
MAN1=		fldigi.1 fldigi-shell.1

OPTIONS_DEFINE=	NATIVE_OPT FLARQ OSS SNDFILE PORTAUDIO PULSEAUDIO HAMLIB NLS

NATIVE_OPT_DESC=	Enable Native Optimizations
FLARQ_DESC=		Compile flarq
OSS_DESC=		Support OSS
SNDFILE_DESC=		Support for libsndfile
PORTAUDIO_DESC=		PortAudio support
PULSEAUDIO_DESC=	PulseAudio support
HAMLIB_DESC=		Support rig control via hamlib

OPTIONS_DEFAULT=	OPTFLARQ OPTOSS HAMLIB

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Fails to install
.endif
.if ${PORT_OPTIONS:MNATIVE_OPT}
CONFIGURE_ARGS+=--enable-optimizations=native
.else
CONFIGURE_ARGS+=--enable-optimizations=none
.endif
.if ${PORT_OPTIONS:MFLARQ}
CONFIGURE_ARGS+=--enable-flarq
MAN1+=		flarq.1
PLIST_SUB+=	FLARQ=""
.else
CONFIGURE_ARGS+=--disable-flarq
PLIST_SUB+=	FLARQ="@comment "
.endif
PLIST_SUB+=	XMLRPC=""
.if ${PORT_OPTIONS:MOSS}
CONFIGURE_ARGS+=--enable-oss
.else
CONFIGURE_ARGS+=--disable-oss
.endif
.if ${PORT_OPTIONS:MSNDFILE}
CONFIGURE_ARGS+=--with-sndfile
LIB_DEPENDS+=	sndfile:${PORTSDIR}/audio/libsndfile
.else
CONFIGURE_ARGS+=--without-sndfile
.endif
.if ${PORT_OPTIONS:MPORTAUDIO}
CONFIGURE_ARGS+=--with-portaudio
BUILD_DEPENDS+=	${LOCALBASE}/lib/portaudio2/libportaudio.so:${PORTSDIR}/audio/portaudio2
RUN_DEPENDS+=	${LOCALBASE}/lib/portaudio2/libportaudio.so:${PORTSDIR}/audio/portaudio2
.else
CONFIGURE_ARGS+=--without-portaudio
.endif
.if ${PORT_OPTIONS:MPULSEAUDIO}
CONFIGURE_ARGS+=--with-pulseaudio
LIB_DEPENDS+=	pulse:${PORTSDIR}/audio/pulseaudio
.else
CONFIGURE_ARGS+=--without-pulseaudio
.endif
.if ${PORT_OPTIONS:MHAMLIB}
CONFIGURE_ARGS+=--with-hamlib
LIB_DEPENDS+=	hamlib:${PORTSDIR}/comms/hamlib
.else
CONFIGURE_ARGS+=--without-hamlib
.endif
.if ${PORT_OPTIONS:MNLS}
USES+=	gettext
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif
# Always need asciidoc for man pages
CONFIGURE_ARGS+=--with-asciidoc

post-patch:
	@${REINPLACE_CMD} -e 's|png_infopp_NULL|NULL|' \
		 ${WRKSRC}/src/widgets/picture.cxx
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/Makefile.in

post-configure:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|' \
		-e 's|^CPPFLAGS|#CPPFLAGS|' \
		${WRKSRC}/src/Makefile
# force rebuild of man pages
	${RM} ${WRKSRC}/doc/*.1

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/guide.html ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>
