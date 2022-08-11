PORTNAME=	Data-Object-Vars
PORTVERSION=	2.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Stashable Role for Data::Object

LICENSE=	APACHE20

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Data-Object-Class>=2.02:devel/p5-Data-Object-Class \
		p5-Data-Object-ClassHas>=2.01:devel/p5-Data-Object-ClassHas \
		p5-Data-Object-Role-Buildable>=0.02:devel/p5-Data-Object-Role-Buildable \
		p5-Data-Object-Role-Proxyable>=2.03:devel/p5-Data-Object-Role-Proxyable \
		p5-Data-Object-Role-Stashable>=2.01:devel/p5-Data-Object-Role-Stashable
TEST_DEPENDS=	p5-Test-Auto>=0.10:devel/p5-Test-Auto

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
