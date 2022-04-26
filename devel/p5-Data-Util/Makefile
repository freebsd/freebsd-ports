PORTNAME=	Data-Util
PORTVERSION=	0.67
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for utilities for data and data types

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Module-Build-XSUtil>=0:devel/p5-Module-Build-XSUtil \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-Hash-Util-FieldHash-Compat>=0:devel/p5-Hash-Util-FieldHash-Compat
TEST_DEPENDS=	p5-Scope-Guard>=0:devel/p5-Scope-Guard \
		p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	modbuild

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Data/Util/Util.so

.include <bsd.port.mk>
