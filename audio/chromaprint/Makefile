# $FreeBSD$

PORTNAME=	chromaprint
PORTVERSION=	1.3.1
CATEGORIES=	audio
MASTER_SITES=	http://bitbucket.org/acoustid/${PORTNAME}/downloads/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	AcoustID audio fingerprinting library

LICENSE=	LGPL21

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

USES=		cmake:outsource pathfix
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBUILD_EXAMPLES:BOOL=ON \
		-DWITH_AVFFT:BOOL=ON \

.include <bsd.port.mk>
