PORTNAME=	DateTime-Format-Pg
PORTVERSION=	0.16014
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Parse and format PostgreSQL dates and times

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DateTime>=0.10:devel/p5-DateTime \
		p5-DateTime-Format-Builder>=0.72:devel/p5-DateTime-Format-Builder \
		p5-DateTime-TimeZone>=0.05:devel/p5-DateTime-TimeZone

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
