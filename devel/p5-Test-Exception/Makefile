# New ports collection makefile for:    p5-Test-Exception
# Date created:				January 27th 2003
# Whom:	      				Erwin Lansing <erwin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Exception
PORTVERSION=	0.31
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Test::Exception - test functions for exception based code

RUN_DEPENDS=	p5-Sub-Uplevel>=0.18:${PORTSDIR}/devel/p5-Sub-Uplevel
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Test::Exception.3

.include <bsd.port.mk>
