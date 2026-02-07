PORTNAME=	AnyEvent-Connector
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	tcp_connect with transparent proxy handling
WWW=		https://metacpan.org/dist/AnyEvent-Connector

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Module-Build-Prereqs-FromCPANfile>=0.02:devel/p5-Module-Build-Prereqs-FromCPANfile \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-AnyEvent>=0:devel/p5-AnyEvent \
		p5-URI>=0:net/p5-URI
TEST_DEPENDS=	p5-Test-TCP>=0:devel/p5-Test-TCP

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

.include <bsd.port.mk>
