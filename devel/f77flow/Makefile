# New ports collection makefile for:	f77flow
# Date created:				25 June 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=		f77flow
PORTVERSION=		0.12
PORTREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	devel/lang/fortran

MAINTAINER=		ports@FreeBSD.org
COMMENT=	Analyze the structure of a fortran77 program

ALL_TARGET=
MAN1=		flow.1
PLIST_FILES=	bin/flow

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/flow ${PREFIX}/bin/flow
	@ ${INSTALL_MAN} ${WRKSRC}/flow.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
