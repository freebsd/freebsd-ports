# $FreeBSD$

PORTNAME=	speech-dispatcher
DISTVERSION=	0.8.8
CATEGORIES?=	accessibility audio
MASTER_SITES=	http://devel.freebsoft.org/pub/projects/speechd/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT?=	Common interface to speech synthesis

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libdotconf.so:devel/dotconf \
		libltdl.so:devel/libltdl \
		libsndfile.so:audio/libsndfile

USES=		alias gettext gmake gnome libtool pathfix pkgconfig
USE_GNOME=	glib20 intltool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-espeak-ng
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.if !defined(SPEECH_SLAVE)

CONFIGURE_ARGS+=	--disable-python

ETCFILES=	clients/emacs.conf modules/cicero.conf modules/dtk-generic.conf \
		modules/epos-generic.conf modules/espeak-generic.conf \
		modules/espeak-mbrola-generic.conf modules/espeak-ng.conf \
		modules/espeak.conf modules/festival.conf modules/flite.conf \
		modules/ibmtts.conf modules/ivona.conf \
		modules/llia_phon-generic.conf modules/pico-generic.conf \
		modules/swift-generic.conf speechd.conf

PORTDOCS=	ANNOUNCE AUTHORS FAQ NEWS README TODO

INFO=		spd-say speech-dispatcher speech-dispatcher-cs ssip

OPTIONS_DEFINE=		ALSA AO DOCS ESPEAK FESTIVAL FLITE NAS PULSEAUDIO
OPTIONS_DEFAULT=	ESPEAK
OPTIONS_SUB=		yes

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_WITH=	alsa

AO_LIB_DEPENDS=		libao.so:audio/libao
AO_CONFIGURE_WITH=	libao

ESPEAK_DESC=		eSpeak speech synthesizer support
ESPEAK_LIB_DEPENDS=	libespeak.so:audio/espeak
ESPEAK_CONFIGURE_WITH=	espeak

FESTIVAL_DESC=		Festival Speech Synthesis System support
FESTIVAL_RUN_DEPENDS=	${LOCALBASE}/share/festival/lib/${PORTNAME}.scm:audio/festival-freebsoft-utils \
			festival:audio/festival

FLITE_DESC=		Flite speech synthesis engine support
FLITE_LIB_DEPENDS=	libflite.so:audio/flite
FLITE_CONFIGURE_WITH=	flite

NAS_LIB_DEPENDS=	libaudio.so:audio/nas
NAS_CONFIGURE_WITH=	nas

PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_WITH=	pulse

post-patch:
	${REINPLACE_CMD} -e 's,/usr/share,${PREFIX}/share,g' \
		${WRKSRC}/src/modules/*.c \
		${WRKSRC}/config/modules/*.conf

post-install:
.for f in ${ETCFILES}
	@${MV} ${STAGEDIR}${ETCDIR}/${f} ${STAGEDIR}${ETCDIR}/${f}.sample
.endfor
	@${RM} -r ${STAGEDIR}${DATADIR}/conf
	@${RMDIR} ${STAGEDIR}${DATADIR} || ${TRUE}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.else

PORTSCOUT=	ignore:1

NO_ARCH=	yes
USES+=		python:3.3+ shebangfix
SHEBANG_FILES=	src/api/python/speechd_config/spd-conf
USE_PYTHON=	flavors
LIB_DEPENDS+=	libspeechd.so:accessibility/speech-dispatcher
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/xdg/__init__.py:devel/py-xdg@${PY_FLAVOR}

.endif

.include <bsd.port.mk>
