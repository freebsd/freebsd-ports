# Created by: trevor
# $FreeBSD$

PORTNAME=	snd
PORTVERSION=	13.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ccrma-ftp.stanford.edu/pub/Lisp/ \
		http://mirror.mcx2.org/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Multitracking sound editor and utilities

OPTIONS_DEFINE=	FFTW3 GSL S7 LADSPA MOTIF GTK2 X11 DOCS EXAMPLES
OPTIONS_DEFAULT=	FFTW3 GSL LADSPA GTK2 X11
FFTW3_DESC=	Use FFTW
GSL_DESC=	Use GNU Scientific Library
S7_DESC=	Use S7 as the extension language

WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-float-samples
MAKEFILE=	makefile
ALL_TARGET=	snd snd-info sndplay
MAKE_JOBS_UNSAFE=	yes
NO_STAGE=	yes

MAN1=		snd.1

CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64"
BROKEN=		does not compile on sparc64
.endif

.if ${PORT_OPTIONS:MFFTW3}
LIB_DEPENDS+=	libfftw3.so:${PORTSDIR}/math/fftw3
.else
CONFIGURE_ARGS+=	--without-fftw
.endif

.if ${PORT_OPTIONS:MGSL}
LIB_DEPENDS+=	libgsl.so:${PORTSDIR}/math/gsl
.else
CONFIGURE_ARGS+=	--without-gsl
.endif

.if ${PORT_OPTIONS:MS7}
CONFIGURE_ARGS+=	--with-s7
.else
CONFIGURE_ARGS+=	--without-s7
.endif

.if ${PORT_OPTIONS:MLADSPA}
BUILD_DEPENDS+=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
RUN_DEPENDS+=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
.else
CONFIGURE_ARGS+=	--without-ladspa
.endif

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=	--with-gtk
.endif
.if ${PORT_OPTIONS:MMOTIF}
USES+=		motif
CONFIGURE_ARGS+=	--with-motif
.endif

.if ${PORT_OPTIONS:MX11}
CONFIGURE_ARGS+=	--with-no-gui
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^ _Complex| Vaiolate _Complex|g ; \
		 s|-O2 -I|-I|g ; \
		 s|LDFLAGS -ldl|LDFLAGS|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|^sndinfo:|snd-info:|g ; \
		 s|-o sndinfo|-o snd-info|g' ${WRKSRC}/makefile.in

do-install:
.for i in snd snd-info sndplay
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/snd.1 ${MANPREFIX}/man/man1/
.if ${PORT_OPTIONS:MS7}
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.scm ${DATADIR}
	@${MKDIR} ${DATADIR}/tools
	${INSTALL_DATA} ${WRKSRC}/tools/*.scm ${DATADIR}/tools
	@${MKDIR} ${DATADIR}/sndins/samples
	${INSTALL_DATA} ${WRKSRC}/sndins/samples/*.scm ${DATADIR}/sndins/samples
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in HISTORY.Snd README.Snd
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/*.html ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/pix
	${INSTALL_DATA} ${WRKSRC}/pix/*.png ${DOCSDIR}/pix
	cd ${WRKSRC} && ${PAX} -r -w tutorial ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/DotEmacs ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
