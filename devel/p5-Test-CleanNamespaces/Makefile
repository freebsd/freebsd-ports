# Created by: Frederic Culot <culot@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-CleanNamespaces
PORTVERSION=	0.18
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Check for uncleaned imports

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-File-Find-Rule>0:devel/p5-File-Find-Rule \
		p5-File-Find-Rule-Perl>0:devel/p5-File-Find-Rule-Perl \
		p5-Module-Runtime>0:devel/p5-Module-Runtime \
		p5-Package-Stash>=0.14:devel/p5-Package-Stash \
		p5-Sub-Exporter>0:devel/p5-Sub-Exporter \
		p5-Sub-Identify>0:devel/p5-Sub-Identify \
		p5-namespace-clean>0:devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>0:devel/p5-Test-Deep \
		p5-Test-Requires>0:devel/p5-Test-Requires \
		p5-Test-Warnings>=0.009:devel/p5-Test-Warnings

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	%%SITE_PERL%%/Test/CleanNamespaces.pm \
		%%PERL5_MAN3%%/Test::CleanNamespaces.3.gz

.include <bsd.port.mk>
