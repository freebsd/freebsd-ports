# New ports collection makefile for:	p5-Class-XSAccessor-Array
# Date created:				March 8th 2009
# Whom:	      				Cezary Morga <cm@therek.net>
#
# $FreeBSD$
#

PORTNAME=	Class-XSAccessor-Array
PORTVERSION=	1.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cm@therek.net
COMMENT=	Perl5 module for unloading classes

BUILD_DEPENDS=	${SITE_PERL}/AutoXS/Header.pm:${PORTSDIR}/devel/p5-AutoXS-Header
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Class::XSAccessor::Array.3

.include <bsd.port.mk>
