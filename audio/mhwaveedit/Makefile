# ex:ts=8
# Ports collection makefile for:	mhWaveEdit
# Date created:			Apr 19, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mhwaveedit
PORTVERSION=	1.2.5
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.mtek.chalmers.se/~hjormagn/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical program for editing sound files

LIB_DEPENDS=	sndfile.1:${PORTSDIR}/audio/libsndfile \
		portaudio.0:${PORTSDIR}/audio/portaudio

USE_REINPLACE=	yes
USE_GNOME=	gnomehack gnometarget gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--without-sdl

.if defined(WITH_DOUBLE_SAMPLES)
CONFIGURE_ARGS+=	--with-double-samples
.endif
PLIST_FILES=	bin/mhwaveedit

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "mhWaveEdit has the following tunable option:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	WITH_DOUBLE_SAMPLES=yes"
	@${ECHO_MSG} "		Use double precision floating point numbers for sound"
	@${ECHO_MSG} "		processing (slows down program but may increase"
	@${ECHO_MSG} "		quality for 24/32-bit samplerates)"
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's| -O2||g' ${WRKSRC}/configure

.include <bsd.port.mk>
