PORTNAME=	Carp-REPL
PORTVERSION=	0.18
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ETHER
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Read-Eval-Print-Loop on die and/or warn

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Data-Dump-Streamer>=0:devel/p5-Data-Dump-Streamer \
		p5-Devel-LexAlias>=0:devel/p5-Devel-LexAlias \
		p5-Devel-REPL>=0:devel/p5-Devel-REPL \
		p5-Devel-StackTrace-WithLexicals>=0:devel/p5-Devel-StackTrace-WithLexicals \
		p5-Lexical-Persistence>=0:devel/p5-Lexical-Persistence \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
TEST_DEPENDS=	p5-Test-Expect>=0:devel/p5-Test-Expect

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
