PORTNAME=	Class-Closure
PORTVERSION=	0.304
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Encapsulated, declarative classes in Perl
WWW=		https://metacpan.org/release/Class-Closure

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-PadWalker>=0:devel/p5-PadWalker \
		p5-Devel-Caller>=0:devel/p5-Devel-Caller \
		p5-Sentinel>=0:devel/p5-Sentinel

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
