# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	zita-convolver
DISTVERSION=	4.0.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://kokkinizita.linuxaudio.org/linuxaudio/downloads/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast, partitioned convolution engine library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:math/fftw3
LIB_DEPENDS=	libfftw3f.so:math/fftw3-float

USES=		compiler:c++11-lib gmake localbase:ldflags tar:bz2
USE_LDCONFIG=	yes

WRKSRC_SUBDIR=	source

PLIST_FILES=	include/zita-convolver.h \
		lib/libzita-convolver.so \
		lib/libzita-convolver.so.4 \
		lib/libzita-convolver.so.${PORTVERSION}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libzita-convolver.so.${PORTVERSION}

.include <bsd.port.mk>
