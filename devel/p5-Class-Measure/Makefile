# New ports collection makefile for:	p5-Class-Measure
# Date created:		2006-10-23
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Class-Measure
PORTVERSION=	0.02
CATEGORIES=	devel
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Create, compare, and convert units of measurement

PERL_MODBUILD=	yes

MAN3=		Class::Measure.3 Class::Measure::Length.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		requires Perl 5.6.1 or newer. Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
