PORTNAME=	MooX-Traits
PORTVERSION=	0.005
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOBYINK
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Automatically apply roles at object creation time

LICENSE=	ARTPERL10

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Exporter-Tiny>0:devel/p5-Exporter-Tiny \
		p5-Module-Runtime>0:devel/p5-Module-Runtime \
		p5-Moo>0:devel/p5-Moo \
		p5-Role-Tiny>0:devel/p5-Role-Tiny

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
