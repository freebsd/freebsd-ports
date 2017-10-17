# Created by: chinsan
# $FreeBSD$

PORTNAME=	Color-Library
PORTVERSION=	0.021
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easy-to-use and comprehensive named-color library

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Class-Data-Inheritable>=0:devel/p5-Class-Data-Inheritable
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Most>=0:devel/p5-Test-Most

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
