# New ports collection makefile for:	devel/p5-Devel-GlobalDestruction
# Date created:				3 Sep 2008
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Devel-GlobalDestruction
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Expose PL_dirty, the flag which marks global destruction

RUN_DEPENDS=	p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-Scope-Guard>=0:${PORTSDIR}/devel/p5-Scope-Guard
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	Devel::GlobalDestruction.3

.include <bsd.port.mk>
