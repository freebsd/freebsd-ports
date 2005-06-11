# New ports collection makefile for:	p5-Test-Reporter
# Date created:				Sat Dec 20 23:11:45 CET 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	Test-Reporter
PORTVERSION=	1.27
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Sends test results to cpan-testers@perl.org

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools \
		${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp \
		${SITE_PERL}/Net/SMTP.pm:${PORTSDIR}/net/p5-Net
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		cpantest.1
MAN3=		Test::Reporter.3 \
		Test::Reporter::Date::Format.3 \
		Test::Reporter::Mail::Util.3 \
		Test::Reporter::Time::Zone.3

.include <bsd.port.mk>
