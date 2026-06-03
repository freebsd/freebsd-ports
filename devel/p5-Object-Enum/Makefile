PORTNAME=	Object-Enum
DISTVERSION=	0.075
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Replacement for if ($$foo eq 'bar')
WWW=		https://metacpan.org/release/Object-Enum

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Sub-Install>=0:devel/p5-Sub-Install \
		p5-Sub-Exporter>=0:devel/p5-Sub-Exporter \
		p5-Class-Data-Inheritable>=0:devel/p5-Class-Data-Inheritable \
		p5-Class-Accessor>=0:devel/p5-Class-Accessor

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
