PORTNAME=	Bio-FeatureIO
PORTVERSION=	1.6.905
CATEGORIES=	biology perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Handler for FeatureIO

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-BioPerl>=0:biology/p5-BioPerl \
		p5-Tree-DAG_Node>=0:devel/p5-Tree-DAG_Node \
		p5-URI>=0:net/p5-URI \
		p5-XML-DOM>=0:textproc/p5-XML-DOM \
		p5-XML-DOM-XPath>=0:textproc/p5-XML-DOM-XPath

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
