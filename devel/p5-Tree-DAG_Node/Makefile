PORTNAME=	Tree-DAG_Node
PORTVERSION=	1.35
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Super class for representing nodes in a tree
WWW=		https://metacpan.org/release/Tree-DAG_Node

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-Slurp-Tiny>=0.003:devel/p5-File-Slurp-Tiny
TEST_DEPENDS=	p5-File-Slurper>=0:devel/p5-File-Slurper

USES=		perl5 tar:tgz
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
