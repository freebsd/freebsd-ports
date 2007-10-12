# New ports collection makefile for:	p5-Test-Reporter
# Date created:				Sat Dec 20 23:11:45 CET 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	Test-Reporter
PORTVERSION=	1.38
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Sends test results to cpan-testers@perl.org

RUN_DEPENDS=	p5-PathTools>0:${PORTSDIR}/devel/p5-PathTools \
		p5-File-Temp>0:${PORTSDIR}/devel/p5-File-Temp \
		p5-Net>0:${PORTSDIR}/net/p5-Net
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		cpantest.1
MAN3=		Test::Reporter.3

.include <bsd.port.mk>
