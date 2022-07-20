PORTNAME=	Hash-AutoHash-Args
PORTVERSION=	1.18
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Object-oriented processing of keyword-based argument lists

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Hash-AutoHash>=1.17:devel/p5-Hash-AutoHash
TEST_DEPENDS=	p5-Test-Deep>=0.110:devel/p5-Test-Deep \
		p5-Test-Pod>=1.48:devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

.include <bsd.port.mk>
