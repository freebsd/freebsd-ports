PORTNAME=	Data-TreeDumper
PORTVERSION=	0.40
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Dumps a data structure in a tree fashion

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Check-ISA>=0:devel/p5-Check-ISA \
		p5-Devel-Size>=0:devel/p5-Devel-Size \
		p5-Sort-Naturally>=0:textproc/p5-Sort-Naturally \
		p5-Term-Size>=0:devel/p5-Term-Size \
		p5-Text-Tabs+Wrap>=0:textproc/p5-Text-Tabs+Wrap

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
