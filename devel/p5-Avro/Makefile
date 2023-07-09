PORTNAME=	Avro
PORTVERSION=	1.11.2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RSKRABA
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Official Perl API for the Apache Avro
WWW=		https://metacpan.org/dist/Avro

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Compress-Zstd>=0:archivers/p5-Compress-Zstd \
		p5-Error>=0:lang/p5-Error \
		p5-IO-String>=0:devel/p5-IO-String \
		p5-JSON-XS>=0:converters/p5-JSON-XS \
		p5-Object-Tiny>=0:devel/p5-Object-Tiny \
		p5-Regexp-Common>=0:textproc/p5-Regexp-Common \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny
TEST_DEPENDS=	p5-Perl-Critic>=0:textproc/p5-Perl-Critic \
		p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
