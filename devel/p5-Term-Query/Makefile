# New ports collection makefile for:    p5-Term-Query
# Date created:				21 May 1998
# Whom:	      				Garrett Wollman <wollman@lcs.mit.edu>
#
# $FreeBSD$
#

PORTNAME=	Term-Query
PORTVERSION=	2.0
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Term
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An interactive question-response user interface module

RUN_DEPENDS=	${SITE_PERL}/Array/PrintCols.pm:${PORTSDIR}/misc/p5-Array-PrintCols

PERL_CONFIGURE=	YES

MAN3=		Term::Query.3

.include <bsd.port.mk>
