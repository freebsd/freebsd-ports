# New ports collection makefile for:	p5-Test-MockObject
# Date Created:				16 Jul, 2003
# Whom:					Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-MockObject
PORTVERSION=	0.12
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Tests remote URLs or local web files

BUILD_DEPENDS=	${SITE_PERL}/Test/Builder.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Test::MockObject.3

.include <bsd.port.mk>
