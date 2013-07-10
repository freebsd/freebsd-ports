# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fplib
PORTVERSION=	20120911
CATEGORIES=	audio
MASTER_SITES=	LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Last.fm fingerprint library

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		fftw3:${PORTSDIR}/math/fftw3 \
		fftw3f:${PORTSDIR}/math/fftw3-float \
		mad:${PORTSDIR}/audio/libmad \
		samplerate:${PORTSDIR}/audio/libsamplerate \
		tag:${PORTSDIR}/audio/taglib

CPPFLAGS+=	-I${LOCALBASE}/include
REINPLACE_ARGS=	-i ''
USES=		cmake
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes
USE_XZ=		yes

post-patch:
	@${REINPLACE_CMD} \
		-e 's|\(ADD_DEFINITIONS\)(.*)|\1(${CFLAGS} ${CPPFLAGS})|' \
		-e 's|\(LINK_DIRECTORIES\)(\(.*\))|\1(\2 ${LOCALBASE}/lib)|' \
			${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} \
		-e '85 s|size|&()|' \
			${WRKSRC}/include/fplib/FloatingAverage.h

.include <bsd.port.mk>
