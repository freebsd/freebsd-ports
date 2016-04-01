# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Inline
PORTVERSION=	0.80
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:INGY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Write Perl subroutines in other programming languages

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Parse-RecDescent>=1.800:devel/p5-Parse-RecDescent
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Inline-Files>=0:devel/p5-Inline-Files \
		p5-Test-Warn>=0.23:devel/p5-Test-Warn

PORTSCOUT=	limit:^[0-9\.]*$$

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
