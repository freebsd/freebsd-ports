# Created by: gahr
# $FreeBSD$

PORTNAME=	ccaudio2
PORTVERSION=	2.0.5
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://www.gnutelephony.org/dist/tarballs/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	C++ class framework for manipulating audio files

LIB_DEPENDS=	ccgnu2:${PORTSDIR}/devel/commoncpp \
    		ucommon:${PORTSDIR}/devel/ucommon \
		gsm:${PORTSDIR}/audio/gsm \
		speex:${PORTSDIR}/audio/speex

CONFLICTS=	ccaudio-[0-9]*

NO_STAGE=	yes
USES=		pathfix cmake:outsource pkgconfig
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DWITH_INCLUDES:PATH=${LOCALBASE}/include \
   		-DWITH_LIBS:PATH=${LOCALBASE}/lib

.include <bsd.port.mk>
