PORTNAME=	Future-XS
PORTVERSION=	0.15
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PEVANS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Experimental XS implementation of Future
WWW=		https://metacpan.org/release/Future-XS

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

TEST_DEPENDS=	p5-Future-AsyncAwait>=0:devel/p5-Future-AsyncAwait \
		p5-Test-Simple>=1.302200:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	modbuild

PORTSCOUT=	limit:^[0-9\.]*$$

.include <bsd.port.mk>
