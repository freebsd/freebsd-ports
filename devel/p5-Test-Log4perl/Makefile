# New ports collection makefile for:	p5-Test-Log4perl
# Date created:				August 27, 2007
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Log4perl
PORTVERSION=	0.1001
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Test::Log4perl - test Log::Log4perl

BUILD_DEPENDS=	${SITE_PERL}/Test/Exception.pm:${PORTSDIR}/devel/p5-Test-Exception \
		${SITE_PERL}/Lingua/EN/Numbers/Ordinate.pm:${PORTSDIR}/textproc/p5-Lingua-EN-Numbers-Ordinate \
		${SITE_PERL}/Class/Accessor/Chained.pm:${PORTSDIR}/devel/p5-Class-Accessor-Chained \
		${SITE_PERL}/Log/Log4perl.pm:${PORTSDIR}/devel/p5-Log-Log4perl
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Test::Log4perl.3

.include <bsd.port.mk>
