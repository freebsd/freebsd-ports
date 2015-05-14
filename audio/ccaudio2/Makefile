# Created by: gahr
# $FreeBSD$

PORTNAME=	ccaudio2
PORTVERSION=	2.1.3
CATEGORIES=	audio
MASTER_SITES=	GNU/ccaudio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ class framework for manipulating audio files

LIB_DEPENDS=	libccgnu2.so:${PORTSDIR}/devel/commoncpp \
    		libucommon.so:${PORTSDIR}/devel/ucommon \
		libgsm.so:${PORTSDIR}/audio/gsm \
		libspeex.so:${PORTSDIR}/audio/speex

USES=		cmake:outsource pkgconfig
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DWITH_INCLUDES:PATH=${LOCALBASE}/include \
   		-DWITH_LIBS:PATH=${LOCALBASE}/lib \
		-DINSTALL_MANDIR=man \
		-DSYSCONFDIR=${PREFIX}/etc

.include <bsd.port.mk>
