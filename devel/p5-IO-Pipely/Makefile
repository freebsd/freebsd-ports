# Created by: Mathieu Arnold
# $FreeBSD$

PORTNAME=	IO-Pipely
PORTVERSION=	0.005
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Portably create pipe() or pipe-like handles, one way or another

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Exporter>=5.68:${PORTSDIR}/devel/p5-Exporter
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Scalar-List-Utils>=1.29:${PORTSDIR}/lang/p5-Scalar-List-Utils

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.98:${PORTSDIR}/devel/p5-Test-Simple
.endif

.if ${PERL_LEVEL} < 501600
BUILD_DEPENDS+=	p5-base>=2.18:${PORTSDIR}/devel/p5-base
RUN_DEPENDS+=	p5-base>=2.18:${PORTSDIR}/devel/p5-base
TEST_DEPENDS+=	p5-Carp>=1.26:${PORTSDIR}/devel/p5-Carp
.endif

.include <bsd.port.post.mk>
