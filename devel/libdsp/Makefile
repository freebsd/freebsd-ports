# ex:ts=8
# New ports collection makefile for:	libdsp
# Date created:		Jan 16, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libdsp
PORTVERSION=	4.1.1
CATEGORIES=	devel audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	libdsp-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

# dont use "USE_LIBTOOL=yes" because there's no configure script
BUILD_DEPENDS=	libtool:${PORTSDIR}/devel/libtool

WRKSRC=		${WRKDIR}/libdsp-src/${PORTNAME:S/dsp/DSP/}-${PORTVERSION}
MAKEFILE=	Makefile.FreeBSD
INLINE_VER=	1.2.3
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${PERL} -pi -e "s|%%INLINE_VER%%|${INLINE_VER}|g ; \
		s|install -m 644|${INSTALL_DATA}|g" ${WRKSRC}/${MAKEFILE}

.include <bsd.port.mk>
