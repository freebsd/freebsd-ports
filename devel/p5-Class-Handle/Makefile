# New ports collection makefile for:	Class-Handle
# Date created:	   12 February 2005
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Class-Handle
PORTVERSION=	1.03
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Create objects that are handles to classes

RUN_DEPENDS=	${SITE_PERL}/Class/ISA.pm:${PORTSDIR}/devel/p5-Class-ISA \
		${SITE_PERL}/Class/Inspector.pm:${PORTSDIR}/devel/p5-Class-Inspector
BUILD_DEPENDS=	${RUN_DEPENDS} \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=		Class::Handle.3

.include <bsd.port.mk>
