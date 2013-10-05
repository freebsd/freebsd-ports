# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Getopt-Long-Descriptive
PORTVERSION=	0.096
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Getopt::Long with usage text

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Params-Validate>=0.97:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Sub-Exporter>=0.972:${PORTSDIR}/devel/p5-Sub-Exporter
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-Warnings>=0.005:${PORTSDIR}/devel/p5-Test-Warnings

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.96:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
