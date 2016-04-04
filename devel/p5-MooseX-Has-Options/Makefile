# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MooseX-Has-Options
PORTVERSION=	0.003
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	MooseX::Has::Options - Succinct options for Moose

BUILD_DEPENDS=	p5-Class-Load>=0:devel/p5-Class-Load \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Package-Stash>=0.18:devel/p5-Package-Stash \
		p5-String-RewritePrefix>=0:textproc/p5-String-RewritePrefix \
		p5-Moose>=0:devel/p5-Moose \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Most>=0:devel/p5-Test-Most

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
