PORTNAME=	DateTime-Format-Oracle
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Parse and format Oracle dates and timestamps

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Convert-NLS_DATE_FORMAT>=0.03:converters/p5-Convert-NLS_DATE_FORMAT \
		p5-DateTime>=0:devel/p5-DateTime \
		p5-DateTime-Format-Builder>=0:devel/p5-DateTime-Format-Builder

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
