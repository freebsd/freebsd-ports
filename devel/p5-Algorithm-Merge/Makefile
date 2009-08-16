# New ports collection makefile for:	devel/p5-Algorithm-Merge
# Date created:				29 Mar 2009
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Algorithm-Merge
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Three-way merge and diff

RUN_DEPENDS=	p5-Algorithm-Diff>=1.15:${PORTSDIR}/devel/p5-Algorithm-Diff
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Algorithm::Merge.3

.include <bsd.port.mk>
