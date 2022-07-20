PORTNAME=	libdsp
PORTVERSION=	5.0.2
PORTREVISION=	3
CATEGORIES=	devel audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-stable-src/${PORTVERSION} \
		http://mirror.mcx2.org/

DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ class library of common digital signal processing functions

WRKSRC=		${WRKDIR}/libdsp-src-${PORTVERSION}/${PORTNAME:S/dsp/DSP/}-${PORTVERSION}

MAKE_ENV=	MKDIR="${MKDIR}" INLINE_VER="${INLINE_VER}"
MAKEFILE=	Makefile.BSD
USES=		gmake libtool:build
USE_LDCONFIG=	yes

INLINE_VER=	1.4.0

CFLAGS_i386+=	-DDSP_X86

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libdsp.so

.include <bsd.port.mk>
