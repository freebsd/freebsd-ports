PORTNAME=	MooseX-InsideOut
PORTVERSION=	0.106
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Inside-out objects with Moose

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Hash-Util-FieldHash-Compat>=0:devel/p5-Hash-Util-FieldHash-Compat \
		p5-Moose>=2:devel/p5-Moose \
		p5-namespace-clean>=0.11:devel/p5-namespace-clean

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
