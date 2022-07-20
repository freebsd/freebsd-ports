PORTNAME=	Module-Runtime-Conflicts
PORTVERSION=	0.003
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provide information on conflicts for Module::Runtime

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENCE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Dist-CheckConflicts>=0:devel/p5-Dist-CheckConflicts \
		p5-Module-Runtime>=0:devel/p5-Module-Runtime

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
