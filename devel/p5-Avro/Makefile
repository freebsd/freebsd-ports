PORTNAME=	Avro
PORTVERSION=	1.12.0
CATEGORIES=	devel perl5
#MASTER_SITES=	CPAN
#MASTER_SITE_SUBDIR=	CPAN:RSKRABA
MASTER_SITES=	APACHE/avro/avro-${PORTVERSION}/perl
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Official Perl API for the Apache Avro
WWW=		https://metacpan.org/dist/Avro \
		https://avro.apache.org/ \
		https://github.com/apache/avro

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Module-Install>=0:devel/p5-Module-Install \
		p5-Module-Install-ReadmeFromPod>=0:devel/p5-Module-Install-ReadmeFromPod \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-Compress-Zstd>=0:archivers/p5-Compress-Zstd \
		p5-Error>=0:lang/p5-Error \
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-Object-Tiny>=0:devel/p5-Object-Tiny \
		p5-Regexp-Common>=0:textproc/p5-Regexp-Common \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny
TEST_DEPENDS=	p5-Perl-Critic>=0:textproc/p5-Perl-Critic \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Pod>=0:devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
