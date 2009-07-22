# New ports collection makefile for:	Class-Autouse
# Date created:	   10 December 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Class-Autouse
PORTVERSION=	1.29
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Defer loading of one or more classes

RUN_DEPENDS=	${SITE_PERL}/prefork.pm:${PORTSDIR}/devel/p5-prefork
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Class::Autouse.3

.include <bsd.port.mk>
