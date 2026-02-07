PORTNAME=	Data-Sah-Coerce
PORTVERSION=	0.054
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Coercion rules for Data::Sah
WWW=		https://metacpan.org/dist/Data-Sah-Coerce

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-IPC-System-Options>=0.339:devel/p5-IPC-System-Options \
		p5-JSON>=0:converters/p5-JSON \
		p5-JavaScript-QuickJS>=0:lang/p5-JavaScript-QuickJS \
		p5-Log-ger>=0.038:devel/p5-Log-ger \
		p5-Time-Duration-Parse-AsHash>=0:devel/p5-Time-Duration-Parse-AsHash \
		p5-subroutines>=0:devel/p5-subroutines
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Needs>=0:devel/p5-Test-Needs

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
