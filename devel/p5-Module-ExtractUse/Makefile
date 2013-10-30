# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Module-ExtractUse
PORTVERSION=	0.32
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Find out what CPAN modules are used

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Pod-Strip>=0:${PORTSDIR}/textproc/p5-Pod-Strip \
		p5-Parse-RecDescent>=1.967:${PORTSDIR}/devel/p5-Parse-RecDescent
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-UNIVERSAL-require>=0.11:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		p5-Test-Deep>0:${PORTSDIR}/devel/p5-Test-Deep

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.98:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
