# New ports collection makefile for:    p5-Test-Class
# Date created:				January 27th 2003
# Whom:	      				Erwin Lansing <erwin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Class
PORTVERSION=	0.31
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Test::Class - Easily create test classes in an xUnit style

RUN_DEPENDS=	p5-Devel-Symdump>=2.03:${PORTSDIR}/devel/p5-Devel-Symdump \
		p5-Test-Exception>=0.25:${PORTSDIR}/devel/p5-Test-Exception

PERL_MODBUILD=	yes

MAN3=		Test::Class.3 \
		Test::Class::Load.3 \
		Test::Class::MethodInfo.3

.include <bsd.port.mk>
