# Created by: trevor
# $FreeBSD$

PORTNAME=	denemo
PORTVERSION=	0.9.6
CATEGORIES=	audio
MASTER_SITES=	GNU

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Graphical score editor

BUILD_DEPENDS=	portaudio>=19:${PORTSDIR}/audio/portaudio2
LIB_DEPENDS=	aubio:${PORTSDIR}/audio/aubio \
		fluidsynth:${PORTSDIR}/audio/fluidsynth \
		jack:${PORTSDIR}/audio/jack \
		smf:${PORTSDIR}/audio/libsmf \
		sndfile:${PORTSDIR}/audio/libsndfile \
		evview:${PORTSDIR}/graphics/evince \
		guile:${PORTSDIR}/lang/guile \
		fftw3:${PORTSDIR}/math/fftw3
RUN_DEPENDS=	portaudio>=19:${PORTSDIR}/audio/portaudio2

LICENSE=	GPLv3

OPTIONS_DEFINE=	LILYPOND DOCS EXAMPLES
LILYPOND_DESC=	Install LilyPond (Printing)

USE_GNOME=	gtk20 gtksourceview2 librsvg2 libxml2
USE_BISON=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-jack \
		--disable-portmidi \
		--sysconfdir=${PREFIX}/etc
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include/portaudio2 \
		-I${LOCALBASE}/include
LDFLAGS+=	${LOCALBASE}/lib/portaudio2/libportaudio.so \
		-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLILYPOND}
RUN_DEPENDS+=	lilypond:${PORTSDIR}/print/lilypond
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|evince-view-2.30|evince-view-2.32|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|doc|| ; \
		 /\/examples/d' ${WRKSRC}/Makefile.in

post-install:
	@${LN} -sf ${DOCSDIR}/manual ${DATADIR}/manual
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in AUTHORS ChangeLog NEWS README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.for i in DESIGN DESIGN.lilypond GOALS TODO
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
	@${MKDIR} ${DOCSDIR}/manual
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}/manual
	@${MKDIR} ${DOCSDIR}/manual/images
	${INSTALL_DATA} ${WRKSRC}/doc/images/*.png ${DOCSDIR}/manual/images
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.denemo ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
