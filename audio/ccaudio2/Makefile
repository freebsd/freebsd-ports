PORTNAME=	ccaudio2
PORTVERSION=	2.2.0
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	GNU/ccaudio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ class framework for manipulating audio files
WWW=		https://www.gnu.org/software/ccaudio/

DEPRECATED=	Abandonware, no development since 2011
EXPIRATION_DATE=2023-09-30

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libccgnu2.so:devel/commoncpp \
		libucommon.so:devel/ucommon \
		libgsm.so:audio/gsm \
		libspeex.so:audio/speex

USES=		cmake compiler:c++11-lib pathfix pkgconfig
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DWITH_INCLUDES:PATH=${LOCALBASE}/include

.include <bsd.port.mk>
