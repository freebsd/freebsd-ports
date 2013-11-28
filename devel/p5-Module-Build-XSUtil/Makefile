# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Module-Build-XSUtil
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Module::Build class for building XS modules

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Devel-CheckCompiler>=0.02:${PORTSDIR}/devel/p5-Devel-CheckCompiler
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	modbuild
USES=		perl5

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
BUILD_DEPENDS+=	p5-CPAN-Meta>=0:${PORTSDIR}/devel/p5-CPAN-Meta \
		p5-Devel-PPPort>=3.19:${PORTSDIR}/devel/p5-Devel-PPPort
RUN_DEPENDS+=	p5-Devel-PPPort>=3.19:${PORTSDIR}/devel/p5-Devel-PPPort
TEST_DEPENDS+=	p5-Test-Simple>=0.98:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
