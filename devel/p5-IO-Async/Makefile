PORTNAME=	IO-Async
PORTVERSION=	0.803
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PEVANS
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl modules that implement asynchronous filehandle IO
WWW=		https://metacpan.org/release/IO-Async

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Future>=0.44:devel/p5-Future \
		p5-Struct-Dumb>0:devel/p5-Struct-Dumb
TEST_DEPENDS=	p5-Future-IO>=0:devel/p5-Future-IO \
		p5-Test-Metrics-Any>=0:devel/p5-Test-Metrics-Any \
		p5-Test-Pod>=1:devel/p5-Test-Pod \
		p5-Test-Simple>=1.302200:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

.include <bsd.port.mk>
