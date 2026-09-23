PORTNAME=	Test-YAML-Meta
DISTVERSION=	0.22
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BARBIE
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Validation of the META.yml file in a distribution
WWW=		https://metacpan.org/release/Test-YAML-Meta

LICENSE=	ART20

DEPRECATED=	Upstream deprecated
EXPIRATION_DATE=	2026-10-23

BUILD_RUN_DEPENDS=	p5-Test-YAML-Valid>=0:devel/p5-Test-YAML-Valid \
		p5-Test-CPAN-Meta-YAML>=0.17:devel/p5-Test-CPAN-Meta-YAML

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
