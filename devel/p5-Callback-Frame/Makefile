PORTNAME=	Callback-Frame
DISTVERSION=	1.102
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bill.brinzer@gmail.com
COMMENT=	Preserve error handlers and "local" variables across callbacks
WWW=		https://metacpan.org/release/Callback-Frame

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Guard>=0:devel/p5-Guard

NO_ARCH=	yes

USES=	perl5
USE_PERL5=	configure

.include <bsd.port.mk>
