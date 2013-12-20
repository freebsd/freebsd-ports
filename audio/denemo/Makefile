# Created by: trevor
# $FreeBSD$

PORTNAME=	denemo
PORTVERSION=	1.1.0
CATEGORIES=	audio
MASTER_SITES=	GNU

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Graphical score editor

BUILD_DEPENDS=	portaudio2>0:${PORTSDIR}/audio/portaudio2
LIB_DEPENDS=	libaubio.so:${PORTSDIR}/audio/aubio \
		libfluidsynth.so:${PORTSDIR}/audio/fluidsynth \
		libjack.so:${PORTSDIR}/audio/jack \
		libsmf.so:${PORTSDIR}/audio/libsmf \
		libsndfile.so:${PORTSDIR}/audio/libsndfile \
		librubberband.so:${PORTSDIR}/audio/rubberband \
		libevview.so:${PORTSDIR}/graphics/evince \
		libguile.so:${PORTSDIR}/lang/guile \
		libfftw3.so:${PORTSDIR}/math/fftw3
RUN_DEPENDS=	portaudio2>0:${PORTSDIR}/audio/portaudio2 \
		xdg-open:${PORTSDIR}/devel/xdg-utils

LICENSE=	GPLv3

OPTIONS_DEFINE=	LILYPOND DOCS EXAMPLES
LILYPOND_DESC=	Install LilyPond (Printing)

USE_GNOME=	gtk20 gtksourceview2 librsvg2 libxml2
USES=		bison gmake pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gtk2 \
		--enable-jack \
		--disable-portmidi \
		--sysconfdir=${PREFIX}/etc

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
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for i in actions templates
	@(cd ${WRKSRC} && ${TAR} --exclude "*Makefile*" -cf - ${i}) | \
		(cd ${STAGEDIR}${DATADIR} && ${TAR} --unlink -xf -)
	@${FIND} ${STAGEDIR}${DATADIR}/${i} -print0 | \
		${XARGS} -0 ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@${FIND} ${STAGEDIR}${DATADIR}/${i} -type d -print0 | \
		${XARGS} -0 ${CHMOD} a+rx
	@${FIND} ${STAGEDIR}${DATADIR}/${i} -type f -print0 | \
		${XARGS} -0 ${CHMOD} ${SHAREMODE}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in AUTHORS ChangeLog NEWS README
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor
.for i in DESIGN DESIGN.lilypond GOALS TODO
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/manual
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} *.html \
		${STAGEDIR}${DOCSDIR}/manual)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/manual/images
	(cd ${WRKSRC}/doc/images && ${INSTALL_DATA} *.png \
		${STAGEDIR}${DOCSDIR}/manual/images)
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${INSTALL_DATA} *.denemo \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
