# New ports collection makefile for:	gsoap
# Date created:				8 March 2004
# Whom:					Sergey Matveychuk <sem@ciam.ru>
#
# $FreeBSD$
#

PORTNAME=	gsoap
PORTVERSION=	2.6.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gsoap2

MAINTAINER=	sem@ciam.ru
COMMENT=	Generator Tools for Coding SOAP/XML Web Services in C and C++

WRKSRC=		${WRKDIR}/${PORTNAME}-2.6

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

ONLY_FOR_ARCHS=	i386

.include <bsd.port.mk>
