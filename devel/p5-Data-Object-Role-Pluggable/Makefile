PORTNAME=	Data-Object-Role-Pluggable
PORTVERSION=	0.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Pluggable Role for Data::Object

LICENSE=	APACHE20

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Data-Object-Class>=2.02:devel/p5-Data-Object-Class \
		p5-Data-Object-Plugin>=0.01:devel/p5-Data-Object-Plugin \
		p5-Data-Object-Role>=2.01:devel/p5-Data-Object-Role \
		p5-Data-Object-Space>=2.00:devel/p5-Data-Object-Space \
		p5-routines>=0:devel/p5-routines
TEST_DEPENDS=	p5-Test-Auto>=0.07:devel/p5-Test-Auto

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
