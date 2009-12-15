# New ports collection makefile for:  p5-Class-Declare
# Date created:        12 January 2009
# Whom:            kevit
#
# $FreeBSD$
#

PORTNAME=	Class-Declare
PORTVERSION=	0.13
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	simarg@gmail.com
COMMENT=	Perl module for declare classes

BUILD_DEPENDS=	${SITE_PERL}/Test/Exception.pm:${PORTSDIR}/devel/p5-Test-Exception
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
MAN3=	Class::Declare::Dump.3 Class::Declare.3 Class::Declare::Hash.3

.include <bsd.port.mk>
