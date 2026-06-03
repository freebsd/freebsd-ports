PORTNAME=	Sub-HandlesVia-XS
PORTVERSION=	0.003004
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOBYINK
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	XS parts for Sub::HandlesVia; no user-serviceable parts inside
WWW=		https://metacpan.org/dist/Sub-HandlesVia-XS

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Type-Tiny>=2.010001:devel/p5-Type-Tiny
TEST_DEPENDS=	p5-Test-Simple>=1.302200:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Sub/HandlesVia/XS/XS.so

.include <bsd.port.mk>
