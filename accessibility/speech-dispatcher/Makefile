PORTNAME=	speech-dispatcher
DISTVERSION=	0.12.1
CATEGORIES?=	accessibility audio
MASTER_SITES=	https://github.com/brailcom/speechd/releases/download/${PORTVERSION}/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT?=	Common interface to speech synthesis
WWW=		https://devel.freebsoft.org/speechd

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	help2man:misc/help2man
LIB_DEPENDS=	libdotconf.so:devel/dotconf \
		libsndfile.so:audio/libsndfile

USES=		gettext gmake gnome libtool localbase makeinfo \
		pkgconfig
USE_GNOME=	glib20 intltool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-ltdl \
		--with-espeak-ng=no \
		--with-baratinoo=no \
		--with-kali=no \
		--with-ibmtts=no \
		--with-oss \
		--with-voxin=no \
		--without-systemdsystemunitdir
INSTALL_TARGET=	install-strip

.if !defined(_SD_PYTHON)

CONFIGURE_ARGS+=--disable-python
TEST_TARGET=	check
TEST_WRKSRC=	${WRKSRC}/src/tests

INFO=		spd-say speech-dispatcher speech-dispatcher-cs ssip
PORTDOCS=	ANNOUNCE AUTHORS FAQ NEWS README* TODO

OPTIONS_DEFINE=		ALSA AO DOCS ESPEAK FESTIVAL FLITE NAS PIPEWIRE \
			PULSEAUDIO
OPTIONS_DEFAULT=	ESPEAK PULSEAUDIO
OPTIONS_SUB=		yes

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_WITH=	alsa

AO_LIB_DEPENDS=		libao.so:audio/libao
AO_CONFIGURE_WITH=	libao

ESPEAK_LIB_DEPENDS=	libespeak-ng.so:audio/espeak-ng
ESPEAK_CONFIGURE_WITH=	espeak

FESTIVAL_DESC=		Festival Speech Synthesis System support
FESTIVAL_RUN_DEPENDS=	${LOCALBASE}/share/festival/lib/${PORTNAME}.scm:audio/festival-freebsoft-utils \
			festival:audio/festival

FLITE_DESC=		Flite speech synthesis engine support
FLITE_LIB_DEPENDS=	libflite.so:audio/flite
FLITE_CONFIGURE_WITH=	flite

NAS_LIB_DEPENDS=	libaudio.so:audio/nas
NAS_USES=		xorg
NAS_USE=		XORG=xau
NAS_CONFIGURE_WITH=	nas

PIPEWIRE_LIB_DEPENDS=		libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_CONFIGURE_WITH=	pipewire

PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_WITH=	pulse

_SD_ETCFILES=	clients/emacs.conf \
		modules/cicero.conf \
		modules/dtk-generic.conf \
		modules/epos-generic.conf \
		modules/espeak-mbrola-generic.conf \
		modules/espeak-ng-mbrola-generic.conf \
		modules/espeak-ng-mbrola.conf \
		modules/espeak-ng.conf \
		modules/espeak.conf \
		modules/festival.conf \
		modules/flite.conf \
		modules/llia_phon-generic.conf \
		modules/mary-generic.conf \
		modules/mimic3-generic.conf \
		modules/openjtalk.conf \
		modules/swift-generic.conf \
		speechd.conf

.  include <bsd.port.options.mk>

post-patch:
# ibmtts.c is omitted, because it is disabled by default
.  for f in espeak.c generic.c ivona.c openjtalk.c pico.c
	${REINPLACE_CMD} -e 's|/usr/share|${LOCALBASE}/share|g' \
		${WRKSRC}/src/modules/${f}
.  endfor
	${REINPLACE_CMD} -e 's|/etc|${LOCALBASE}/etc|g ; \
		s|/usr/bin|${LOCALBASE}/bin|g ; \
		s|/usr/share|${LOCALBASE}/share|g' \
		${WRKSRC}/config/modules/*.conf

post-install:
.  for f in ${_SD_ETCFILES}
	@${MV} ${STAGEDIR}${ETCDIR}/${f} ${STAGEDIR}${ETCDIR}/${f}.sample
.  endfor
	@${RM} -r ${STAGEDIR}${DATADIR}/conf
	@${RMDIR} ${STAGEDIR}${DATADIR} || ${TRUE}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

# The 'test' target only builds the tests. The speech-dispatcher tests, in
# whole, are not easily automated. This is only intended to provide a minimal
# baseline. If you don't hear some robotic voices coming out of your speakers
# after running the 'test' target, something is definitely wrong.
post-test:
	@if [ "`${LOCALBASE}/bin/speech-dispatcher -v | head -1`" != "${PORTNAME} ${DISTVERSION}" ]; then \
		${ECHO_CMD} "===> Tests require a local installation of ${PKGNAME} to"; \
		${ECHO_CMD} "     proceed. Try reinstalling ${PKGNAME} and running the"; \
		${ECHO_CMD} "     'test' target again."; \
		exit 1; \
	else \
		${ECHO_CMD} "===> Testing with locally installed `${LOCALBASE}/bin/speech-dispatcher -v | head -1`" ; \
		${LOCALBASE}/bin/speech-dispatcher && ${TEST_WRKSRC}/run_test ${TEST_WRKSRC}/basic.test; \
	fi

.else

BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}xdg>0:devel/py-xdg@${PY_FLAVOR}
LIB_DEPENDS+=	libspeechd.so:accessibility/speech-dispatcher
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}xdg>0:devel/py-xdg@${PY_FLAVOR}

USES+=		python shebangfix
USE_PYTHON=	flavors

SHEBANG_FILES=	src/api/python/speechd_config/spd-conf

NO_ARCH=	yes
PORTSCOUT=	ignore:1

.endif

.include <bsd.port.mk>
