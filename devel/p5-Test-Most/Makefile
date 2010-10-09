# New ports collection makefile for:	Test::Most
# Date created:		20 Feb 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Most
PORTVERSION=	0.23
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for most commonly needed test functions and features

RUN_DEPENDS=	\
	p5-Exception-Class>=1.14:${PORTSDIR}/devel/p5-Exception-Class \
	p5-Test-Deep>=0.106:${PORTSDIR}/devel/p5-Test-Deep \
	p5-Test-Differences>=0.500:${PORTSDIR}/devel/p5-Test-Differences \
	p5-Test-Exception>=0.29:${PORTSDIR}/devel/p5-Test-Exception \
	p5-Test-Warn>=0.11:${PORTSDIR}/devel/p5-Test-Warn
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Test::Most.3 \
	Test::Most::Exception.3

.include <bsd.port.mk>
