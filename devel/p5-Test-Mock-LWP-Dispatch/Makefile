PORTNAME=	Test-Mock-LWP-Dispatch
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Mocks LWP::UserAgent and dispatches your requests/responses

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-Test-MockObject>=0:devel/p5-Test-MockObject \
		p5-libwww>=0:www/p5-libwww
TEST_DEPENDS=	p5-Moose>=0:devel/p5-Moose \
		p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
