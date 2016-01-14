# Created by: gahr
# $FreeBSD$

PORTNAME=	ccaudio2
PORTVERSION=	2.2.0
CATEGORIES=	audio
MASTER_SITES=	GNU/ccaudio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ class framework for manipulating audio files

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libccgnu2.so:${PORTSDIR}/devel/commoncpp \
    		libucommon.so:${PORTSDIR}/devel/ucommon \
		libgsm.so:${PORTSDIR}/audio/gsm \
		libspeex.so:${PORTSDIR}/audio/speex

USES=		cmake:outsource pathfix pkgconfig
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DWITH_INCLUDES:PATH=${LOCALBASE}/include \
		-DCMAKE_INSTALL_MANDIR:STRING=man

.include <bsd.port.mk>
