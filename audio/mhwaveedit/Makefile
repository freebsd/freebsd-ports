# ex:ts=8
# Ports collection makefile for:	mhWaveEdit
# Date created:			Apr 19, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mhwaveedit
PORTVERSION=	1.2.4
CATEGORIES=	audio
MASTER_SITES=	http://www.mtek.chalmers.se/~hjormagn/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical program for editing sound files

LIB_DEPENDS=	sndfile.1:${PORTSDIR}/audio/libsndfile \
		portaudio.0:${PORTSDIR}/audio/portaudio

USE_REINPLACE=	yes
USE_GNOME=	gnomehack gtk20
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--without-sdl

post-patch:
	@${REINPLACE_CMD} -e 's| -O2||g' ${WRKSRC}/configure

.include <bsd.port.mk>
