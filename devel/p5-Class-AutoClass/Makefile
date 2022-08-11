PORTNAME=	Class-AutoClass
PORTVERSION=	1.56
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Create get and set methods and simplify object initialization

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Hash-AutoHash>=1.17:devel/p5-Hash-AutoHash \
		p5-Hash-AutoHash-Args>=1.18:devel/p5-Hash-AutoHash-Args
TEST_DEPENDS=	p5-IO-Stringy>=2.1:devel/p5-IO-Stringy \
		p5-Test-Deep>=0.110:devel/p5-Test-Deep \
		p5-Test-Pod>=1.48:devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

.include <bsd.port.mk>
