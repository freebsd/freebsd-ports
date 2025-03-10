PORTNAME=	Convert-PEM
PORTVERSION=	0.13
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Read/write access to ASN.1-encoded PEM files with optional encryption
WWW=		https://metacpan.org/release/Convert-PEM

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-ErrorHandler>=0:devel/p5-Class-ErrorHandler \
		p5-Convert-ASN1>=0.34:converters/p5-Convert-ASN1 \
		p5-Crypt-DES_EDE3>=0:security/p5-Crypt-DES_EDE3 \
		p5-CryptX>=0:security/p5-CryptX
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
