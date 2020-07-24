# $FreeBSD$

PORTNAME=	Devel-Cover
PORTVERSION=	1.36
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Code coverage metrics for Perl

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENCE

BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Differences>=0:devel/p5-Test-Differences

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	CPANCOVER HTML_REPORTS POD_COVERAGE SYNTAX_HIGHLIGHTING
OPTIONS_DEFAULT=CPANCOVER HTML_REPORTS POD_COVERAGE
OPTIONS_SUB=	yes

CPANCOVER_DESC=		Coverage statistics on CPAN modules
CPANCOVER_RUN_DEPENDS=	p5-Parallel-Iterator>=0:devel/p5-Parallel-Iterator \
			p5-Template-Toolkit>=2:www/p5-Template-Toolkit

HTML_REPORTS_DESC=	Build HTML reports with p5-HTML-Parser
HTML_REPORTS_RUN_DEPENDS=	p5-HTML-Parser>=0:www/p5-HTML-Parser

POD_COVERAGE_DESC=	POD coverage via p5-Pod-Coverage
POD_COVERAGE_RUN_DEPENDS=	p5-Pod-Coverage>=0.06:devel/p5-Pod-Coverage

SYNTAX_HIGHLIGHTING_DESC=	Syntax highlighting via p5-PPI-HTML
SYNTAX_HIGHLIGHTING_RUN_DEPENDS=p5-PPI-HTML>=1.07:textproc/p5-PPI-HTML

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Devel/Cover/Cover.so

.include <bsd.port.mk>
