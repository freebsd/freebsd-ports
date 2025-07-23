PORTNAME=	dssi
PORTVERSION=	1.1.1
PORTREVISION=	13
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	API for audio processing plugins
WWW=		https://dssi.sourceforge.net/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
LIB_DEPENDS=	libdssialsacompat.so:audio/libdssialsacompat \
		liblo.so:audio/liblo \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile \
		libjack.so:audio/jack
RUN_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa \
		${LOCALBASE}/include/alsa/seq_event.h:audio/alsa-lib

USES=		gmake pkgconfig localbase libtool xorg
USE_XORG=	x11

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PORTDOCS=	ChangeLog README

PORTEXAMPLES=	*
EXAMPLESSRCDIR=	${WRKSRC}/examples
EXAMPLES_FILES1=dssi_analyse_plugin dssi_list_plugins \
		dssi_osc_send dssi_osc_update
EXAMPLES_FILES2=LTS_qt trivial_sampler_qt

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
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
	@${REINPLACE_CMD} -e \
		'/QtCore >=/s|$$PKG_CONFIG|${FALSE}|' ${WRKSRC}/configure

post-install:
.for l in trivial_synth less_trivial_synth trivial_sampler karplong
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/dssi/${l}.so
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_PROGRAM} ${EXAMPLES_FILES1:S|^|${EXAMPLESSRCDIR}/|} \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
