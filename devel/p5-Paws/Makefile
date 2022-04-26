PORTNAME=	Paws
PORTVERSION=	0.44
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JLMARTIN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension of SDK for AWS (Amazon Web Services) APIs

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-ARGV-Struct>=0:devel/p5-ARGV-Struct \
		p5-Config-AWS>=0:devel/p5-Config-AWS \
		p5-Data-Compare>=0:devel/p5-Data-Compare \
		p5-DataStruct-Flat>=0:devel/p5-DataStruct-Flat \
		p5-DateTime>=0:devel/p5-DateTime \
		p5-DateTime-Format-ISO8601>=0:devel/p5-DateTime-Format-ISO8601 \
		p5-File-HomeDir>=0:devel/p5-File-HomeDir \
		p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL \
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-Module-Find>=0:devel/p5-Module-Find \
		p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-ClassAttribute>=0:devel/p5-MooseX-ClassAttribute \
		p5-MooseX-Getopt>=0:devel/p5-MooseX-Getopt \
		p5-Net-Amazon-Signature-V4>=0:net/p5-Net-Amazon-Signature-V4 \
		p5-Path-Tiny>=0.017:devel/p5-Path-Tiny \
		p5-String-CRC32>=0:devel/p5-String-CRC32 \
		p5-Throwable>=0:devel/p5-Throwable \
		p5-URI-Template>=0.23:net/p5-URI-Template \
		p5-URI>=0:net/p5-URI \
		p5-URL-Encode-XS>=0:www/p5-URL-Encode-XS \
		p5-URL-Encode>=0:www/p5-URL-Encode \
		p5-XML-Simple>=2.21:textproc/p5-XML-Simple
TEST_DEPENDS=	p5-Class-Unload>=0:devel/p5-Class-Unload \
		p5-File-Slurper>=0:devel/p5-File-Slurper \
		p5-Path-Class>=0:devel/p5-Path-Class \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Timer>=0:devel/p5-Test-Timer \
		p5-Test-Warnings>=0:devel/p5-Test-Warnings \
		p5-YAML>=0:textproc/p5-YAML

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

.include <bsd.port.mk>
