# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Data-Object-Role-Formulatable
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Formulatable Role for Data::Object

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Data-Object-Class>=2.02:devel/p5-Data-Object-Class \
		p5-Data-Object-ClassHas>=2.01:devel/p5-Data-Object-ClassHas \
		p5-Data-Object-Role>=2.01:devel/p5-Data-Object-Role \
		p5-Data-Object-Role-Buildable>=0.03:devel/p5-Data-Object-Role-Buildable \
		p5-Data-Object-RoleHas>=2.01:devel/p5-Data-Object-RoleHas \
		p5-Data-Object-Space>=2.01:devel/p5-Data-Object-Space \
		p5-routines>=0:devel/p5-routines
TEST_DEPENDS=	p5-Test-Auto>=0.12:devel/p5-Test-Auto

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
