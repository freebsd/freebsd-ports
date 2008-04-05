# New ports collection makefile for:	geekbench
# Date created:		2006-12-09
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	geekbench
PORTVERSION=	2
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.primatelabs.ca/download/
DISTNAME=	Geekbench${PORTVERSION}-Linux

MAINTAINER=	gslin@gslin.org
COMMENT=	Cross-platform benchmark suite

NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes

PLIST_FILES=	bin/geekbench

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/geekbench ${PREFIX}/bin

.include <bsd.port.mk>
