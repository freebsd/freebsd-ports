PORTNAME=	snd
DISTVERSION=	25.5
CATEGORIES=	audio
MASTER_SITES=	https://ccrma.stanford.edu/software/snd/ \
		SF

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Multitracking sound editor and utilities
WWW=		https://ccrma.stanford.edu/software/snd/

LICENSE=	snd
LICENSE_NAME=	snd license
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		localbase:ldflags

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-float-samples
MAKEFILE=	makefile
MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	snd snd-info sndplay

OPTIONS_DEFINE=		DOCS EXAMPLES FFTW3 GSL GTK2 LADSPA MOTIF S7 X11
OPTIONS_DEFAULT=	FFTW3 GSL GTK2 LADSPA X11
OPTIONS_SUB=		yes
FFTW3_DESC=		Use FFTW
GSL_DESC=		Use GNU Scientific Library
S7_DESC=		Use S7 as the extension language

FFTW3_LIB_DEPENDS=	libfftw3.so:math/fftw3
FFTW3_CONFIGURE_WITH=	fftw

GSL_LIB_DEPENDS=	libgsl.so:math/gsl
GSL_CONFIGURE_WITH=	gsl

GTK2_USES=		gnome
GTK2_USE=		GNOME=gtk20
GTK2_CONFIGURE_WITH=	gtk

LADSPA_BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
LADSPA_RUN_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
LADSPA_CONFIGURE_WITH=	ladspa

GTK2_USES=		gnome
GTK2_USE=		GNOME=gtk20
GTK2_CONFIGURE_WITH=	gtk

MOTIF_USES=		motif
MOTIF_CONFIGURE_WITH=	motif
S7_CONFIGURE_WITH=	s7

X11_CONFIGURE_ON=	--with-no-gui

post-patch:
	@${REINPLACE_CMD} -e 's|^ _Complex| Vaiolate _Complex|g ; \
		 s|-O2 -I|-I|g ; \
		 s|LDFLAGS -ldl|LDFLAGS|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|^sndinfo:|snd-info:|g ; \
		 s|-o sndinfo|-o snd-info|g' ${WRKSRC}/makefile.in

do-install:
.for i in snd snd-info sndplay
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/snd.1 ${STAGEDIR}${PREFIX}/share/man/man1/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in HISTORY.Snd README.Snd
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/*.html ${STAGEDIR}${DOCSDIR}/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/pix
	${INSTALL_DATA} ${WRKSRC}/pix/*.png ${STAGEDIR}${DOCSDIR}/pix

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/DotEmacs ${STAGEDIR}${EXAMPLESDIR}

do-install-S7-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.scm ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/tools
	${INSTALL_DATA} ${WRKSRC}/tools/*.scm ${STAGEDIR}${DATADIR}/tools
	@${MKDIR} ${STAGEDIR}${DATADIR}/sndins/samples
	${INSTALL_DATA} ${WRKSRC}/sndins/samples/*.scm ${STAGEDIR}${DATADIR}/sndins/samples

.include <bsd.port.mk>
