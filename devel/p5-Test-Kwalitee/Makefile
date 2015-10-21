# Created by: Felippe de Meirelles Motta <lippemail@gmail.com>
# $FreeBSD$

PORTNAME=	Test-Kwalitee
PORTVERSION=	1.22
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Test the Kwalitee of a distribution before you release it

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Module-CPANTS-Analyse>=0.92:${PORTSDIR}/devel/p5-Module-CPANTS-Analyse \
		p5-namespace-clean>0:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-CPAN-Meta-Check>=0.007:${PORTSDIR}/devel/p5-CPAN-Meta-Check \
		p5-Test-Deep>0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Warnings>=0.009:${PORTSDIR}/devel/p5-Test-Warnings

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
