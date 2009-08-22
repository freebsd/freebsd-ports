# New ports collection makefile for:	libdsp
# Date created:		Jan 16, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libdsp
PORTVERSION=	5.0.2
CATEGORIES=	devel audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-stable-src/${PORTVERSION} \
		http://mirror.mcx2.org/

DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	C++ class library of common digital signal processing functions

WRKSRC=		${WRKDIR}/libdsp-src-${PORTVERSION}/${PORTNAME:S/dsp/DSP/}-${PORTVERSION}

USE_AUTOTOOLS=	libtool:22:env
USE_GMAKE=	yes
MAKE_ENV=	MKDIR="${MKDIR}" INLINE_VER="${INLINE_VER}"
MAKEFILE=	Makefile.BSD
USE_LDCONFIG=	yes

INLINE_VER=	1.4.0

do-configure:
	@${DO_NADA}

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
CFLAGS+=	-DDSP_X86
.endif

.if ${OSVERSION} < 700000
BROKEN=		Unable to build
.endif

.include <bsd.port.post.mk>
