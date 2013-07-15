# Created by: trevor
# $FreeBSD$

PORTNAME=	denemo
PORTVERSION=	1.0.4
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
RUN_DEPENDS=	portaudio>=19:${PORTSDIR}/audio/portaudio2 \
		xdg-open:${PORTSDIR}/devel/xdg-utils

LICENSE=	GPLv3

OPTIONS_DEFINE=	LILYPOND DOCS EXAMPLES
LILYPOND_DESC=	Install LilyPond (Printing)

USE_GNOME=	gtk20 gtksourceview2 librsvg2 libxml2
USES=		bison gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gtk2 \
		--enable-jack \
		--disable-portmidi \
		--sysconfdir=${PREFIX}/etc
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include/portaudio2 \
		-I${LOCALBASE}/include
LDFLAGS+=	${LOCALBASE}/lib/portaudio2/libportaudio.so \
		-L${LOCALBASE}/lib

LILYPOND_RUN_DEPENDS=	lilypond:${PORTSDIR}/print/lilypond

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		'/^CFLAGS=/s|_LIBS|_CFLAGS| ; \
		 s|-lpthread|-pthread|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|doc|| ; \
		 /) install-data-hook/s|^|#|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|"firefox"|"xdg-open"|' ${WRKSRC}/src/prefops.c

post-install:
	@${MKDIR} ${DATADIR}
.for i in actions templates
	@(cd ${WRKSRC} && ${TAR} --exclude "*Makefile*" -cf - ${i}) | \
		(cd ${DATADIR} && ${TAR} --unlink -xf -)
	@${FIND} ${DATADIR}/${i} -print0 | \
		${XARGS} -0 ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@${FIND} ${DATADIR}/${i} -type d -print0 | \
		${XARGS} -0 ${CHMOD} a+rx
	@${FIND} ${DATADIR}/${i} -type f -print0 | \
		${XARGS} -0 ${CHMOD} ${SHAREMODE}
.endfor
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
