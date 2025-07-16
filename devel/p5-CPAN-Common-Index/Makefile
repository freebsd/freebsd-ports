PORTNAME=	CPAN-Common-Index
PORTVERSION=	0.010
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAGOLDEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	root@dc365.ru
COMMENT=	Common library for searching CPAN modules, authors and distributions
WWW=		https://metacpan.org/dist/CPAN-Common-Index

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-CPAN-DistnameInfo>=0:devel/p5-CPAN-DistnameInfo \
		p5-Class-Tiny>=0:devel/p5-Class-Tiny \
		p5-Tie-Handle-Offset>=0:textproc/p5-Tie-Handle-Offset \
		p5-URI>=0:net/p5-URI
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-FailWarnings>=0:devel/p5-Test-FailWarnings \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal

USES=		localbase perl5
USE_PERL5=	configure test

NO_ARCH=	yes

.include <bsd.port.mk>
