# New ports collection makefile for:	p5-Test-Mock-LWP
# Date created:		2009-03-13
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Mock-LWP
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kaoru@kaisei.org
COMMENT=	Easy mocking of LWP packages

RUN_DEPENDS=	p5-Test-MockObject>=1.08:${PORTSDIR}/devel/p5-Test-MockObject

PERL_CONFIGURE=	5.6.2+

MAN3=		Test::Mock::HTTP::Request.3 \
		Test::Mock::HTTP::Response.3 \
		Test::Mock::LWP::UserAgent.3 \
		Test::Mock::LWP.3

.include <bsd.port.mk>
