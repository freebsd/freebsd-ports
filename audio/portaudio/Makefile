# Created by: michaelnottebrock@gmx.net and lioux@FreeBSD.org
# $FreeBSD$

PORTNAME=	portaudio
DISTVERSION=	19_20140130
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.portaudio.com/archives/
DISTNAME=	pa_stable_v${DISTVERSION}

MAINTAINER=	koalative@gmail.com
COMMENT=	Portable cross-platform Audio API

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		dos2unix gmake libtool pathfix pkgconfig tar:tgz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=PKG_CONFIG_LIBDIR=${PREFIX}/libdata/pkgconfig \
			--without-alsa
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	*
PORTEXAMPLES=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	README.txt index.html

OPTIONS_DEFINE=	DOCS DOXYGEN EXAMPLES JACK PATEST
OPTIONS_DEFAULT=PATEST

PATEST_DESC=	PortAudio Test Programs
DOXYGEN_DESC=	Install API documentation (requires DOCS)

OPTIONS_SUB=	yes

JACK_LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack
JACK_CONFIGURE_ON=	--with-jack
JACK_CONFIGURE_OFF=	--without-jack

EXAMPLES_BIN=	pa_d* pa_f* paex_*
PATEST_BIN=	pa_m* paqa_* patest*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOXYGEN} && ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|machine/soundcard.h|sys/soundcard.h|' ${WRKSRC}/configure.in \
		${WRKSRC}/src/hostapi/oss/pa_unix_oss.c ${WRKSRC}/src/SConscript
	@${REINPLACE_CMD} -e 's|PACKAGE_NAME=|PACKAGE_NAME=portaudio2|' ${WRKSRC}/configure

.if ! ${PORT_OPTIONS:MEXAMPLES}
	@${REINPLACE_CMD} -i '' '/EXAMPLES =/,/bin\/paex_write_sine_nonint/s/^/#/' \
		${WRKSRC}/Makefile.in
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libportaudio.so.2

.if ${PORT_OPTIONS:MEXAMPLES}
.for f in ${EXAMPLES_BIN}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${STAGEDIR}${PREFIX}/bin/
.endfor
.endif

.if ${PORT_OPTIONS:MPATEST}
.for f in ${PATEST_BIN}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${STAGEDIR}${PREFIX}/bin/
.endfor
.endif

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MDOXYGEN} && ${PORT_OPTIONS:MDOCS}
	@cd ${WRKSRC} && doxygen
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})
.endif 

.if ${PORT_OPTIONS:MEXAMPLES}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
