# New ports collection makefile for:	p5-forks
# Date created:		2006-10-12
# Whom:			Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	forks
PORTVERSION=	0.22
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/R/RY/RYBSKEJ
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Drop-in replacement for Perl threads using fork()

RUN_DEPENDS=	${SITE_PERL}/reaper.pm:${PORTSDIR}/devel/p5-reaper
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		forks.3 forks::shared.3 \
		threads::shared::array.3 \
		threads::shared::handle.3 \
		threads::shared::hash.3 \
		threads::shared::scalar.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.0 or later. Install lang/perl5.8 then try again
.endif

.if ${PERL_LEVEL} < 500702
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils
.endif

.include <bsd.port.post.mk>
