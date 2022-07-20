PORTNAME=	Devel-MAT
PORTVERSION=	0.47
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl Memory Analysis Tool

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Commandable>=0.04:devel/p5-Commandable \
		p5-Devel-MAT-Dumper>=0.35:devel/p5-Devel-MAT-Dumper \
		p5-Feature-Compat-Try>=0:devel/p5-Feature-Compat-Try \
		p5-File-ShareDir>=0:devel/p5-File-ShareDir \
		p5-Heap>=0:devel/p5-Heap \
		p5-List-UtilsBy>=0:devel/p5-List-UtilsBy \
		p5-Module-Pluggable>=0:devel/p5-Module-Pluggable \
		p5-String-Tagged>=0:textproc/p5-String-Tagged \
		p5-String-Tagged-Terminal>=0.03:textproc/p5-String-Tagged-Terminal \
		p5-Struct-Dumb>=0.07:devel/p5-Struct-Dumb \
		p5-Syntax-Keyword-Match>=0:devel/p5-Syntax-Keyword-Match
TEST_DEPENDS=	p5-Test-Identity>=0:devel/p5-Test-Identity \
		p5-Test-Pod>=1:devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	modbuild

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Devel/MAT/MAT.so

.include <bsd.port.mk>
