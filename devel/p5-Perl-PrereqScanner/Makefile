# Created by: Geraud CONTINSOUZAS <geraud@gcu.info>
# $FreeBSD$

PORTNAME=	Perl-PrereqScanner
PORTVERSION=	1.018
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	geraud@gcu.info
COMMENT=	A tool to scan your Perl code for its prerequisites

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-CPAN-Meta>=2.120630:${PORTSDIR}/devel/p5-CPAN-Meta \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-PPI>=1.215:${PORTSDIR}/textproc/p5-PPI \
		p5-Params-Util>=0:${PORTSDIR}/devel/p5-Params-Util \
		p5-String-RewritePrefix>=0.005:${PORTSDIR}/textproc/p5-String-RewritePrefix \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean \
		p5-Getopt-Long-Descriptive>=0:${PORTSDIR}/devel/p5-Getopt-Long-Descriptive \
		p5-Module-Path>=0:${PORTSDIR}/devel/p5-Module-Path
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
