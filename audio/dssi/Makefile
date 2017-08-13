# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	dssi
PORTVERSION=	1.1.1
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	API for audio processing plugins

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
LIB_DEPENDS=	libdssialsacompat.so:audio/libdssialsacompat \
		liblo.so:audio/liblo \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile \
		libjack.so:audio/jack
RUN_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa

USES=		gmake pathfix pkgconfig localbase libtool
GNU_CONFIGURE=	yes
USE_XORG=	x11

PORTDOCS=	ChangeLog README

PORTEXAMPLES=	*
EXAMPLESSRCDIR=	${WRKSRC}/examples
EXAMPLES_FILES1=dssi_analyse_plugin dssi_list_plugins \
		dssi_osc_send dssi_osc_update
EXAMPLES_FILES2=LTS_qt trivial_sampler_qt

OPTIONS_DEFINE=	DOCS EXAMPLES QT4
OPTIONS_DEFAULT=QT4
OPTIONS_SUB=	yes

QT4_USE=	QT4=corelib,gui,moc_build
QT_NONSTANDARD=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		'/^lts_uidir/s|^|@HAVE_QT_TRUE@|; \
		/^trivial_sampler_uidir/s|^|@HAVE_QT_TRUE@|; \
		s|-ldl$$||' ${WRKSRC}/examples/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-ldl$$||' ${WRKSRC}/jack-dssi-host/Makefile.in
	@${REINPLACE_CMD} -e \
		'/alsa >=/s|$$PKG_CONFIG|${FALSE}|' ${WRKSRC}/configure

post-patch-QT4-off:
	@${REINPLACE_CMD} -e \
		'/QtCore >=/s|$$PKG_CONFIG|${FALSE}|' ${WRKSRC}/configure

post-install:
.for l in trivial_synth less_trivial_synth trivial_sampler karplong
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/dssi/${l}.so
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_PROGRAM} ${EXAMPLES_FILES1:S|^|${EXAMPLESSRCDIR}/|} \
		${STAGEDIR}${EXAMPLESDIR}

post-install-QT4-on:
	${INSTALL_PROGRAM} ${EXAMPLES_FILES2:S|^|${EXAMPLESSRCDIR}/|} \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
