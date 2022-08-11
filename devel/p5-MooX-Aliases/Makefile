PORTNAME=	MooX-Aliases
PORTVERSION=	0.001006
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:HAARG
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easy aliasing of methods and attributes in Moo

LICENSE=	ARTPERL10

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Moo>0:devel/p5-Moo \
		p5-Class-Method-Modifiers>0:devel/p5-Class-Method-Modifiers \
		p5-strictures>0:devel/p5-strictures

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
