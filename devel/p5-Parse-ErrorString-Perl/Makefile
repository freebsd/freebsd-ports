# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	Parse-ErrorString-Perl
PORTVERSION=	0.27
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Parse error messages from the Perl interpreter

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-XSAccessor>0:devel/p5-Class-XSAccessor \
		p5-Module-Install>0:devel/p5-Module-Install \
		p5-Pod-POM>=0.27:textproc/p5-Pod-POM
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Differences>0:devel/p5-Test-Differences

NO_ARCH=	YES
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
