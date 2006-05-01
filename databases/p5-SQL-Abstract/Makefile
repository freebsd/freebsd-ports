# New ports collection makefile for:	SQL-Abstract
# Date created:	   18 Feb 2003
# Whom:		   Dominic Mitchell <dom@happygiraffe.net>
#
# $FreeBSD$
#

PORTNAME=	SQL-Abstract
PORTVERSION=	1.21
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	SQL
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Perl extension to generate SQL from Perl data structures

PERL_CONFIGURE=	yes

MAN3=		SQL::Abstract.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.x or later
.endif

.include <bsd.port.post.mk>
