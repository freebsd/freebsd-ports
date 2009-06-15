# New ports collection makefile for:	devel/p5-B-Hooks-EndOfScope
# Date created:				26 Oct 2008
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	B-Hooks-EndOfScope
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Execute code after a scope finished compilation

RUN_DEPENDS=	p5-Variable-Magic>=0.31:${PORTSDIR}/devel/p5-Variable-Magic \
		p5-Sub-Exporter>0:${PORTSDIR}/devel/p5-Sub-Exporter
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	B::Hooks::EndOfScope.3

.include <bsd.port.mk>
