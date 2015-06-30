# $FreeBSD$

PORTNAME=	speech-dispatcher
PORTVERSION=	0.8.3
CATEGORIES=	accessibility audio
MASTER_SITES=	http://devel.freebsoft.org/pub/projects/speechd/

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Common interface to speech synthesis

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libdotconf.so:${PORTSDIR}/devel/dotconf \
		libltdl.so:${PORTSDIR}/devel/libltdl \
		libsndfile.so:${PORTSDIR}/audio/libsndfile

USE_GNOME=	glib20 intltool
USES=		alias gettext gmake pathfix pkgconfig libtool
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

ETCFILES=	clients/emacs.conf modules/pico-generic.conf \
		modules/cicero.conf modules/dtk-generic.conf \
		modules/epos-generic.conf modules/espeak-generic.conf \
		modules/espeak-mbrola-generic.conf modules/espeak.conf \
		modules/festival.conf modules/flite.conf modules/ibmtts.conf \
		modules/ivona.conf modules/llia_phon-generic.conf \
		modules/swift-generic.conf speechd.conf

PORTDOCS=	ANNOUNCE AUTHORS ChangeLog FAQ NEWS README TODO

INFO=		spd-say speech-dispatcher speech-dispatcher-cs ssip

OPTIONS_DEFINE=	ALSA AO DOCS ESPEAK FESTIVAL FLITE NAS \
		PULSEAUDIO PYTHON
OPTIONS_DEFAULT=ESPEAK
OPTIONS_SUB=	yes

ALSA_LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib
ALSA_CONFIGURE_WITH=	alsa

AO_LIB_DEPENDS=		libao.so:${PORTSDIR}/audio/libao
AO_CONFIGURE_WITH=	libao

ESPEAK_DESC=		eSpeak speech synthesizer support
ESPEAK_LIB_DEPENDS=	libespeak.so:${PORTSDIR}/audio/espeak
ESPEAK_CONFIGURE_WITH=	espeak

FESTIVAL_DESC=		Festival Speech Synthesis System support
FESTIVAL_RUN_DEPENDS=	festival:${PORTSDIR}/audio/festival \
			${LOCALBASE}/share/festival/lib/${PORTNAME}.scm:${PORTSDIR}/audio/festival-freebsoft-utils

FLITE_DESC=		Flite speech synthesis engine support
FLITE_LIB_DEPENDS=	libflite.so:${PORTSDIR}/audio/flite
FLITE_CONFIGURE_WITH=	flite

NAS_LIB_DEPENDS=	libaudio.so:${PORTSDIR}/audio/nas
NAS_CONFIGURE_WITH=	nas

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:${PORTSDIR}/audio/pulseaudio
PULSEAUDIO_CONFIGURE_WITH=pulse

PYTHON_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py3-xdg
PYTHON_USES=		python:3
PYTHON_USE=		PYTHON=py3kplist
PYTHON_CONFIGURE_ENABLE=python

post-patch:
	@${REINPLACE_CMD} -e '/SUBDIRS/ s/tests//' \
		${WRKSRC}/src/Makefile.in

post-install:
.for f in ${ETCFILES}
	@${MV} ${STAGEDIR}${ETCDIR}/${f} ${STAGEDIR}${ETCDIR}/${f}.sample
.endfor
	@${RM} -rf ${STAGEDIR}${DATADIR}/conf
	@${RMDIR} ${STAGEDIR}${DATADIR} || ${TRUE}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
