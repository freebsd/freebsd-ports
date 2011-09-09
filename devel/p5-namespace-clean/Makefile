# New ports collection makefile for:	devel/p5-namespace-clean
# Date created:				23 Jul 2008
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	namespace-clean
PORTVERSION=	0.21
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RIBASUSHI
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Keep imports and functions out of your namespace

COMMON_DEPENDS=	p5-B-Hooks-EndOfScope>=0.07:${PORTSDIR}/devel/p5-B-Hooks-EndOfScope \
		p5-Package-Stash>=0.23:${PORTSDIR}/devel/p5-Package-Stash
BUILD_DEPENDS=	${COMMON_DEPENDS}
RUN_DEPENDS=	${COMMON_DEPENDS}
TEST_DEPENDS=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=	namespace::clean.3

.include <bsd.port.mk>
