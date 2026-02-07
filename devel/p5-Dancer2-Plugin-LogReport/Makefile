PORTNAME=	Dancer2-Plugin-LogReport
PORTVERSION=	2.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MARKOV
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Logging, exceptions and translations in Dancer2 via Log::Report
WWW=		https://metacpan.org/dist/Dancer2-Plugin-LogReport

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Dancer2>=0.207:www/p5-Dancer2 \
		p5-Log-Report>=1.42:devel/p5-Log-Report \
		p5-Log-Report-Template>=0:devel/p5-Log-Report-Template

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
