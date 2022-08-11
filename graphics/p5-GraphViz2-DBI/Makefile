PORTNAME=	GraphViz2-DBI
PORTVERSION=	2.52
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Visualize a database schema as a graph

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DBIx-Admin-TableInfo>=3.00:databases/p5-DBIx-Admin-TableInfo \
		p5-GraphViz2>=2.60:graphics/p5-GraphViz2 \
		p5-Moo>=2.001001:devel/p5-Moo
TEST_DEPENDS=	p5-DBD-SQLite>=1.66:databases/p5-DBD-SQLite

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
