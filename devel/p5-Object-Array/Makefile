PORTNAME=	Object-Array
PORTVERSION=	0.060
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Array references with accessors

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Sub-Exporter>=0:devel/p5-Sub-Exporter \
		p5-Sub-Install>=0:devel/p5-Sub-Install

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
