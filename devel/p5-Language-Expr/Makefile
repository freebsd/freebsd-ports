PORTNAME=	Language-Expr
PORTVERSION=	0.29
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple minilanguage for use in expression
WWW=		https://metacpan.org/dist/Language-Expr

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-Mo>=0:devel/p5-Mo \
		p5-Nodejs-Util>=0.006:www/p5-Nodejs-Util \
		p5-Regexp-Grammars>=1.005:devel/p5-Regexp-Grammars \
		p5-Role-Tiny>=0:devel/p5-Role-Tiny \
		p5-UUID-Tiny>=0:devel/p5-UUID-Tiny \
		p5-boolean>=0.20:devel/p5-boolean
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
