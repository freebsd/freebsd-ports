PORTNAME=	Test-Metrics-Any
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PEVANS
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Assert that code produces metrics via Metrics::Any
WWW=		https://metacpan.org/release/Test-Metrics-Any

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Metrics-Any>=0:devel/p5-Metrics-Any

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

.include <bsd.port.mk>
