# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	zita-convolver
PORTVERSION=	3.1.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://kokkinizita.linuxaudio.org/linuxaudio/downloads/

MAINTAINER=	yuri@rawbw.com
COMMENT=	Fast, partitioned convolution engine library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:math/fftw3
LIB_DEPENDS=	libfftw3f.so:math/fftw3-float

USES=		compiler:c++11-lib gmake localbase:ldflags tar:bz2
USE_LDCONFIG=	yes
WRKSRC_SUBDIR=	libs

PLIST_FILES=	include/zita-convolver.h \
		lib/libzita-convolver.so \
		lib/libzita-convolver.so.3 \
		lib/libzita-convolver.so.${PORTVERSION}

post-patch:
	${REINPLACE_CMD} 's/__APPLE__/__FreeBSD__/' \
		${WRKSRC}/zita-convolver.h

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libzita-convolver.so.${PORTVERSION}

.include <bsd.port.mk>
