# New ports collection makefile for:	p5-Test-Simple
# Date Created:				12 Aug 2001
# Whom:					Shell Hung <shell@shellhung.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Simple
PORTVERSION=	0.47
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	shell@shellhung.org

BUILD_DEPENDS=	${SITE_PERL}/Test/Harness.pm:${PORTSDIR}/devel/p5-Test-Harness
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
MAN3=		Test::More.3 Test::Simple.3 Test::Tutorial.3 \
		Test::Builder.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
