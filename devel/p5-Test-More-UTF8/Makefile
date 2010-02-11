# New ports collection makefile for:	devel/p5-Test-More-UTF8
# Date created:				11 Feb 2010
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-More-UTF8
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Enhancing Test::More for UTF8-based projects

BUILD_DEPENDS=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/ex/lib.pm:${PORTSDIR}/devel/p5-ex-lib
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Test::More::UTF8.3

.include <bsd.port.mk>
