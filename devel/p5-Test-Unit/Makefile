PORTNAME=	Test-Unit
PORTVERSION=	0.27
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	PerlUnit testing framework
WWW=		https://metacpan.org/release/Test-Unit

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Inner>=0:devel/p5-Class-Inner \
		p5-Devel-Symdump>=0:devel/p5-Devel-Symdump \
		p5-Error>=0:lang/p5-Error

USES=		perl5 shebangfix
SHEBANG_FILES=	TestLister.pl
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
