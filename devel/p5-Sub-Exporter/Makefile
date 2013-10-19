# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Sub-Exporter
PORTVERSION=	0.987
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Sophisticated exporter for custom-built routines

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Data-OptList>=0.100:${PORTSDIR}/devel/p5-Data-OptList \
		p5-Params-Util>=0.14:${PORTSDIR}/devel/p5-Params-Util \
		p5-Sub-Install>=0.920:${PORTSDIR}/devel/p5-Sub-Install
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.96:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
