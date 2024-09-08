PORTNAME=	Data-Sah-DefaultValue
PORTVERSION=	0.005
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Default-value rules for Data::Sah
WWW=		https://metacpan.org/dist/Data-Sah-DefaultValue

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+  =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Data-Dmp>=0.242:devel/p5-Data-Dmp \
		p5-IPC-System-Options>=0.339:devel/p5-IPC-System-Options \
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-Log-ger>=0.038:devel/p5-Log-ger \
		p5-Nodejs-Util>=0.007:www/p5-Nodejs-Util
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Needs>=0:devel/p5-Test-Needs

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
