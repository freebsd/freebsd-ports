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

USES=		cmake:insource localbase:ldflags
USE_LDCONFIG=	${PREFIX}/lib

# Fix with clang11. Seems dead upstream. Don't expect a proper fix.
CFLAGS+=	-fcommon

WRKSRC_SUBDIR=	src

PLIST_FILES=	bin/arss

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arss ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
