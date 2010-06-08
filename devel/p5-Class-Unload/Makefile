# New ports collection makefile for:	p5-Class-Unload
# Date created:				March 8th 2009
# Whom:	      				Cezary Morga <cm@therek.net>
#
# $FreeBSD$
#

PORTNAME=	Class-Unload
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cm@therek.net
COMMENT=	Perl5 module for unloading classes

BUILD_DEPENDS=	${SITE_PERL}/Class/Inspector.pm:${PORTSDIR}/devel/p5-Class-Inspector
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Class::Unload.3

.include <bsd.port.mk>
