PORTNAME=	Data-TreeDumper
PORTVERSION=	0.41
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Dumps a data structure in a tree fashion
WWW=		https://metacpan.org/release/Data-TreeDumper

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Check-ISA>=0:devel/p5-Check-ISA \
		p5-Sort-Naturally>=0:textproc/p5-Sort-Naturally \
		p5-Term-Size>=0:devel/p5-Term-Size \
		p5-Text-Tabs+Wrap>=0:textproc/p5-Text-Tabs+Wrap

USES=		perl5 shebangfix
USE_PERL5=	configure

NO_ARCH=	yes

SHEBANG_FILES=	*.pl

.include <bsd.port.mk>
