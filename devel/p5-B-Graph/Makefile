# New ports collection makefile for:	p5-B-Graph
# Date created:		24-Jul-2000
# Whom:			Leo Kim <leo@florida.sarang.net>
#
# $FreeBSD$
#

PORTNAME=	B-Graph
PORTVERSION=	0.50
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=B
PKGNAMEPREFIX=	p5-

MAINTAINER=	leo@florida.sarang.net

USE_PERL5=	YES
MAN3=		B::Graph.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
