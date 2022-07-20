PORTNAME=	Config-Parser
PORTVERSION=	1.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Base class for configuration file parsers

LICENSE=	GPLv3+

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Config-AST>=1.05:devel/p5-Config-AST \
		p5-Text-Locus>=1.01:textproc/p5-Text-Locus

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
