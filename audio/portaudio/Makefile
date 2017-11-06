# Created by: michaelnottebrock@gmx.net and lioux@FreeBSD.org
# $FreeBSD$

PORTNAME=	portaudio
DISTVERSION=	19_20140130
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://www.portaudio.com/archives/
DISTNAME=	pa_stable_v${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable cross-platform Audio API

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=	autoreconf dos2unix gmake localbase:ldflags libtool pathfix \
	pkgconfig tar:tgz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	PKG_CONFIG_LIBDIR=${PREFIX}/libdata/pkgconfig \
		--without-alsa
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	*
PORTEXAMPLES=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	README.txt index.html

OPTIONS_DEFINE=	DOCS DOXYGEN EXAMPLES JACK PATEST SNDIO

PATEST_DESC=	PortAudio Test Programs
DOXYGEN_DESC=	Install API documentation (requires DOCS)

OPTIONS_SUB=	yes

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_WITH=	jack

PATEST_BIN=	pa_m* paqa_* patest*

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CONFIGURE_WITH=	sndio

DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

post-extract:
	@${MKDIR} ${WRKSRC}/src/hostapi/sndio
	@${CP} ${FILESDIR}/pa_sndio.c ${WRKSRC}/src/hostapi/sndio

post-patch:
	@${REINPLACE_CMD} -e 's|machine/soundcard.h|sys/soundcard.h|' ${WRKSRC}/configure.in \
		${WRKSRC}/src/hostapi/oss/pa_unix_oss.c ${WRKSRC}/src/SConscript
	@${REINPLACE_CMD} -e 's|PACKAGE_NAME=|PACKAGE_NAME=portaudio2|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -i '' '/EXAMPLES =/,/bin\/paex_write_sine_nonint/s/^/#/' \
		${WRKSRC}/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libportaudio.so

post-install-PATEST-on:
.for f in ${PATEST_BIN}
	${STRIP_CMD} ${WRKSRC}/bin/.libs/${f}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/.libs/${f} ${STAGEDIR}${PREFIX}/bin/
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}

post-install-DOXYGEN-on:
	@cd ${WRKSRC} && doxygen
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
