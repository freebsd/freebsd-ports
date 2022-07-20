PORTNAME=	Data-Object-Role-Errable
PORTVERSION=	0.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Errable Role for Data::Object

LICENSE=	APACHE20

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Data-Object-Exception>=2.02:devel/p5-Data-Object-Exception \
		p5-Data-Object-Role>=2.01:devel/p5-Data-Object-Role \
		p5-Data-Object-Role-Tryable>=2.00:devel/p5-Data-Object-Role-Tryable \
		p5-Data-Object-RoleHas>=2.01:devel/p5-Data-Object-RoleHas \
		p5-Data-Object-Types>=0.04:devel/p5-Data-Object-Types \
		p5-routines>=0:devel/p5-routines
TEST_DEPENDS=	p5-Test-Auto>=0.10:devel/p5-Test-Auto

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
