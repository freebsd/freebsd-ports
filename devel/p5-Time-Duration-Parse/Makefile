# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Time-Duration-Parse
PORTVERSION=	0.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Parse string that represents time duration

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Exporter-Lite>=0.02:${PORTSDIR}/devel/p5-Exporter-Lite
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Simple>=0.99:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Time-Duration>=1.0.6:${PORTSDIR}/devel/p5-Time-Duration

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
