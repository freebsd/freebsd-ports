PORTNAME=	Data-Serializer
PORTVERSION=	0.65
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Modules that serialize data structures

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/README

TEST_DEPENDS=	p5-Bencode>=0:converters/p5-Bencode \
		p5-Config-General>=0:devel/p5-Config-General \
		p5-Convert-Bencode_XS>=0:converters/p5-Convert-Bencode_XS \
		p5-Crypt-Blowfish>=0:security/p5-Crypt-Blowfish \
		p5-Crypt-CBC>=0:security/p5-Crypt-CBC \
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
		p5-FreezeThaw>=0:devel/p5-FreezeThaw \
		p5-JSON>=0:converters/p5-JSON \
		p5-MD5>=0:security/p5-MD5 \
		p5-PHP-Serialization>=0:devel/p5-PHP-Serialization \
		p5-Test-Kwalitee>=0:devel/p5-Test-Kwalitee \
		p5-Test-Pod>=0:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:devel/p5-Test-Pod-Coverage \
		p5-XML-Dumper>=0:textproc/p5-XML-Dumper \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		p5-YAML>=0:textproc/p5-YAML \
		p5-YAML-Syck>=0:textproc/p5-YAML-Syck

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
