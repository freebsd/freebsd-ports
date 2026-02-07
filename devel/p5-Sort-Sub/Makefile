PORTNAME=	Sort-Sub
PORTVERSION=	0.121
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Collection of Perl sort subroutines
WWW=		https://metacpan.org/release/Sort-Sub

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-Complete-Sah>=0.012:devel/p5-Complete-Sah \
		p5-Complete-Sequence>=0.002:devel/p5-Complete-Sequence \
		p5-Complete-Util>=0.620:devel/p5-Complete-Util \
		p5-Log-ger>=0.038:devel/p5-Log-ger \
		p5-Sort-Naturally>=0:textproc/p5-Sort-Naturally

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
