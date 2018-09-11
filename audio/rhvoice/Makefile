# $FreeBSD$

PORTNAME=	RHVoice
DISTVERSION=	0.7.1-4
DISTVERSIONSUFFIX=	-g1083ce5
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Speech synthesizer for English, Russian, Georgian, and other languages

LICENSE=	LGPL21+ GPLv3+ # the main code is under LGPL21+, MAGE library is under GPLv3+, voices are licensed for use by individuals only, no commercial use
LICENSE_COMB=	multi
LICENSE_FILE_LGPL21+ =	${WRKSRC}/licenses/lgpl-2.1.txt
LICENSE_FILE_GPLv3+ =	${WRKSRC}/licenses/gpl-3.0.txt

LIB_DEPENDS=	libao.so:audio/libao \
		libportaudio.so:audio/portaudio \
		libpulse.so:audio/pulseaudio

USES=		pkgconfig scons
USE_GITHUB=	yes
GH_ACCOUNT=	Olga-Yakovleva
USE_LDCONFIG=	yes

post-install:
	${MV} ${STAGEDIR}${ETCDIR}/${PORTNAME}.conf ${STAGEDIR}${ETCDIR}/${PORTNAME}.conf.sample

.include <bsd.port.mk>
