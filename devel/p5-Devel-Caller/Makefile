PORTNAME=	Devel-Caller
PORTVERSION=	2.07
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module which is meatier versions of caller
WWW=		https://metacpan.org/release/Devel-Caller

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-PadWalker>=0.08:devel/p5-PadWalker

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Devel/Caller/Caller.so

.include <bsd.port.mk>
