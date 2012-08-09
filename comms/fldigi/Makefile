# New ports collection makefile for:	fldigi
# Date created:				December 20 2006
# Whom:					Diane Bruce <db@db.net>
#
# $FreeBSD$
#

PORTNAME=	fldigi
PORTVERSION=	3.21.50
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.w1hkj.com/downloads/fldigi/\
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	db@FreeBSD.org
COMMENT=	Digital decoder for psk, cw, psk31, olivia

LICENSE=	GPLv3

BUILD_DEPENDS=	asciidoc:${PORTSDIR}/textproc/asciidoc\
		xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	samplerate:${PORTSDIR}/audio/libsamplerate\
		fltk:${PORTSDIR}/x11-toolkits/fltk

GNU_CONFIGURE=	yes
USE_DOS2UNIX=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	FLTK_CONFIG="${LOCALBASE}/bin/fltk-config"
MAN1=		fldigi.1

OPTIONS_DEFINE=	NATIVE_OPT FLARQ XMLRPC OSS SNDFILE PORTAUDIO PULSEAUDIO HAMLIB

NATIVE_OPT_DESC=	Enable Native Optimizations
FLARQ_DESC=		Compile flarq
XMLRPC_DESC=		Support XMLrpc (fldigi-shell)
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
.if ${PORT_OPTIONS:MXMLRPC}
CONFIGURE_ARGS+=--with-xmlrpc
LIB_DEPENDS+=	xmlrpc:${PORTSDIR}/net/xmlrpc-c
PLIST_SUB+=	XMLRPC=""
MAN1+=		fldigi-shell.1
.else
CONFIGURE_ARGS+=--without-xmlrpc
PLIST_SUB+=	XMLRPC="@comment "
.endif
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
.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
USE_GETTEXT=	yes
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
.if	!defined(NOPORTDOCS)
	@${ECHO} ""
	${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/guide.html ${DOCSDIR}
	@${ECHO} "fldigi docs installed in ${DOCSDIR}"
	@${ECHO} ""
.endif

.include <bsd.port.post.mk>
