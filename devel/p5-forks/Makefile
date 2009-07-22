# New ports collection makefile for:	p5-forks
# Date created:		2006-10-12
# Whom:			Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	forks
PORTVERSION=	0.33
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	SOAP/RYBSKEJ
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Drop-in replacement for Perl threads using fork()

RUN_DEPENDS=	${SITE_PERL}/reaper.pm:${PORTSDIR}/devel/p5-reaper \
		p5-Devel-Required>=0:${PORTSDIR}/devel/p5-Devel-Required \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		forks.3 forks::signals.3 \
		forks::shared.3 \
		forks::Devel::Symdump.3 \
		threads::shared::array.3 \
		threads::shared::handle.3 \
		threads::shared::hash.3 \
		threads::shared::scalar.3

.include <bsd.port.mk>
