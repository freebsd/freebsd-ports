PORTNAME=	Graphics-ColorNames
DISTVERSIONPREFIX=	v
DISTVERSION=	3.5.0
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RRWO
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl class that defines RGB values for common color names
WWW=		https://metacpan.org/release/Graphics-ColorNames

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Color-Library>=0:graphics/p5-Color-Library \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Most>=0:devel/p5-Test-Most \
		p5-Tie-Sub>=0/:devel/p5-Tie-Sub

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
