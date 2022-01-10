# Created by: Vladimir Timofeev <vovkasm@gmail.com>

PORTNAME=	Devel-NYTProf
DISTVERSION=	6.10
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vovkasm@gmail.com
COMMENT=	Powerful feature-rich Perl source code profiler

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-Which>=1.09:sysutils/p5-File-Which \
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS
TEST_DEPENDS=	p5-Capture-Tiny>=0:devel/p5-Capture-Tiny \
		p5-Test-Differences>=0.60:devel/p5-Test-Differences

USES=		perl5
USE_PERL5=	configure

CONFLICTS_INSTALL=	flamegraph

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Devel/NYTProf/NYTProf.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/Devel/auto/Devel/NYTProf/NYTProf.so

.include <bsd.port.mk>
