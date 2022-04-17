PORTNAME=	AnyEvent-MessagePack
PORTVERSION=	0.20
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension of AnyEvent for MessagePack

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-AnyEvent>=7.02,1:devel/p5-AnyEvent \
		p5-Data-MessagePack>=0.46:devel/p5-Data-MessagePack \
		p5-Data-MessagePack-Stream>=0.07:devel/p5-Data-MessagePack-Stream
TEST_DEPENDS=	p5-Test-Requires>=0:devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

.include <bsd.port.mk>
