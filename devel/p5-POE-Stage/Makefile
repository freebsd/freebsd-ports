PORTNAME=	POE-Stage
PORTVERSION=	0.0600
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
DISTNAME=	${PORTNAME}-${PORTVERSION:S/0$//}
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Base class for formalized POE components

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-POE>=1.351:devel/p5-POE \
		p5-PadWalker>=1.93:devel/p5-PadWalker \
		p5-Net-DNS>=0.68:dns/p5-Net-DNS \
		p5-Devel-LexAlias>=0.04:devel/p5-Devel-LexAlias \
		p5-Lexical-Persistence>=1.020:devel/p5-Lexical-Persistence \
		p5-Attribute-Handlers>=0.93:devel/p5-Attribute-Handlers

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
