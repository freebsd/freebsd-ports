# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	dssi
PORTVERSION=	1.1.1
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	API for audio processing plugins

LICENSE=	LGPL21

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
LIB_DEPENDS=	libdssialsacompat.so:audio/libdssialsacompat \
		liblo.so:audio/liblo \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile \
		libjack.so:audio/jack
RUN_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa

USES=		gmake pathfix pkgconfig libtool
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	ChangeLog README

PORTEXAMPLES=	*

EXAMPLESSRCDIR=		${WRKSRC}/examples

EXAMPLES_FILES1=	dssi_analyse_plugin dssi_list_plugins \
			dssi_osc_send dssi_osc_update

EXAMPLES_FILES2=	LTS_qt trivial_sampler_qt

OPTIONS_DEFINE=	DOCS EXAMPLES QT4
OPTIONS_DEFAULT=	QT4

OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQT4}
USE_QT4=	corelib gui moc_build
QT_NONSTANDARD=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^lts_uidir/s|^|@HAVE_QT_TRUE@|; \
		/^trivial_sampler_uidir/s|^|@HAVE_QT_TRUE@|; \
		s|-ldl$$||' ${WRKSRC}/examples/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-ldl$$||' ${WRKSRC}/jack-dssi-host/Makefile.in
	@${REINPLACE_CMD} -e \
		'/alsa >=/s|$$PKG_CONFIG|${FALSE}|' ${WRKSRC}/configure

.if ! ${PORT_OPTIONS:MQT4}
	@${REINPLACE_CMD} -e \
		'/QtCore >=/s|$$PKG_CONFIG|${FALSE}|' ${WRKSRC}/configure
.endif

post-install:
.for l in trivial_synth less_trivial_synth trivial_sampler karplong
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/dssi/${l}.so
.endfor

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_PROGRAM} ${EXAMPLES_FILES1:S|^|${EXAMPLESSRCDIR}/|} \
		${STAGEDIR}${EXAMPLESDIR}

.if ${PORT_OPTIONS:MQT4}
	${INSTALL_PROGRAM} ${EXAMPLES_FILES2:S|^|${EXAMPLESSRCDIR}/|} \
		${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
