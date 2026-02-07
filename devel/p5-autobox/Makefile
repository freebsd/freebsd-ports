PORTNAME=	autobox
PORTVERSION=	3.0.2
DISTVERSIONPREFIX=	v
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CHOCOLATE
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Call methods on native Perl types
WWW=		https://metacpan.org/release/autobox

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Scope-Guard>=0.20:devel/p5-Scope-Guard
TEST_DEPENDS=	p5-Test-Fatal>=0.017:devel/p5-Test-Fatal \
		p5-IPC-System-Simple>=1.30:devel/p5-IPC-System-Simple

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/autobox/autobox.so

.include <bsd.port.mk>
