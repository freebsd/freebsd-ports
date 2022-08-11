PORTNAME=	Data-Object-Opts
PORTVERSION=	2.00
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Opts Class for Data::Object

LICENSE=	APACHE20

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Data-Object-Class>=2.02:devel/p5-Data-Object-Class \
		p5-Data-Object-ClassHas>=2.01:devel/p5-Data-Object-ClassHas \
		p5-Data-Object-Role-Buildable>=0.02:devel/p5-Data-Object-Role-Buildable \
		p5-Data-Object-Role-Proxyable>=2.03:devel/p5-Data-Object-Role-Proxyable \
		p5-Data-Object-Role-Stashable>=2.01:devel/p5-Data-Object-Role-Stashable \
		p5-routines>=0:devel/p5-routines
TEST_DEPENDS=	p5-Test-Auto>=0.10:devel/p5-Test-Auto

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
