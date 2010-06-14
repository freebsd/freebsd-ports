# New ports collection makefile for:	devel/p5-namespace-clean
# Date created:				23 Jul 2008
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	namespace-clean
PORTVERSION=	0.18
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Keep imports and functions out of your namespace

BUILD_DEPENDS=	p5-B-Hooks-EndOfScope>=0.07:${PORTSDIR}/devel/p5-B-Hooks-EndOfScope \
		p5-Sub-Identify>=0.04:${PORTSDIR}/devel/p5-Sub-Identify \
		p5-Sub-Name>=0.04:${PORTSDIR}/devel/p5-Sub-Name
RUN_DEPENDS=	p5-B-Hooks-EndOfScope>=0.07:${PORTSDIR}/devel/p5-B-Hooks-EndOfScope \
		p5-Sub-Identify>=0.04:${PORTSDIR}/devel/p5-Sub-Identify \
		p5-Sub-Name>=0.04:${PORTSDIR}/devel/p5-Sub-Name \
		p5-Package-Stash>=0.03:${PORTSDIR}/devel/p5-Package-Stash
TEST_DEPENDS=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	5.8.0+

MAN3=	namespace::clean.3

post-extract:
	@${PERL} -i -ne 'print unless m,build_requires,' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
