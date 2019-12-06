# Created by: trevor
# $FreeBSD$

PORTNAME=	snd
PORTVERSION=	15.7
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	ftp://ccrma-ftp.stanford.edu/pub/Lisp/ \
		SF

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Multitracking sound editor and utilities

LICENSE=	snd
LICENSE_NAME=	snd license
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

OPTIONS_DEFINE=	FFTW3 GSL S7 LADSPA MOTIF GTK2 X11 DOCS EXAMPLES
OPTIONS_DEFAULT=	FFTW3 GSL LADSPA GTK2 X11
FFTW3_DESC=	Use FFTW
GSL_DESC=	Use GNU Scientific Library
S7_DESC=	Use S7 as the extension language

USES=		localbase:ldflags
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-float-samples
MAKEFILE=	makefile
ALL_TARGET=	snd snd-info sndplay
MAKE_JOBS_UNSAFE=	yes

FFTW3_LIB_DEPENDS=	libfftw3.so:math/fftw3
FFTW3_CONFIGURE_WITH=	fftw

GSL_LIB_DEPENDS=	libgsl.so:math/gsl
GSL_CONFIGURE_WITH=	gsl

S7_CONFIGURE_WITH=	s7

LADSPA_BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
LADSPA_RUN_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
LADSPA_CONFIGURE_WITH=	ladspa

GTK2_USES=		gnome
GTK2_USE=		GNOME=gtk20
GTK2_CONFIGURE_WITH=	gtk

MOTIF_USES=	motif
MOTIF_CONFIGURE_WITH=	motif

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
	${INSTALL_MAN} ${WRKSRC}/snd.1 ${STAGEDIR}${MANPREFIX}/man/man1/

do-install-S7-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.scm ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/tools
	${INSTALL_DATA} ${WRKSRC}/tools/*.scm ${STAGEDIR}${DATADIR}/tools
	@${MKDIR} ${STAGEDIR}${DATADIR}/sndins/samples
	${INSTALL_DATA} ${WRKSRC}/sndins/samples/*.scm ${STAGEDIR}${DATADIR}/sndins/samples

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in HISTORY.Snd README.Snd
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/*.html ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/pix
	${INSTALL_DATA} ${WRKSRC}/pix/*.png ${STAGEDIR}${DOCSDIR}/pix

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/DotEmacs ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
