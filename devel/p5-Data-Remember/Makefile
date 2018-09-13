# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Data-Remember
PORTVERSION=	0.140490
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Remember complex information without giving yourself a headache

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Load>=0:devel/p5-Class-Load \
		p5-DBM-Deep>=0:databases/p5-DBM-Deep \
		p5-Sub-Exporter>=0:devel/p5-Sub-Exporter \
		p5-YAML-Syck>=0:textproc/p5-YAML-Syck
TEST_DEPENDS=	p5-POE>=0:devel/p5-POE

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
