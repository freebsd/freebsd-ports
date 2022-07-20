PORTNAME=	Data-Object-Role-Throwable
PORTVERSION=	2.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Throwable Role for Data::Object

LICENSE=	APACHE20

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Data-Object-Exception>=2.02:devel/p5-Data-Object-Exception \
		p5-Moo>=0:devel/p5-Moo \
		p5-routines>=0:devel/p5-routines
TEST_DEPENDS=	p5-Test-Auto>=0.05:devel/p5-Test-Auto

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
