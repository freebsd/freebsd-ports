# $FreeBSD$

PORTNAME=	rhvoice
DISTVERSION=	0.7.1-4
DISTVERSIONSUFFIX=	-g1083ce5
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Speech synthesizer for English, Russian, Georgian, and other languages

LICENSE=	GPLv3+

LIB_DEPENDS=	libao.so:audio/libao \
		libportaudio.so:audio/portaudio \
		libpulse.so:audio/pulseaudio

USES=		pkgconfig scons
USE_GITHUB=	yes
GH_ACCOUNT=	Olga-Yakovleva
GH_PROJECT=	RHVoice
USE_LDCONFIG=	yes

.include <bsd.port.mk>
