PORTNAME=	Color-Theme-Role
PORTVERSION=	0.020
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Role for class wanting to support color themes

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Color-ANSI-Util>=0.160:devel/p5-Color-ANSI-Util \
		p5-Module-List>=0:devel/p5-Module-List \
		p5-Moo>=0:devel/p5-Moo \
		p5-Term-App-Roles>=0:devel/p5-Term-App-Roles

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
