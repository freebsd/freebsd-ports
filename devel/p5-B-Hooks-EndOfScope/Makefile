# New ports collection makefile for:	devel/p5-B-Hooks-EndOfScope
# Date created:				26 Oct 2008
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	B-Hooks-EndOfScope
PORTVERSION=	0.10
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Execute code after a scope finished compilation

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Variable-Magic>=0.34:${PORTSDIR}/devel/p5-Variable-Magic \
		p5-Sub-Exporter>0:${PORTSDIR}/devel/p5-Sub-Exporter
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	B::Hooks::EndOfScope.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
TEST_DEPENDS+=	p5-Test-Simple>=0.89:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
