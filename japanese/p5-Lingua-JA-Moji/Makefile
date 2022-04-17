PORTNAME=	Lingua-JA-Moji
PORTVERSION=	0.59
CATEGORIES=	japanese perl5
MASTER_SITES=	CPAN

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to handle many kinds of Japanese characters

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Convert-Moji>=0.05:converters/p5-Convert-Moji \
		p5-JSON-Parse>=0.61:devel/p5-JSON-Parse

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

.include <bsd.port.post.mk>
