# New ports collection makefile for:	p5-Carp-Assert-More
# Date created:				13 Jun 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Carp-Assert-More
PORTVERSION=	1.12
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convenience wrappers around Carp::Assert

BUILD_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception
RUN_DEPENDS=	p5-Carp-Assert>=0:${PORTSDIR}/devel/p5-Carp-Assert

MAN3=	Carp::Assert::More.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
