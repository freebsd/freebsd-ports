# New ports collection makefile for:	libsamplerate
# Date created:				2 February 2003
# Whom:			<dmagda+libsamplerate@ee.ryerson.ca>
#
# $FreeBSD$
#

PORTNAME=	libsamplerate
PORTVERSION=	0.1.8
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://www.mega-nerd.com/SRC/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Secret Rabbit Code: a Sample Rate Converter for audio

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GNOME=	gnomehack pkgconfig
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

OPTIONS=	CPU_CLIP "Allow machine-dependent clipping" off

.include <bsd.port.options.mk>

MAKE_ARGS+=	htmldocdir=${PREFIX}/share/doc/libsamplerate

.if !defined(WITH_CPU_CLIP)
CONFIGURE_ARGS+=	--disable-cpu-clip
.else
MANUAL_PACKAGE_BUILD=	WITH_CPU_CLIP may customize the package for the build machine
.endif

.if defined(MAINTAINER_MODE) || defined(PACKAGE_BUILDING)
BUILD_DEPENDS +=	${LOCALBASE}/lib/libfftw3.so:${PORTSDIR}/math/fftw3
.else
CONFIGURE_ARGS+=	--disable-fftw
.endif

.if !defined(NOPORTEXAMPLES)
LIB_DEPENDS+=	sndfile.1:${PORTSDIR}/audio/libsndfile
.elif defined(MAINTAINER_MODE) || defined(PACKAGE_BUILDING)
BUILD_DEPENDS +=	${LOCALBASE}/lib/libsndfile.so:${PORTSDIR}/audio/libsndfile
.else
CONFIGURE_ARGS+=	--disable-sndfile
.endif

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/SUBDIRS =/s/doc //' ${WRKSRC}/Makefile.in
.endif
.if defined(NOPORTEXAMPLES)
	@${REINPLACE_CMD} -e '/SUBDIRS =/s/examples //' ${WRKSRC}/Makefile.in
.endif

.if defined(MAINTAINER_MODE) || defined(PACKAGE_BUILDING)
check regression-test test: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} \
	check
.endif

.include <bsd.port.mk>
