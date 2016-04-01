# Created by: Mons Anderson <mons@cpan.org>
# $FreeBSD$

PORTNAME=	uni-perl
PORTVERSION=	0.91
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MONS
PKGNAMEPREFIX=	p5-

MAINTAINER=	mons@cpan.org
COMMENT=	Modern perl with Unicode

RUN_DEPENDS=	p5-Encode>=2.37:converters/p5-Encode \
		p5-lib-abs>=0.90:devel/p5-lib-abs
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-NoWarnings>=0:devel/p5-Test-NoWarnings

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
