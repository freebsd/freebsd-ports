PORTNAME=	Devel-EvalContext
PORTVERSION=	0.09
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Save lexicals and hints between calls to eval

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-PadWalker>=0:devel/p5-PadWalker \
		p5-Data-Alias>=0:devel/p5-Data-Alias \
		p5-YAML>=0:textproc/p5-YAML

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
