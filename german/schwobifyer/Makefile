# New ports collection makefile for:	schwobifyer
# Date created:				30 Jul 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	schwobifyer
PORTVERSION=	20050730
CATEGORIES=	german
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Utility for translating German into the Schwaebisch dialect

MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/schwobifyer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
