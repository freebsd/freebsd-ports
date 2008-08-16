# New ports collection makefile for:	Test-Memory-Cycle
# Date created:	   16 Aug 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Test-Memory-Cycle
PORTVERSION=	1.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Check for memory leaks and circular memory references

BUILD_DEPENDS=	${SITE_PERL}/Devel/Cycle.pm:${PORTSDIR}/devel/p5-Devel-Cycle \
		${SITE_PERL}/${PERL_ARCH}/PadWalker.pm:${PORTSDIR}/devel/p5-PadWalker \
		${SITE_PERL}/Test/Simple.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Test::Memory::Cycle.3

.include <bsd.port.mk>
