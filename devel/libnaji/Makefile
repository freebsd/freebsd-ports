# New ports collection makefile for:	libnaji
# Date created:				18 May 2005
# Whom:					NECDET COKYAZICI <cokyazici@yahoo.co.uk>
#
# $FreeBSD$
#

PORTNAME=	libnaji
PORTVERSION=	0.3.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	najitool

MAINTAINER=	cokyazici@yahoo.co.uk
COMMENT=	A library that generates, converts, and filters files

MAKEFILE=	makefile

DISTVERSIONSUFFIX=	.src

do-install:
	${INSTALL_DATA} ${WRKSRC}/libnaji.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libnaji.a ${PREFIX}/lib

.include <bsd.port.mk>
