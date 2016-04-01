# Created by: Timothy Beyer <beyert@cs.ucr.edu>
# $FreeBSD$

PORTNAME=	arss
PORTVERSION=	0.2.3
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Additive Image Synthesizer (convert audio to images, images to audio)

LIB_DEPENDS=	libfftw3.so:math/fftw3

WRKSRC=	${WRKDIR}/${DISTNAME}/src

USES=		cmake
USE_LDCONFIG=	${PREFIX}/lib
CFLAGS+=	-L${LOCALBASE}/lib -I${LOCALBASE}/include
CMAKE_C_FLAGS=	${CFLAGS}

PLIST_FILES=	bin/arss

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arss ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
