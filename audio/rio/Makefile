# New ports collection makefile for:   rio
# Date created:        29 April 1999
# Whom:                Nick Sayer <nsayer@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	rio
PORTVERSION=	1.06
CATEGORIES=	audio
MASTER_SITES=	http://www.world.co.uk/sba/
DISTNAME=	rio006
EXTRACT_SUFX=	.tgz

MAINTAINER=	derm@ibm.net

WRKSRC=		${WRKDIR}/rio
MAKEFILE=	makefile

BINOWN=		root
BINMODE=	4755

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rio ${PREFIX}/bin

.include <bsd.port.mk>
