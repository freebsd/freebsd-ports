# New ports collection makefile for:	lmbench
# Version required:	1.0
# Date created:		6 May 1995
# Whom:			asami
#
# $Id: Makefile,v 1.4 1995/04/15 03:46:04 asami Exp $
#

DISTNAME=	lmbench-1.0
CATEGORIES+=	utilities
MASTER_SITES=	ftp://forte.mathematik.uni-bremen.de/pub/unix/benchmarks/

MAINTAINER=	asami@FreeBSD.ORG

ALL_TARGET=	build

test: build
	@(cd ${WRKSRC}; make results)

retest: build
	@(cd ${WRKSRC}; make rerun)

.include <bsd.port.mk>
