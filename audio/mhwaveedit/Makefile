# ex:ts=8
# Ports collection makefile for:	mhWaveEdit
# Date created:			Apr 19, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mhwaveedit
PORTVERSION=	1.3.7
CATEGORIES=	audio
MASTER_SITES=	http://www.mtek.chalmers.se/~hjormagn/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical program for editing sound files

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS=	samplerate.1:${PORTSDIR}/audio/libsamplerate \
		sndfile.1:${PORTSDIR}/audio/libsndfile \
		portaudio.0:${PORTSDIR}/audio/portaudio

USE_GNOME=	gnomehack gnometarget gtk20
WANT_GNOME=	yes
WANT_SDL=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-optimization --without-alsalib

PLIST_FILES=	bin/mhwaveedit

.include <bsd.port.pre.mk>

.if defined(WITH_DOUBLE_SAMPLES)
CONFIGURE_ARGS+=	--with-double-samples
.endif

.if defined(WITH_JACK)
LIB_DPENDS+=	jack:${PORTSDIR}/audio/jack
.else
CONFIGURE_ARGS+=	--without-jack
.endif

.if ${HAVE_SDL:Msdl}!=""
USE_SDL+=	sdl
.else
CONFIGURE_ARGS+=	--without-sdl
.endif

.if ${HAVE_GNOME:Mesound}!=""
USE_GNOME+=	esound
.else
CONFIGURE_ARGS+=	--without-esound
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "mhWaveEdit has the following tunable option:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	WITH_DOUBLE_SAMPLES=yes"
	@${ECHO_MSG} "		Use double precision floating point numbers for sound"
	@${ECHO_MSG} "		processing (slows down program but may increase"
	@${ECHO_MSG} "		quality for 24/32-bit samplerates)"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	WITH_JACK=yes"
	@${ECHO_MSG} "		Support JACK driver"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	WITH_GNOME=esound"
	@${ECHO_MSG} "		Support EsounD driver"
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
