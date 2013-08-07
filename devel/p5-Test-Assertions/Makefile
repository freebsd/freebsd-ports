# New ports collection makefile for:	devel/p5-Test-Assertions
# Date created:				27 May 2007
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Assertions
PORTVERSION=	1.054
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	A simple set of building blocks for both unit and runtime testing

RUN_DEPENDS=	p5-Log-Trace>0:${PORTSDIR}/devel/p5-Log-Trace
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Test::Assertions.3 \
	Test::Assertions::Manual.3 \
	Test::Assertions::TestScript.3

.include <bsd.port.mk>
