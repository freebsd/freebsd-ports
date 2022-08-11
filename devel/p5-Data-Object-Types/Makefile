PORTNAME=	Data-Object-Types
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Data-Object Type Constraints for Data::Object

LICENSE=	APACHE20

USES=		perl5
USE_PERL5=	configure

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Type-Tiny>=0:devel/p5-Type-Tiny \
		p5-routines>=0:devel/p5-routines
TEST_DEPENDS=	p5-Test-Auto>=0.07:devel/p5-Test-Auto

NO_ARCH=	yes

.include <bsd.port.mk>
