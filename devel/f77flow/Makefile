# New ports collection makefile for:	f77flow
# Date created:				25 June 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=		f77flow
PORTVERSION=		0.12
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	devel/lang/fortran

MAINTAINER=		ports@FreeBSD.org

ALL_TARGET=
MAN1=			flow.1

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/flow ${PREFIX}/bin/flow
	@ ${INSTALL_MAN} ${WRKSRC}/flow.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
