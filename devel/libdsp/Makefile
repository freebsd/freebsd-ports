# ex:ts=8
# New ports collection makefile for:	libdsp
# Date created:		Jan 16, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libdsp
PORTVERSION=	4.3.0
CATEGORIES=	devel audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

# dont use "USE_LIBTOOL=yes" because there's no configure script
BUILD_DEPENDS=	libtool:${PORTSDIR}/devel/libtool

WRKSRC=		${WRKDIR}/libdsp-src/${PORTNAME:S/dsp/DSP/}-${PORTVERSION}

USE_GMAKE=	yes
MAKE_ENV=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" MKDIR="${MKDIR}" \
		INLINE_VER="${INLINE_VER}"
MAKEFILE=	Makefile.FreeBSD
INSTALLS_SHLIB=	yes

INLINE_VER=	1.2.4

.include <bsd.port.mk>
