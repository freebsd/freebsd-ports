# New ports collection makefile for:	Class::ObjectTemplate
# Date created:				9 Nov 2001
# Whom:					Tony Maher <tonym@biolateral.com.au>
#
# $FreeBSD$
#

PORTNAME=	Class-ObjectTemplate-DB
PORTVERSION=	0.27
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	An optimized template builder base class with lookup capability

RUN_DEPENDS=	${SITE_PERL}/Class/ObjectTemplate.pm:${PORTSDIR}/devel/p5-Class-ObjectTemplate

PERL_CONFIGURE=	yes

MAN3=		Class::ObjectTemplate::DB.3

.include <bsd.port.mk>
