# Created by: Frederic Culot <culot@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-CleanNamespaces
PORTVERSION=	0.16
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Check for uncleaned imports

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-File-Find-Rule>0:${PORTSDIR}/devel/p5-File-Find-Rule \
		p5-File-Find-Rule-Perl>0:${PORTSDIR}/devel/p5-File-Find-Rule-Perl \
		p5-Module-Runtime>0:${PORTSDIR}/devel/p5-Module-Runtime \
		p5-Package-Stash>=0.14:${PORTSDIR}/devel/p5-Package-Stash \
		p5-Sub-Exporter>0:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-Sub-Identify>0:${PORTSDIR}/devel/p5-Sub-Identify \
		p5-namespace-clean>0:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Requires>0:${PORTSDIR}/devel/p5-Test-Requires \
		p5-Test-Tester>0:${PORTSDIR}/devel/p5-Test-Tester \
		p5-Test-Warnings>=0.009:${PORTSDIR}/devel/p5-Test-Warnings

USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Test/CleanNamespaces/.packlist \
		%%SITE_PERL%%/Test/CleanNamespaces.pm \
		%%PERL5_MAN3%%/Test::CleanNamespaces.3.gz

PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Test/CleanNamespaces
PLIST_DIRSTRY=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Test \
		%%SITE_PERL%%/Test

.include <bsd.port.mk>
