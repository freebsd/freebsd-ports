# New ports collection makefile for:	p5-XML-Compile-Tester
# Date created:		2009-01-11
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	XML-Compile-Tester
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Support XML::Compile Related Regression Testing

RUN_DEPENDS=	p5-Log-Report>=0.17:${PORTSDIR}/devel/p5-Log-Report \
		p5-Test-Deep>=0.103:${PORTSDIR}/devel/p5-Test-Deep \
		${SITE_PERL}/Test/Simple.pm:${PORTSDIR}/devel/p5-Test-Simple
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	XML::Compile::Tester.3

.include <bsd.port.mk>
