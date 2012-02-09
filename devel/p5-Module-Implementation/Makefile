# New ports collection makefile for:	p5-Module-Implementation
# Date created:		2012-02-07
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Module-Implementation
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Loads one of several alternate underlying implementations for a module

BUILD_DEPENDS=	p5-Module-Runtime>=0.011:${PORTSDIR}/devel/p5-Module-Runtime \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny
RUN_DEPENDS=	p5-Module-Runtime>=0.011:${PORTSDIR}/devel/p5-Module-Runtime \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny

TEST_DEPENDS=	p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-NoTabs>=0:${PORTSDIR}/devel/p5-Test-NoTabs \
		p5-Test-Taint>=0:${PORTSDIR}/devel/p5-Test-Taint

PERL_CONFIGURE=	yes

MAN3=		Module::Implementation.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
TEST_DEPENDS+=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
