PORTNAME=	Data-Page-NoTotalEntries
PORTVERSION=	0.02
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOKUHIROM
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for paging results without total entries
WWW=		https://metacpan.org/release/Data-Page-NoTotalEntries

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	\
	p5-Class-Accessor-Lite>=0.05:devel/p5-Class-Accessor-Lite
TEST_DEPENDS=	p5-Test-Simple>=0.96:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
