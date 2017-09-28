# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	liba52
PORTVERSION=	0.7.4
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://liba52.sourceforge.net/files/
DISTNAME=	a52dec-${PORTVERSION:S/.b/b/}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Free library for decoding ATSC A/52 streams, aka AC-3

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-oss --enable-shared
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DJBFFT OPTIMIZED_CFLAGS DOCS
DJBFFT_DESC=	djb fft support

DJBFFT_BUILD_DEPENDS=	${LOCALBASE}/lib/libdjbfft.a:math/djbfft
DJBFFT_RUN_DEPENDS=	${LOCALBASE}/lib/libdjbfft.a:math/djbfft
DJBFFT_CFLAGS=		-I${LOCALBASE}/include
DJBFFT_LDFLAGS=		-L${LOCALBASE}/lib
DJBFFT_CONFIGURE_ON=	--enable-djbfft

HEADER_FILES=	liba52/a52_internal.h

post-patch:
	@${REINPLACE_CMD} '/-prefer-non-pic/d' ${WRKSRC}/configure

post-patch-OPTIMIZED_CFLAGS-off:
	@${REINPLACE_CMD} -E -e 's!-O3!${CFLAGS}!' -e 's!-mcpu=[^"]+"!"!' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
post-patch-DJBFFT-on:
	@${REINPLACE_CMD} -E -e 's|(fftc4.h)|djbfft/\1|' ${WRKSRC}/liba52/imdct.c

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/liba52.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/liba52/a52_internal.h ${STAGEDIR}${PREFIX}/include/a52dec
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/liba52.so.0.*

.include <bsd.port.mk>
