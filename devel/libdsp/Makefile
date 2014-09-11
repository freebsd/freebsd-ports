# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libdsp
PORTVERSION=	5.0.2
PORTREVISION=	1
CATEGORIES=	devel audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-stable-src/${PORTVERSION} \
		http://mirror.mcx2.org/

DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	C++ class library of common digital signal processing functions

WRKSRC=		${WRKDIR}/libdsp-src-${PORTVERSION}/${PORTNAME:S/dsp/DSP/}-${PORTVERSION}

MAKE_ENV=	MKDIR="${MKDIR}" INLINE_VER="${INLINE_VER}"
MAKEFILE=	Makefile.BSD
USES=		gmake libtool:build
USE_LDCONFIG=	yes

INLINE_VER=	1.4.0

CFLAGS_i386+=	-DDSP_X86

.include <bsd.port.mk>
