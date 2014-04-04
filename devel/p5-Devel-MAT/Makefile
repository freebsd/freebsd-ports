# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Devel-MAT
PORTVERSION=	0.17
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl Memory Analysis Tool

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

# Module::Pluggable will be removed from core since Perl 5.20
BUILD_DEPENDS=	p5-File-ShareDir>=0:${PORTSDIR}/devel/p5-File-ShareDir \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-List-UtilsBy>=0:${PORTSDIR}/devel/p5-List-UtilsBy \
		p5-Module-Pluggable>=0:${PORTSDIR}/devel/p5-Module-Pluggable \
		p5-Scalar-List-Utils>=1.29:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Identity>=0:${PORTSDIR}/devel/p5-Test-Identity \
		p5-Test-Pod>=1:${PORTSDIR}/devel/p5-Test-Pod

USE_PERL5=	modbuild
USES=		perl5

.include <bsd.port.mk>
