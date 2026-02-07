PORTNAME=	Params-CallbackRequest
PORTVERSION=	1.20
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provide callbacks to method and function parameters
WWW=		https://metacpan.org/release/Params-CallbackRequest

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Params-Validate>=0:devel/p5-Params-Validate \
		p5-Exception-Class>=0:devel/p5-Exception-Class \
		p5-Class-ISA>=0:devel/p5-Class-ISA

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

.include <bsd.port.mk>
