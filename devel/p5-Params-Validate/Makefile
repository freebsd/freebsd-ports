# Created by: Denis Shaposhnikov <dsh@vlink.ru>
# $FreeBSD$

PORTNAME=	Params-Validate
PORTVERSION=	1.26
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Validate method/function parameters

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Module-Implementation>=0.04:devel/p5-Module-Implementation
RUN_DEPENDS=	p5-Module-Implementation>=0.04:devel/p5-Module-Implementation
TEST_DEPENDS=	p5-Readonly>=0:devel/p5-Readonly \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Requires>0:devel/p5-Test-Requires \
		p5-Test-Taint>=0.02:devel/p5-Test-Taint

USES=		perl5
USE_PERL5=	modbuild

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Params/Validate/XS/XS.so

.include <bsd.port.mk>
