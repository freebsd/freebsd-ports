# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	liba52
PORTVERSION=	0.7.4
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://liba52.sourceforge.net/files/
DISTNAME=	a52dec-${PORTVERSION:S/.b/b/}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Free library for decoding ATSC A/52 streams, aka AC-3

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_AUTOTOOLS=	libtool
USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-oss --enable-shared
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DJBFFT OPTIMIZED_CFLAGS DOCS
DJBFFT_DESC=	djb fft support

DJBFFT_BUILD_DEPENDS=	${LOCALBASE}/lib/libdjbfft.a:${PORTSDIR}/math/djbfft
DJBFFT_RUN_DEPENDS=	${LOCALBASE}/lib/libdjbfft.a:${PORTSDIR}/math/djbfft
DJBFFT_CFLAGS=		-I${LOCALBASE}/include
DJBFFT_LDFLAGS=		-L${LOCALBASE}/lib
DJBFFT_CONFIGURE_ON=	--enable-djbfft

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "powerpc"
CFLAGS+=	-fPIC
.endif

HEADER_FILES=	liba52/a52_internal.h

post-patch:
.if ! ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
	@${REINPLACE_CMD} -E -e 's!-O3!${CFLAGS}!' -e 's!-mcpu=[^"]+"!"!' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.endif
.if ${PORT_OPTIONS:MDJBFFT}
	@${REINPLACE_CMD} -E -e 's|(fftc4.h)|djbfft/\1|' ${WRKSRC}/liba52/imdct.c
.endif

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/liba52.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/liba52/a52_internal.h ${STAGEDIR}${PREFIX}/include/a52dec
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/liba52.so.0

.include <bsd.port.post.mk>
