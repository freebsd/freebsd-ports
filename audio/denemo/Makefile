# New ports collection makefile for:	denemo
# Date created:				2001-02-24
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	denemo
PORTVERSION=	0.8.14
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SAVANNAH

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Graphical score editor

BUILD_DEPENDS=	portaudio>=19:${PORTSDIR}/audio/portaudio2
LIB_DEPENDS=	aubio.3:${PORTSDIR}/audio/aubio \
		fluidsynth.4:${PORTSDIR}/audio/fluidsynth \
		jack.0:${PORTSDIR}/audio/jack \
		guile.20:${PORTSDIR}/lang/guile \
		fftw3.5:${PORTSDIR}/math/fftw3
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GNOME=	gtk20 gtksourceview2 librsvg2 libxml2
USE_BISON=	build
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-jack \
		--sysconfdir=${PREFIX}/etc

PORTDOCS=	*
PORTEXAMPLES=	*

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.else
USE_GETTEXT=		yes
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=		NLS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|m4 doc actions|m4 actions| ; \
		 s|fonts examples templates|fonts templates|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/<malloc.h>/d' ${WRKSRC}/src/lyparser.y

post-install:
	@${LN} -sf ${DOCSDIR}/manual ${DATADIR}/manual
	@${LN} -sf ${EXAMPLESDIR} ${DATADIR}/examples
.if !defined(NOPORTDOCS)
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
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.denemo ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
