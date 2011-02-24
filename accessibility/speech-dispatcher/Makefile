# New ports collection makefile for:	speech-dispatcher
# Date created:				8 December 2009
# Whom:					Alberto Villa <villa.alberto@gmail.com>
#
# $FreeBSD$

PORTNAME=	speech-dispatcher
PORTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	accessibility audio
MASTER_SITES=	http://www.freebsoft.org/pub/projects/speechd/

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Common interface to speech synthesis

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	dotconf.0:${PORTSDIR}/devel/dotconf \
		sndfile.1:${PORTSDIR}/audio/libsndfile

USE_GNOME=	glib20 pkgconfig
MAKE_JOBS_SAFE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes
CFLAGS+=	-I${LOCALBASE}/include
USE_LDCONFIG=	${PREFIX}/lib ${PREFIX}/lib/${PORTNAME}

CONFFILES=	clients/emacs.conf clients/gnome-speech.conf \
		modules/cicero.conf modules/dtk-generic.conf \
		modules/epos-generic.conf modules/espeak-generic.conf \
		modules/espeak-mbrola-generic.conf modules/espeak.conf \
		modules/festival.conf modules/flite.conf modules/ibmtts.conf \
		modules/ivona.conf modules/llia_phon-generic.conf \
		modules/swift-generic.conf speechd.conf

PORTDOCS=	AUTHORS ChangeLog INSTALL NEWS README TODO

INFO=		spd-say ${PORTNAME} ssip

OPTIONS=	ALSA	"ALSA support" off \
		ESPEAK	"eSpeak output module" on \
		FESTIVAL	"Festival output module" off \
		FLITE	"Festival Lite output module" off \
		LIBAO	"libao support" off \
		NAS	"Network Audio System support" off \
		PULSEAUDIO	"PulseAudio support (broken on FreeBSD 6.X)" off \
		PYTHON	"Python support" off

.include <bsd.port.options.mk>

.ifdef(WITH_ALSA)
LIB_DEPENDS+=	asound.2:${PORTSDIR}/audio/alsa-lib
CONFIGURE_ARGS+=	--with-alsa
.else
CONFIGURE_ARGS+=	--without-alsa
.endif

.ifndef(WITHOUT_ESPEAK)
LIB_DEPENDS+=	espeak.1:${PORTSDIR}/audio/espeak
CONFIGURE_ARGS+=	--with-espeak
PLIST_SUB+=	ESPEAK=""
.else
CONFIGURE_ARGS+=	--without-espeak
PLIST_SUB+=	ESPEAK="@comment "
.endif

.ifdef(WITH_FESTIVAL)
RUN_DEPENDS+=	festival:${PORTSDIR}/audio/festival \
		${LOCALBASE}/share/festival/lib/${PORTNAME}.scm:${PORTSDIR}/audio/festival-freebsoft-utils
.endif

.ifdef(WITH_FLITE)
BUILD_DEPENDS+=	flite:${PORTSDIR}/audio/flite
RUN_DEPENDS+=	flite:${PORTSDIR}/audio/flite
CONFIGURE_ARGS+=	--with-flite
PLIST_SUB+=	FLITE=""
.else
CONFIGURE_ARGS+=	--without-flite
PLIST_SUB+=	FLITE="@comment "
.endif

.ifdef(WITH_LIBAO)
LIB_DEPENDS+=	ao.4:${PORTSDIR}/audio/libao
CONFIGURE_ARGS+=	--with-libao
.else
CONFIGURE_ARGS+=	--without-libao
.endif

.ifdef(WITH_NAS)
LIB_DEPENDS+=	audio.2:${PORTSDIR}/audio/nas
CONFIGURE_ARGS+=	--with-nas
.else
CONFIGURE_ARGS+=	--without-nas
.endif

.ifdef(WITH_PYTHON)
USE_PYTHON=	2.5+
CONFIGURE_ARGS+=	--enable-python
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=	--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_PULSEAUDIO) && ${OSVERSION} >= 700041
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
CONFIGURE_ARGS+=	--with-pulse
PLIST_SUB+=	GNOMEHIER="@comment "
.else
CONFIGURE_ARGS+=	--without-pulse
PLIST_SUB+=	GNOMEHIER=""
.endif

.if ${OSVERSION} < 800067 && ${ARCH} == "amd64"
CFLAGS+=	-fPIC
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

post-install:
.for f in ${CONFFILES}
	@if [ ! -f ${ETCDIR}/${f} ]; then \
		${CP} -p ${ETCDIR}/${f}.sample ${ETCDIR}/${f}; \
	fi
.endfor
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
