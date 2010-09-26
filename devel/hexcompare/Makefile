# New ports collection makefile for:	hexcompare
# Date created:		2010-07-20
# Whom:			Steven Kreuzer <skreuzer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hexcompare
PORTVERSION=	1.0.1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20v${PORTVERSION}
DISTNAME=	${PORTNAME}-101

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Compare and identify differences between two binary files

LICENSE=	GPLv3

PLIST_FILES=	bin/hexcompare

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
