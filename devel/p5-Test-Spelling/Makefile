# New ports collection makefile for:	p5-Test-Spelling
# Date Created:				22 Apr 2008
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Spelling
PORTVERSION=	0.11
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Check for spelling errors in POD files

BUILD_DEPENDS=	${SITE_PERL}/Pod/Spell.pm:${PORTSDIR}/textproc/p5-Pod-Spell
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

MAN3=		Test::Spelling.3

.include <bsd.port.mk>
