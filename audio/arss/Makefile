PORTNAME=	arss
PORTVERSION=	0.2.3
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Additive Image Synthesizer (convert audio to images, images to audio)
WWW=		https://arss.sourceforge.net/

DEPRECATED=	Abandoned upstream, does not build with CMake 4
EXPIRATION_DATE=2026-11-30

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
