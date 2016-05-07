# Created by: Baptiste Daroussin
# $FreeBSD$

PORTNAME=	Config-GitLike
PORTVERSION=	1.16
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ALEXMV
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple git-compatible config file parser for Perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	devel/p5-Moo>=0:devel/p5-Moo \
		devel/p5-MooX-Types-MooseLike>=0:devel/p5-MooX-Types-MooseLike
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS+=	devel/p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
