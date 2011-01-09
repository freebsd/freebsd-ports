# New ports collection makefile for:	filebench
# Date created:			Jan 6, 2011
# Whom:				Tom Judge <tom@tomjudge.com>
#
# $FreeBSD$
#

PORTNAME=	filebench
PORTVERSION=	1.4.8.0.8
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.fsl.cs.sunysb.edu/~vass/filebench/
DISTNAME=	go_filebench-1.4.8.fsl.0.8

MAINTAINER=	tom@tomjudge.com
COMMENT=	Performance Test of Filesystem I/O

ONLY_FOR_ARCHS=	amd64 i386 ia64 ppc

GNU_CONFIGURE=	yes
LICENSE=	CDDL

do-install:
	( cd ${WRKSRC} && make install-binPROGRAMS )
.if !defined(NOPORTDATA)
	(cd ${WRKSRC} && make install-data )
.endif

.include <bsd.port.mk>
