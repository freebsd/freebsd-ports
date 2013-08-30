# Created by: trevor
# $FreeBSD$

PORTNAME=	pd
DISTVERSION=	0.44-3
DISTVERSIONSUFFIX=	.src
CATEGORIES=	audio
#MASTER_SITES=	SF/pure-data/pure-data/${PORTVERSION}
MASTER_SITES=	http://www-crca.ucsd.edu/~msp/Software/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MIDI-capable real-time audio processor/synthesizer

LICENSE=	BSD

RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils \
		dejavu>0:${PORTSDIR}/x11-fonts/dejavu

OPTIONS_DEFINE=	ALSA FFTW JACK DOCS
OPTIONS_DEFAULT=FFTW

WRKSRC=		${WRKDIR}/${DISTNAME:S,${DISTVERSIONSUFFIX},,}

USES=		gettext gmake pkgconfig
USE_TK_WRAPPER=	yes
USE_AUTOTOOLS=	aclocal libtoolize autoconf automake
ACLOCAL_ARGS=	-I m4/generated -I m4
LIBTOOLIZE_ARGS=--install --force
AUTOMAKE_ARGS=	--add-missing --copy --force-missing

MAN1=		pd.1 pdreceive.1 pdsend.1

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	asound:${PORTSDIR}/audio/alsa-lib
CONFIGURE_ARGS+=	--enable-alsa
.else
CONFIGURE_ARGS+=	--disable-alsa
.endif

.if ${PORT_OPTIONS:MFFTW}
BUILD_DEPENDS+=	fftw3>0:${PORTSDIR}/math/fftw3
LIB_DEPENDS+=	fftw3f:${PORTSDIR}/math/fftw3-float
CONFIGURE_ARGS+=	--enable-fftw
.else
CONFIGURE_ARGS+=	--disable-fftw
.endif

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	jack:${PORTSDIR}/audio/jack
CONFIGURE_ARGS+=	--enable-jack
.else
CONFIGURE_ARGS+=	--disable-jack
.endif

post-patch:
	@${FIND} ${PATCH_WRKSRC} -name "*.[ch]" | ${XARGS} ${REINPLACE_CMD} -e \
		's|__FreeBSD_kernel__|__FreeBSD__|g ; \
		 s|<alloca\.h>|<stdlib.h>|g'
	@${REINPLACE_CMD} -e \
		's|kFreeBSD)|kFreeBSD\|*freebsd*)| ; \
		 s|portaudio=yes|portaudio=no| ; \
		 s|-O6|| ; \
		 s|fftw,|fftw3f,| ; \
		 s|fftw_one,|fftwf_execute,| ; \
		 s|fftw"|fftw3f"| ; \
		 s|-lpthread ||' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e \
		'/^pkgconfigdir/s|=.*|= $$(prefix)/libdata/pkgconfig| ; \
		 /^libpddir/s|=.*|= $$(pkglibdir)| ; \
		 s|make -C|$$(MAKE) -C|' ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e \
		'/^pd_LDADD/s| =.*| = $$(LIBM)|' ${WRKSRC}/src/Makefile.am
	@${REINPLACE_CMD} -e \
		's|PD_BASEDIR/LICENSE|${DOCSDIR}/LICENSE|g ; \
		 s|PD_BASEDIR/doc/1|${DOCSDIR}/1|g' \
			${WRKSRC}/doc/1.manual/1.introduction.txt
	@${REINPLACE_CMD} -e \
		's|-O2 | | ; \
		 s|-lc ||g' ${WRKSRC}/extra/makefile.subdir
	@${REINPLACE_CMD} -e \
		's|-O2 |$$(CFLAGS) | ; \
		 s|-g ||g ; \
		 s|-lc ||g' ${WRKSRC}/extra/expr~/makefile

pre-configure:
	@(cd ${WRKSRC}/portaudio \
		&& ${SETENV} ${AUTOTOOLS_ENV} ${ACLOCAL} \
		&& ${SETENV} ${AUTOTOOLS_ENV} ${LIBTOOLIZE} \
		&& ${SETENV} ${AUTOTOOLS_ENV} ${AUTOCONF})

do-install:
.for i in src man tcl po extra
	@(cd ${WRKSRC}/${i} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.endfor
	(cd ${WRKSRC} && ${INSTALL_DATA} pd.pc ${PREFIX}/libdata/pkgconfig)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@(${TAR} -C ${WRKSRC}/doc --exclude "*.bak" --exclude "*.orig" \
		-cf - . | ${TAR} -C ${DOCSDIR} --unlink -xf -)
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@${FIND} ${DOCSDIR} -type d -exec ${CHMOD} 755 {} \;
	@${FIND} ${DOCSDIR} -type f -exec ${CHMOD} ${SHAREMODE} {} \;
.for i in LICENSE.txt README.txt
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${DOCSDIR})
.endfor
	@${LN} -sf ${DOCSDIR} ${PREFIX}/lib/pd/doc
.endif

.include <bsd.port.mk>
