# New ports collection makefile for:	speech-dispatcher
# Date created:				8 December 2009
# Whom:					Alberto Villa <villa.alberto@gmail.com>
#
# $FreeBSD$

PORTNAME=	speech-dispatcher
PORTVERSION=	0.6.7
PORTREVISION=	1
CATEGORIES=	accessibility audio
MASTER_SITES=	http://www.freebsoft.org/pub/projects/speechd/

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Common interface to speech synthesis

LIB_DEPENDS=	dotconf.0:${PORTSDIR}/devel/dotconf

SUB_FILES=	pkg-message

USE_RC_SUBR=	speechd
USE_GNOME=	glib20 pkgconfig
MAKE_JOBS_SAFE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--without-ibmtts --without-alsa --without-ivona
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

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

INFO=		spd-say ${PORTNAME}-cs ${PORTNAME} ssip

OPTIONS=	ESPEAK	"eSpeak output module" on \
		FESTIVAL	"Festival output module" off \
		NAS	"Network Audio System support" off \
		PULSEAUDIO	"PulseAudio support" off

# no *.so library installed to link to
#FLITE	"Festival Lite output module" off \

.include <bsd.port.pre.mk>

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

#.ifdef(WITH_FLITE)
#BUILD_DEPENDS+=	flite:${PORTSDIR}/audio/flite
#RUN_DEPENDS+=	flite:${PORTSDIR}/audio/flite
#CONFIGURE_ARGS+=	--with-flite
#PLIST_SUB+=	FLITE=""
#.else
CONFIGURE_ARGS+=	--without-flite
PLIST_SUB+=	FLITE="@comment "
#.endif

.ifdef(WITH_NAS)
LIB_DEPENDS+=	audio.2:${PORTSDIR}/audio/nas
CONFIGURE_ARGS+=	--with-nas
.else
CONFIGURE_ARGS+=	--without-nas
.endif

.ifdef(WITH_PULSEAUDIO)
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
CONFIGURE_ARGS+=	--with-pulseaudio
.else
CONFIGURE_ARGS+=	--without-pulseaudio
.endif

.if ${OSVERSION} < 800067
.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif
EXTRA_PATCHES=	${FILESDIR}/extrapatch-*
.endif

post-extract:
.if ${OSVERSION} < 800067
	${CP} ${FILESDIR}/getline.h ${WRKSRC}/src
.if ${OSVERSION} < 701101
	${CP} ${FILESDIR}/getline_strndup.c ${WRKSRC}/src/freebsd.c
.else
	${CP} ${FILESDIR}/getline.c ${WRKSRC}/src/freebsd.c
.endif
.endif

post-patch:
.if ${OSVERSION} < 700042
	@${REINPLACE_CMD} -E -e 's/^(LDFLAGS =.+)/\1 ${PTHREAD_LIBS}/' \
		${WRKSRC}/src/c/clients/say/Makefile.in \
		${WRKSRC}/src/tests/Makefile.in
.endif
	@${REINPLACE_CMD} -e 's/-pthread/${PTHREAD_LIBS}/g' \
		${WRKSRC}/ltmain.sh
	@${REINPLACE_CMD} -e 's/-lpthread/${PTHREAD_LIBS}/g' \
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
