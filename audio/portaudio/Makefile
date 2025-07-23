PORTNAME=	portaudio
PORTVERSION=	19.6.0
PORTREVISION=	7
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.portaudio.com/archives/
DISTNAME=	pa_stable_v190600_20161030

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Portable cross-platform Audio API
WWW=		http://www.portaudio.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		autoreconf:2.69 cpe dos2unix gmake libtool localbase:ldflags \
		pkgconfig tar:tgz
USE_LDCONFIG=	yes
CPE_VENDOR=	portaudio_project

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking \
		--enable-cxx \
		--without-alsa
MAKE_ARGS=	EXAMPLES=""

MAKE_JOBS_UNSAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS DOXYGEN EXAMPLES JACK PATEST SNDIO
OPTIONS_SUB=	yes

SUB_FILES=	pkg-message

PATEST_DESC=	PortAudio Test Programs

DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_WITH=	jack

PATEST_MAKE_ARGS_OFF=	SELFTESTS="" \
			TESTS=""

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CONFIGURE_WITH=	sndio

post-extract:
	@${MKDIR} ${WRKSRC}/src/hostapi/sndio
	@${CP} ${FILESDIR}/pa_sndio.c ${WRKSRC}/src/hostapi/sndio

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libportaudio.so \
		${STAGEDIR}${PREFIX}/lib/libportaudiocpp.so
	${INSTALL_DATA} ${FILESDIR}/pa_unix_oss.h ${STAGEDIR}${PREFIX}/include

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README.txt index.html ${STAGEDIR}${DOCSDIR}

post-install-DOXYGEN-on:
	@cd ${WRKSRC} && doxygen
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/bindings/cpp/example/*.cxx \
		${WRKSRC}/examples/*.c ${WRKSRC}/examples/*.cpp \
		${WRKSRC}/src/os/unix/*.[ch] \
		${WRKSRC}/src/common/*.[ch] \
		${STAGEDIR}${EXAMPLESDIR}

post-install-PATEST-on:
.for f in pa_m* paqa_* patest*
	${STRIP_CMD} ${WRKSRC}/bin/.libs/${f}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/.libs/${f} ${STAGEDIR}${PREFIX}/bin/
.endfor

.include <bsd.port.mk>
