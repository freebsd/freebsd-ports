# ex:ts=8
# New ports collection makefile for:	libdsp
# Date created:		Jan 16, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libdsp
PORTVERSION=	4.6.0
PORTREVISION=	2
CATEGORIES=	devel audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ class library of common digital signal processing functions

WRKSRC=		${WRKDIR}/libdsp-src/${PORTNAME:S/dsp/DSP/}-${PORTVERSION}

USE_AUTOTOOLS=	libtool:15:env
USE_GMAKE=	yes
MAKE_ENV=	MKDIR="${MKDIR}" INLINE_VER="${INLINE_VER}"
MAKEFILE=	Makefile.FreeBSD
USE_LDCONFIG=	yes

INLINE_VER=	1.2.5

do-configure:
	@${DO_NADA}

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
CFLAGS+=	-DDSP_X86
.endif

.include <bsd.port.post.mk>
