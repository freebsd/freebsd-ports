PORTNAME=	Lingua-JA-Moji
PORTVERSION=	0.60
CATEGORIES=	japanese perl5
MASTER_SITES=	CPAN

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to handle many kinds of Japanese characters
WWW=		https://metacpan.org/release/Lingua-JA-Moji

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Convert-Moji>=0.11:converters/p5-Convert-Moji \
		p5-JSON-Parse>=0.62:devel/p5-JSON-Parse

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

.include <bsd.port.post.mk>
