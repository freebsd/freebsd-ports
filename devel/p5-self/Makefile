PORTNAME=	self
PORTVERSION=	0.36
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GUGOD
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provides "self" and "args" keywords in your OO program

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-B-Hooks-Parser>=0.21:devel/p5-B-Hooks-Parser \
		p5-B-OPCheck>=0.27:devel/p5-B-OPCheck \
		p5-PadWalker>=1.93:devel/p5-PadWalker \
		p5-Sub-Exporter>=0:devel/p5-Sub-Exporter

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
