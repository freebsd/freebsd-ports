# ex:ts=8
# New ports collection makefile for:	p5-Exception-Class
# Date created:			Jul 28, 2001
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	Exception-Class
PORTVERSION=	1.29
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A module that allows you to declare real exception classes in Perl

RUN_DEPENDS=	p5-Class-Data-Inheritable>=0.02:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-Devel-StackTrace>=1.20:${PORTSDIR}/devel/p5-Devel-StackTrace
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=		Exception::Class.3 Exception::Class::Base.3

.include <bsd.port.mk>
