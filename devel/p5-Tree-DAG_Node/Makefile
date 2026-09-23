PORTNAME=	Tree-DAG_Node
DISTVERSION=	1.36
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RSAVAGE
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Super class for representing nodes in a tree
WWW=		https://metacpan.org/release/Tree-DAG_Node

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/LICENSE

BUILD_RUN_DEPENDS=	p5-File-Slurp-Tiny>=0.003:devel/p5-File-Slurp-Tiny
TEST_DEPENDS=	p5-File-Slurper>=0:devel/p5-File-Slurper

USES=		perl5 tar:tgz
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
