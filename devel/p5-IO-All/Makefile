PORTNAME=	IO-All
PORTVERSION=	0.87
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	IO::All combines all of the best Perl IO modules

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-ReadBackwards>=0:devel/p5-File-ReadBackwards \
		p5-IO-String>=1.08:devel/p5-IO-String
TEST_DEPENDS=	p5-File-MimeInfo>=0:devel/p5-File-MimeInfo \
		p5-MLDBM>=0:databases/p5-MLDBM

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
