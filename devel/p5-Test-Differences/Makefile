# New ports collection makefile for:    p5-Test-Differences
# Date created:				January 28th 2003
# Whom:	      				Erwin Lansing <erwin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Differences
PORTVERSION=	0.4801
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Test::Differences - Test strings and data structures for differences

BUILD_DEPENDS=	${SITE_PERL}/Text/Diff.pm:${PORTSDIR}/textproc/p5-Text-Diff
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Test::Differences.3

.include <bsd.port.mk>
