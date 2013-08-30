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

MAN1=	a52dec.1 extract_a52.1

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
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/liba52.txt ${DOCSDIR}
.endif
.for file in ${HEADER_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/include/a52dec
.endfor

.include <bsd.port.post.mk>
