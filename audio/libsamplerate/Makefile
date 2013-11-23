# Created by: <dmagda+libsamplerate@ee.ryerson.ca>
# $FreeBSD$

PORTNAME=	libsamplerate
PORTVERSION=	0.1.8
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://www.mega-nerd.com/SRC/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Secret Rabbit Code: a Sample Rate Converter for audio

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=	pathfix pkgconfig
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	CPU_CLIP DOCS EXAMPLES
CPU_CLIP_DESC=	Allow machine-dependent clipping

.include <bsd.port.options.mk>

MAKE_ARGS+=	htmldocdir=${PREFIX}/share/doc/libsamplerate

.if ${PORT_OPTIONS:MCPU_CLIP}
MANUAL_PACKAGE_BUILD=	CPU_CLIP may customize the package for the build machine
.else
CONFIGURE_ARGS+=	--disable-cpu-clip
.endif

.if defined(MAINTAINER_MODE) || defined(PACKAGE_BUILDING)
BUILD_DEPENDS +=	${LOCALBASE}/lib/libfftw3.so:${PORTSDIR}/math/fftw3
.else
CONFIGURE_ARGS+=	--disable-fftw
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
LIB_DEPENDS+=	libsndfile.so:${PORTSDIR}/audio/libsndfile
.elif defined(MAINTAINER_MODE) || defined(PACKAGE_BUILDING)
BUILD_DEPENDS +=	libsndfile>=0:${PORTSDIR}/audio/libsndfile
.else
CONFIGURE_ARGS+=	--disable-sndfile
.endif

post-patch:
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -e '/SUBDIRS =/s/doc //' ${WRKSRC}/Makefile.in
.endif
.if empty(PORT_OPTIONS:MEXAMPLES)
	@${REINPLACE_CMD} -e '/SUBDIRS =/s/examples //' ${WRKSRC}/Makefile.in
.endif

.if defined(MAINTAINER_MODE) || defined(PACKAGE_BUILDING)
check regression-test test: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} \
	check
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsamplerate.so.1

.include <bsd.port.mk>
