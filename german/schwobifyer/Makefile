# New ports collection makefile for:	schwobifyer
# Date created:				30 Jul 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	schwobifyer
PORTVERSION=	20050730
CATEGORIES=	german
MASTER_SITES=	http://critical.ch/distfiles/
PKGNAMEPREFIX=	de-

MAINTAINER=	ehaupt@critical.ch
COMMENT=	A utility for translating german into the schwaebisch dialect

PLIST_FILES=	bin/schwobifyer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
