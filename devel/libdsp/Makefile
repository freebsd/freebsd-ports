# ex:ts=8
# New ports collection makefile for:	libdsp
# Date created:		Jan 16, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libdsp
PORTVERSION=	4.0.0
CATEGORIES=	devel audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	libdsp-src-${PORTVERSION}

MAINTAINER=	ijliao@FreeBSD.org

# dont use "USE_LIBTOOL=yes" because there's no configure script
BUILD_DEPENDS=	libtool:${PORTSDIR}/devel/libtool

WRKSRC=		${WRKDIR}/libdsp-src/${PORTNAME:S/dsp/DSP/}-${PORTVERSION}
INLINE_VER=	1.2.2
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${PERL} -pi -e "s|%%INLINE_VER%%|${INLINE_VER}|g" ${WRKSRC}/${MAKEFILE}

.include <bsd.port.mk>
