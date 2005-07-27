# New ports collection makefile for:	gsoap
# Date created:				8 March 2004
# Whom:					Sergey Matveychuk <sem@ciam.ru>
#
# $FreeBSD$
#

PORTNAME=	gsoap
PORTVERSION=	2.7.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gsoap2
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Generator Tools for Coding SOAP/XML Web Services in C and C++

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

WRKSRC=		${WRKDIR}/${PORTNAME}-2.7

ONLY_FOR_ARCHS=	i386

.include <bsd.port.mk>
