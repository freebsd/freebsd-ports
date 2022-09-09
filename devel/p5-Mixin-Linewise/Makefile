PORTNAME=	Mixin-Linewise
PORTVERSION=	0.110
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RJBS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Write your linewise code for handles; this does the rest
WWW=		https://metacpan.org/release/Mixin-Linewise

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-PerlIO-utf8_strict>=0:devel/p5-PerlIO-utf8_strict \
		p5-Sub-Exporter>=0.900:devel/p5-Sub-Exporter

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
