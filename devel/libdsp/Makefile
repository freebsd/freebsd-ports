# ex:ts=8
# New ports collection makefile for:	libdsp
# Date created:		Jan 16, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libdsp
PORTVERSION=	3.3.5
CATEGORIES=	devel audio
MASTER_SITES=	http://www.pp.clinet.fi/~visitor/dlbins/
DISTNAME=	libdsp-src

MAINTAINER=	ijliao@FreeBSD.org

# dont use "USE_LIBTOOL=yes" because there's no configure script
BUILD_DEPENDS=	libtool:${PORTSDIR}/devel/libtool

INSTALLS_SHLIB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME:S/dsp/DSP/}-${PORTVERSION}
MAKEFILE=	Makefile.FreeBSD

USE_GMAKE=	yes

INLINE_VER=	1.1.0

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%INLINE_VER%%|${INLINE_VER}|g" ${WRKSRC}/${MAKEFILE}

.include <bsd.port.mk>
