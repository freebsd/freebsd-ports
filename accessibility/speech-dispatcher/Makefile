# $FreeBSD$

PORTNAME=	speech-dispatcher
PORTVERSION=	0.7.1
PORTREVISION=	3
CATEGORIES=	accessibility audio
MASTER_SITES=	http://www.freebsoft.org/pub/projects/speechd/

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Common interface to speech synthesis

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	dotconf:${PORTSDIR}/devel/dotconf \
		sndfile:${PORTSDIR}/audio/libsndfile

NO_STAGE=	yes
# gnomehier is required because of share/sounds directory.
USES=		gmake pkgconfig
USE_GNOME=	glib20 gnomehier
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	${PREFIX}/lib ${PREFIX}/lib/${PORTNAME}

ETCFILES=	clients/emacs.conf clients/gnome-speech.conf \
		modules/cicero.conf modules/dtk-generic.conf \
		modules/epos-generic.conf modules/espeak-generic.conf \
		modules/espeak-mbrola-generic.conf modules/espeak.conf \
		modules/festival.conf modules/flite.conf modules/ibmtts.conf \
		modules/ivona.conf modules/llia_phon-generic.conf \
		modules/swift-generic.conf speechd.conf

PLIST_SUB+=	ETCFILES="${ETCFILES}"

PORTDOCS=	AUTHORS ChangeLog INSTALL NEWS README TODO

INFO=		spd-say speech-dispatcher ssip

OPTIONS_DEFINE=	ALSA AO ESPEAK FESTIVAL FLITE NAS PULSEAUDIO PYTHON
OPTIONS_DEFAULT=ESPEAK

ESPEAK_DESC=	eSpeak output module
FESTIVAL_DESC=	Festival output module
FLITE_DESC=	Festival Lite output module

.include <bsd.port.options.mk>

.if ${OSVERSION} < 800067 && ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	asound:${PORTSDIR}/audio/alsa-lib
CONFIGURE_ARGS+=--with-alsa
.else
CONFIGURE_ARGS+=--without-alsa
.endif

.if ${PORT_OPTIONS:MAO}
LIB_DEPENDS+=	ao:${PORTSDIR}/audio/libao
CONFIGURE_ARGS+=--with-libao
.else
CONFIGURE_ARGS+=--without-libao
.endif

.if ${PORT_OPTIONS:MESPEAK}
LIB_DEPENDS+=	espeak:${PORTSDIR}/audio/espeak
CONFIGURE_ARGS+=--with-espeak
PLIST_SUB+=	ESPEAK=""
.else
CONFIGURE_ARGS+=--without-espeak
PLIST_SUB+=	ESPEAK="@comment "
.endif

.if ${PORT_OPTIONS:MFESTIVAL}
RUN_DEPENDS+=	festival:${PORTSDIR}/audio/festival \
		${LOCALBASE}/share/festival/lib/${PORTNAME}.scm:${PORTSDIR}/audio/festival-freebsoft-utils
.endif

.if ${PORT_OPTIONS:MFLITE}
BUILD_DEPENDS+=	flite:${PORTSDIR}/audio/flite
RUN_DEPENDS+=	flite:${PORTSDIR}/audio/flite
CONFIGURE_ARGS+=--with-flite
PLIST_SUB+=	FLITE=""
.else
CONFIGURE_ARGS+=--without-flite
PLIST_SUB+=	FLITE="@comment "
.endif

.if ${PORT_OPTIONS:MNAS}
LIB_DEPENDS+=	audio:${PORTSDIR}/audio/nas
CONFIGURE_ARGS+=--with-nas
.else
CONFIGURE_ARGS+=--without-nas
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	pulse:${PORTSDIR}/audio/pulseaudio
CONFIGURE_ARGS+=--with-pulse
.else
CONFIGURE_ARGS+=--without-pulse
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	-2.7
CONFIGURE_ARGS+=--enable-python
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's/-pthread/${PTHREAD_LIBS}/g' \
		${WRKSRC}/ltmain.sh
	${REINPLACE_CMD} -e 's/-lpthread/${PTHREAD_LIBS}/g' \
		${WRKSRC}/configure \
		${WRKSRC}/src/audio/Makefile.in \
		${WRKSRC}/src/c/api/Makefile.in \
		${WRKSRC}/src/c/clients/spdsend/Makefile.in \
		${WRKSRC}/src/modules/Makefile.in \
		${WRKSRC}/src/server/Makefile.in
	${REINPLACE_CMD} -e '/SUBDIRS/ s/tests//' \
		${WRKSRC}/src/Makefile.in

post-install:
.for f in ${ETCFILES}
	@if [ ! -f ${ETCDIR}/${f} ]; then \
		${CP} -p ${ETCDIR}/${f}.sample ${ETCDIR}/${f}; \
	fi
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
