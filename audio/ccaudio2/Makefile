# Created by: gahr
# $FreeBSD$

PORTNAME=	ccaudio2
PORTVERSION=	2.0.5
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://www.gnutelephony.org/dist/tarballs/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	C++ class framework for manipulating audio files

LIB_DEPENDS=	libccgnu2.so:${PORTSDIR}/devel/commoncpp \
    		libucommon.so:${PORTSDIR}/devel/ucommon \
		libgsm.so:${PORTSDIR}/audio/gsm \
		libspeex.so:${PORTSDIR}/audio/speex

CONFLICTS=	ccaudio-[0-9]*

USES=		pathfix cmake:outsource pkgconfig
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DWITH_INCLUDES:PATH=${LOCALBASE}/include \
   		-DWITH_LIBS:PATH=${LOCALBASE}/lib

.include <bsd.port.mk>
