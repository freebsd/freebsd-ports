# New ports collection makefile for:	p5-Test-Strict
# Date Created:				27 Dec 2005
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	Test-Strict
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	Test and report on use strict/warnings coverage

RUN_DEPENDS=	p5-Devel-Cover>=0.43:${PORTSDIR}/devel/p5-Devel-Cover

PERL_CONFIGURE=	yes

MAN3=	Test::Strict.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.1 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
